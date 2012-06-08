#include "event.hpp"

namespace sdl
{
	Event::Event()
	{
		PressEvent press;
		press.state=false;
		press.lastPress=press.lastRelease=0;
		m_keys.assign(press);

		m_posMouse.x=m_posMouse.y=m_posMouse.w=m_posMouse.h=0;
		m_relMouse.x=m_relMouse.y=m_relMouse.w=m_relMouse.h=0;
		m_buttons.assign(press);

		m_sizeWindow.x=m_sizeWindow.y=0;
		SDL_Surface* ecran=SDL_GetVideoSurface();
		m_sizeWindow.w=ecran->w;
		m_sizeWindow.h=ecran->h;

		m_mouseFocus=true;
		m_inputFocus=true;
		m_iconify=false;

		m_quit=false;
	}

	Event::Event(const Event& cp)
	{
		this->operator=(cp);
	}

	Event& Event::operator=(const Event& cp)
	{
		m_keys=cp.m_keys;
		m_posMouse=cp.m_posMouse;
		m_relMouse=cp.m_relMouse;
		m_buttons=cp.m_buttons;
		m_quit=cp.m_quit;

		m_sizeWindow=cp.m_sizeWindow;
		m_mouseFocus=cp.m_mouseFocus;
		m_inputFocus=cp.m_inputFocus;
		m_iconify=cp.m_iconify;

		m_persEvents=cp.m_persEvents;

		m_onPressedKey=cp.m_onPressedKey;
		m_onReleaseKey=cp.m_onReleaseKey;
		m_onMouseMoved=cp.m_onMouseMoved;
		m_onPressedButton=cp.m_onPressedButton;
		m_onReleaseButton=cp.m_onReleaseButton;

		m_onResizeWindow=cp.m_onResizeWindow;
		m_onGetMouseFocus=cp.m_onGetMouseFocus;
		m_onLoseMouseFocus=cp.m_onLoseMouseFocus;
		m_onGetInputFocus=cp.m_onGetInputFocus;
		m_onLoseInputFocus=cp.m_onLoseInputFocus;
		m_onActive=cp.m_onActive;
		m_onIconify=cp.m_onIconify;

		return *this;
	}

	void Event::update()
	{
		SDL_Event* event=new SDL_Event;
		m_quit=false;

		while(SDL_PollEvent(event))
			this->updateFrom(event);

		this->testPEvents();
	}

	void Event::updateFrom(SDL_Event* event)
	{
		switch(event->type)
		{
			case SDL_QUIT:
				m_quit=true;
				break;
			case SDL_KEYDOWN:
				m_keys.at(event->key.keysym.sym).state=true;
				m_keys.at(event->key.keysym.sym).lastPress=SDL_GetTicks();
				if(m_onPressedKey)
					m_onPressedKey(&event->key.keysym);
				if(isQuitKey(event->key.keysym.sym))
					m_quit=true;
				break;
			case SDL_KEYUP:
				m_keys.at(event->key.keysym.sym).state=false;
				m_keys.at(event->key.keysym.sym).lastRelease=SDL_GetTicks();
				if(m_onReleaseKey)
					m_onReleaseKey(&event->key.keysym);
				break;
			case SDL_MOUSEMOTION:
				m_posMouse.x=event->motion.x;
				m_posMouse.y=event->motion.y;
				m_relMouse.x=event->motion.xrel;
				m_relMouse.y=event->motion.yrel;
				if(m_onMouseMoved)
					m_onMouseMoved(m_posMouse, m_relMouse);
				break;
			case SDL_MOUSEBUTTONDOWN:
				m_buttons.at(event->button.button).state=true;
				m_buttons.at(event->key.keysym.sym).lastPress=SDL_GetTicks();
				if(m_onPressedButton)
				{
					SDL_Rect pos;
					pos.w=pos.h=0;
					pos.x=event->button.x;
					pos.y=event->button.y;
					m_onPressedButton(event->button.button, pos);
				}
				break;
			case SDL_MOUSEBUTTONUP:
				m_buttons.at(event->button.button).state=false;
				m_buttons.at(event->key.keysym.sym).lastRelease=SDL_GetTicks();
				if(m_onReleaseButton)
				{
					SDL_Rect pos;
					pos.w=pos.h=0;
					pos.x=event->button.x;
					pos.y=event->button.y;
					m_onReleaseButton(event->button.button, pos);
				}
				break;
			case SDL_VIDEORESIZE:
				m_sizeWindow.w=event->resize.w;
				m_sizeWindow.h=event->resize.h;
				if(m_onResizeWindow)
					m_onResizeWindow(m_sizeWindow);
				break;
			case SDL_ACTIVEEVENT:
				if((event->active.state & SDL_APPMOUSEFOCUS) == SDL_APPMOUSEFOCUS)
				{
					if(event->active.gain == 1)
					{
						m_mouseFocus=true;
						if(m_onGetMouseFocus)
							m_onGetMouseFocus();
					}
					else
					{
						m_mouseFocus=false;
						if(m_onLoseMouseFocus)
							m_onLoseMouseFocus();
					}
				}
				if((event->active.state & SDL_APPINPUTFOCUS) == SDL_APPINPUTFOCUS)
				{
					if(event->active.gain == 1)
					{
						m_inputFocus=true;
						if(m_onGetInputFocus)
							m_onGetInputFocus();
					}
					else
					{
						m_inputFocus=false;
						if(m_onLoseInputFocus)
							m_onLoseInputFocus();
					}
				}
				if((event->active.state & SDL_APPACTIVE) == SDL_APPACTIVE)
				{
					if(event->active.gain == 1)
					{
						m_iconify=false;
						if(m_onActive)
							m_onActive();
					}
					else
					{
						m_iconify=true;
						if(m_onIconify)
							m_onIconify();
					}
				}
				break;
			default:
				break;
		}
	}

	bool Event::isKeyPressed(unsigned int key) const
	{
		return m_keys.at(key).state;
	}

	bool Event::operator[](unsigned int key) const
	{
		return m_keys.at(key).state;
	}

	Uint32 Event::timeKeyPressed(unsigned int key) const
	{
		PressEvent ev=m_keys.at(key);

		if(!ev.state)
			return 0;
		else
			return SDL_GetTicks()-ev.lastPress;
	}

	Uint32 Event::lastKeyPress(unsigned int key) const
	{
		return m_keys.at(key).lastPress;
	}

	Uint32 Event::lastKeyRelease(unsigned int key) const
	{
		return m_keys.at(key).lastRelease;
	}

	bool Event::isButtonPressed(unsigned int button) const
	{
		return m_buttons.at(button).state;
	}

	Uint32 Event::timeButtonPressed(Uint8 button) const
	{
		PressEvent ev=m_buttons.at(button);
		if(!ev.state)
			return 0;
		else
			return SDL_GetTicks()-ev.lastPress;
	}

	Uint32 Event::lastButtonPress(Uint8 button) const
	{
		return m_buttons.at(button).lastPress;
	}

	Uint32 Event::lastButtonRelease(Uint8 button) const
	{
		return m_buttons.at(button).lastRelease;
	}


	SDL_Rect Event::posMouse() const
	{
		return m_posMouse;
	}

	SDL_Rect Event::relMouse() const
	{
		return m_relMouse;
	}

	SDL_Rect Event::windowsize() const
	{
		return m_sizeWindow;
	}

	bool Event::hasMouseFocus() const
	{
		return m_mouseFocus;
	}

	bool Event::hasInputFocus() const
	{
		return m_inputFocus;
	}

	bool Event::isIconify() const
	{
		return m_iconify;
	}


	bool Event::quit() const
	{
		return m_quit;
	}

	bool Event::alt() const
	{
		if((SDL_GetModState() & KMOD_ALT) == KMOD_ALT)
			return true;
		else
			return false;
	}

	bool Event::ctrl() const
	{
		if((SDL_GetModState() & KMOD_CTRL) == KMOD_CTRL)
			return true;
		else
			return false;
	}

	bool Event::shift() const
	{
		if((SDL_GetModState() & KMOD_SHIFT) == KMOD_SHIFT)
			return true;
		else
			return false;
	}

	bool Event::super() const
	{
		if(isKeyPressed(SDLK_LSUPER) || isKeyPressed(SDLK_RSUPER))
			return true;
		else
			return false;
	}

	bool Event::num() const
	{
		if((SDL_GetModState() & KMOD_NUM) == KMOD_NUM)
			return true;
		else
			return false;
	}

	bool Event::caps() const
	{
		if((SDL_GetModState() & KMOD_CAPS) == KMOD_CAPS)
			return true;
		else
			return false;
	}

	void Event::setOnPressedKeyCallback(boost::function<void (SDL_keysym*)> func)
	{
		m_onPressedKey=func;
	}

	bool Event::isOnPressedKeyCallback() const
	{
		return !m_onPressedKey.empty();
	}

	void Event::clearOnPressedKeyCallback()
	{
		m_onPressedKey.clear();
	}

	void Event::setOnReleaseKeyCallback(boost::function<void (SDL_keysym*)> func)
	{
		m_onReleaseKey=func;
	}

	bool Event::isOnReleaseKeyCallback() const
	{
		return !m_onReleaseKey.empty();
	}

	void Event::clearOnReleaseKeyCallback()
	{
		m_onReleaseKey.clear();
	}


	void Event::setOnMouseMovedCallback(boost::function<void (SDL_Rect, SDL_Rect)> func)
	{
		m_onMouseMoved=func;
	}

	bool Event::isOnMouseMovedCallback() const
	{
		return !m_onMouseMoved.empty();
	}

	void Event::clearMouseMovedCallback()
	{
		m_onMouseMoved.clear();
	}


	void Event::setOnPressedButtonCallback(boost::function<void (Uint8, SDL_Rect)> func)
	{
		m_onPressedButton=func;
	}

	bool Event::isOnPressedButtonCallback() const
	{
		return !m_onPressedButton.empty();
	}

	void Event::clearOnPressedButtonCallback()
	{
		m_onPressedButton.clear();
	}

	void Event::setOnReleaseButtonCallback(boost::function<void (Uint8, SDL_Rect)> func)
	{
		m_onReleaseButton=func;
	}

	bool Event::isOnReleaseButtonCallback() const
	{
		return !m_onReleaseButton.empty();
	}

	void Event::clearOnReleaseButtonCallback()
	{
		m_onReleaseButton.clear();
	}

	void Event::setOnResizeWindowCallback(boost::function<void (SDL_Rect)> func)
	{
		m_onResizeWindow=func;
	}

	bool Event::isOnResizeWindowCallBack() const
	{
		return !m_onResizeWindow.empty();
	}

	void Event::clearOnResizeWindowCallback()
	{
		m_onResizeWindow.clear();
	}

	void Event::setOnGetMouseFocusCallback(boost::function<void ()> func)
	{
		m_onGetMouseFocus=func;
	}

	bool Event::isOnGetMouseFocusCallback() const
	{
		return !m_onGetMouseFocus.empty();
	}

	void Event::clearOnGetMouseFocusCallback()
	{
		m_onGetMouseFocus.clear();
	}

	void Event::setOnLoseMouseFocusCallback(boost::function<void ()> func)
	{
		m_onLoseMouseFocus=func;
	}

	bool Event::isOnLoseMouseFocusCallback() const
	{
		return !m_onLoseMouseFocus.empty();
	}

	void Event::clearOnLoseMouseFocusCallback()
	{
		m_onLoseMouseFocus.clear();
	}

	void Event::setOnGetInputFocusCallback(boost::function<void ()> func)
	{
		m_onGetInputFocus=func;
	}

	bool Event::isOnGetInputFocusCallback() const
	{
		return !m_onGetInputFocus.empty();
	}

	void Event::clearOnGetInputFocusCallback()
	{
		m_onGetInputFocus.clear();
	}

	void Event::setOnLoseInputFocusCallback(boost::function<void ()> func)
	{
		m_onLoseInputFocus=func;
	}

	bool Event::isOnLoseInputFocusCallback() const
	{
		return !m_onLoseInputFocus.empty();
	}

	void Event::clearOnLoseInputFocusCallback()
	{
		m_onLoseInputFocus.clear();
	}

	void Event::setOnIconifyCallback(boost::function<void ()> func)
	{
		m_onIconify=func;
	}

	bool Event::isOnIconifyCallback() const
	{
		return !m_onIconify.empty();
	}

	void Event::clearOnIconifyCallback()
	{
		m_onIconify.clear();
	}

	void Event::setOnActiveCallback(boost::function<void ()> func)
	{
		m_onActive=func;
	}

	bool Event::isOnActiveCallback() const
	{
		return !m_onActive.empty();
	}

	void Event::clearOnActiveCallback()
	{
		m_onActive.clear();
	}

	void Event::addQuitKey(SDLKey key)
	{
		if(!isQuitKey(key))
			m_quitKeys.push_back(key);
	}

	void Event::addQuitKeys(std::vector<SDLKey> keys)
	{
		for(std::vector<SDLKey>::iterator it=keys.begin(); it!=keys.end(); ++it)
			addQuitKey(*it);
	}

	void Event::setQuitKeys(std::vector<SDLKey> keys)
	{
		clearQuitKeys();
		addQuitKeys(keys);
	}

	void Event::clearQuitKeys()
	{
		m_quitKeys.clear();
	}

	std::vector<SDLKey> Event::getQuitKeys() const
	{
		return m_quitKeys;
	}

	bool Event::isQuitKey(SDLKey key) const
	{
		for(std::vector<SDLKey>::const_iterator it=m_quitKeys.begin(); it!=m_quitKeys.end(); ++it)
			if(*it == key)
				return true;
		return false;
	}

	bool Event::addPEvent(std::string name, AnEvent* ev, boost::function<void ()> callback, boost::optional<boost::function<void ()>> onquit, Uint32 time, Uint32 repeat)
	{
		if(existPEvent(name))
			return false;

		Event::PersEvent PE;
		PE.event=ev;
		PE.callback=callback;
		if(onquit)
			PE.quitCallback=*onquit;
		PE.firstTime=time;
		PE.repeat=repeat;
		PE.launched=false;
		PE.lastLaunched=0;
		m_persEvents[name]=PE;

		return true;
	}

	bool Event::changePEventCallback(std::string name, boost::function<void ()> callback)
	{
		if(!existPEvent(name))
			return false;

		m_persEvents[name].callback=callback;
		return true;
	}

	bool Event::clearPEventCallback(std::string name)
	{
		if(!existPEvent(name))
			return false;

		m_persEvents[name].callback.clear();
		return true;
	}

	bool Event::changePEventQuitCallback(std::string name, boost::function<void ()> callback)
	{
		if(!existPEvent(name))
			return false;

		m_persEvents[name].quitCallback=callback;
		return true;
	}

	bool Event::clearPEventQuitCallback(std::string name)
	{
		if(!existPEvent(name))
			return false;

		m_persEvents[name].quitCallback.clear();
		return true;
	}

	bool Event::changePEventTime(std::string name, Uint32 time, boost::optional<Uint32> repeat)
	{
		if(!existPEvent(name))
			return false;

		m_persEvents[name].firstTime=time;
		if(repeat)
			m_persEvents[name].repeat=*repeat;

		return true;
	}

	bool Event::changePEventName(std::string name, std::string nname)
	{
		if(!existPEvent(name)
				|| existPEvent(nname))
			return false;

		m_persEvents[nname]=m_persEvents[name];
		deletePEvent(name);

		return true;
	}

	bool Event::deletePEvent(std::string name)
	{
		if(!existPEvent(name))
			return false;

		m_persEvents.erase(name);
		return true;
	}

	bool Event::existPEvent(std::string name) const
	{
		if(m_persEvents.find(name) != m_persEvents.end())
			return true;
		else
			return false;
	}

	void Event::testPEvents()
	{
		for(std::map<std::string,PersEvent>::iterator it=m_persEvents.begin(); it!=m_persEvents.end(); ++it)
			testPEvent(it->first);
	}

	void Event::testPEvent(std::string name)
	{
		if(!existPEvent(name))
			return;

		PersEvent* ev = &m_persEvents[name];
		Uint32 curTime = SDL_GetTicks();

		Uint32 timeToCheck;
		if(ev->launched)
		{
			if(ev->repeat > 0)
				timeToCheck = ev->repeat;
			else
				timeToCheck = std::numeric_limits<Uint32>::max();
		}
		else
			timeToCheck=ev->firstTime;

		bool toLaunch=true;
		bool pause=false;

		for(AnEvent::ckey_iterator it = ev->event->keybegin(); it!=ev->event->keyend() && toLaunch; ++it)
		{
			if( !m_keys.at(*it).state )
				toLaunch=false;
			else if( ev->launched 
					&& timeToCheck > (curTime - ev->lastLaunched) )
			{
				pause=true;
				toLaunch=false;
			}
			else if( !ev->launched
					&& timeToCheck > (curTime - m_keys.at(*it).lastPress) )
				toLaunch=false;
		}

		if(!toLaunch)
		{
			if(!pause)
			{
				if(ev->launched
						&& ev->quitCallback )
					ev->quitCallback();
				ev->launched=false;
				ev->lastLaunched=0;
			}
			return;
		}

		for(AnEvent::ckey_iterator it = ev->event->forbidbegin(); it!=ev->event->forbidend() && toLaunch; ++it)
		{
			if( m_keys.at(*it).state )
				toLaunch=false;
			else if( ev->launched
					&& timeToCheck > (curTime - ev->lastLaunched) )
			{
				pause=true;
				toLaunch=false;
			}
			else if( !ev->launched
					&& timeToCheck > (curTime - m_keys.at(*it).lastPress) )
				toLaunch=false;
		}

		if(!toLaunch)
		{
			if(!pause)
			{
				if(ev->launched
						&& ev->quitCallback )
					ev->quitCallback();
				ev->launched=false;
				ev->lastLaunched=0;
			}
			return;
		}

		ev->launched=true;
		ev->lastLaunched=SDL_GetTicks();
		if(ev->callback)
			ev->callback();
	}

};

