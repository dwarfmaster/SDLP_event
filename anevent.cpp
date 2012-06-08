#include "anevent.hpp"

namespace sdl
{
	AnEvent::AnEvent()
		:m_usePlace(false)
	{}

	AnEvent::AnEvent(SDLKey key)
		:m_usePlace(false)
	{
		m_pressed.push_back(key);
	}

	AnEvent::AnEvent(std::vector<SDLKey> keys)
		:m_pressed(keys), m_usePlace(false)
	{}

	AnEvent::AnEvent(std::vector<SDLKey> keys, std::vector<SDLKey> forbidden)
		:m_pressed(keys), m_released(forbidden), m_usePlace(false)
	{
	}

	AnEvent::AnEvent(const AnEvent& cp)
		:m_usePlace(false)
	{
		this->operator=(cp);
	}

	AnEvent::AnEvent(const std::string& keys, const std::string& forb)
		:m_usePlace(false)
	{
		addKeys(keys);
		addForbid(forb);
	}

	AnEvent& AnEvent::operator=(const AnEvent& cp)
	{
		m_pressed = cp.m_pressed;
		m_released = cp.m_released;
		m_buttonp = cp.m_buttonp;
		m_buttonr = cp.m_buttonr;

		m_usePlace = cp.m_usePlace;
		m_place = cp.m_place;

		return *this;
	}

	bool AnEvent::isNeed(SDLKey key) const
	{
		for(size_t i=0; i<m_pressed.size(); ++i)
			if(key == m_pressed[i])
				return true;
		return false;
	}

	bool AnEvent::isForbidden(SDLKey key) const
	{
		for(size_t i=0; i<m_released.size(); ++i)
			if(key == m_released[i])
				return true;
		return false;
	}

	bool AnEvent::isMustPressed(Uint8 button) const
	{
		for(size_t i=0; i<m_buttonp.size(); ++i)
			if(button == m_buttonp[i])
				return true;
		return false;
	}

	bool AnEvent::isMustReleased(Uint8 button) const
	{
		for(size_t i=0; i<m_buttonr.size(); ++i)
			if(button == m_buttonr[i])
				return true;
		return false;
	}

	AnEvent::ckey_iterator AnEvent::keybegin() const
	{
		return m_pressed.begin();
	}

	AnEvent::ckey_iterator AnEvent::keyend() const
	{
		return m_pressed.end();
	}

	AnEvent::ckey_iterator AnEvent::forbidbegin() const
	{
		return m_released.begin();
	}

	AnEvent::ckey_iterator AnEvent::forbidend() const
	{
		return m_released.end();
	}

	AnEvent::cbutton_iterator AnEvent::buttonbegin() const
	{
		return m_buttonp.begin();
	}

	AnEvent::cbutton_iterator AnEvent::buttonend() const
	{
		return m_buttonp.end();
	}

	AnEvent::cbutton_iterator AnEvent::buttonrbegin() const
	{
		return m_buttonr.begin();
	}

	AnEvent::cbutton_iterator AnEvent::buttonrend() const
	{
		return m_buttonr.end();
	}

	bool AnEvent::addKey(SDLKey key)
	{
		if( (!isNeed(key)) && (!isForbidden(key)) )
		{
			m_pressed.push_back(key);
			return true;
		}
		return false;
	}

	int AnEvent::addKeys(std::vector<SDLKey> keys)
	{
		int nb=0;
		for(size_t i=0; i<keys.size(); ++i)
			if(addKey(keys[i]))
				++nb;
		return nb;
	}

	bool AnEvent::addForbid(SDLKey key)
	{
		if( (!isNeed(key)) && (!isForbidden(key)) )
		{
			m_released.push_back(key);
			return true;
		}
		return false;
	}

	int AnEvent::addForbids(std::vector<SDLKey> keys)
	{
		int nb=0;
		for(size_t i=0; i<keys.size(); ++i)
			if(addForbid(keys[i]))
				++nb;
		return nb;
	}

	bool AnEvent::addButton(Uint8 button)
	{
		if( (!isMustPressed(button)) && (!isMustReleased(button)) )
		{
			m_buttonp.push_back(button);
			return true;
		}
		return false;
	}

	int AnEvent::addButtons(std::vector<Uint8> buttons)
	{
		int nb=0;
		for(size_t i=0; i<buttons.size(); ++i)
			if(addButton(buttons[i]))
				++nb;
		return nb;
	}

	bool AnEvent::addReleased(Uint8 button)
	{
		if( (!isMustPressed(button)) && (!isMustReleased(button)) )
		{
			m_buttonr.push_back(button);
			return true;
		}
		return false;
	}

	int AnEvent::addReleased(std::vector<Uint8> buttons)
	{
		int nb=0;
		for(size_t i=0; i<buttons.size(); ++i)
			if(addReleased(buttons[i]))
				++nb;
		return nb;
	}

	void AnEvent::clear()
	{
		m_pressed.clear();
		m_released.clear();
		m_buttonp.clear();
		m_buttonr.clear();

		m_usePlace=false;
	}

	bool AnEvent::addKeys(std::string keys)
	{
		std::vector<std::string> strs(parseStr(keys));
		if(strs.empty())
			return false;

		for(std::vector<std::string>::iterator it=strs.begin(); it!=strs.end(); ++it)
		{
			std::vector<SDLKey> k=aKey(*it);
			if(k.empty())
				return false;

			for(std::vector<SDLKey>::iterator it2=k.begin(); it2!=k.end(); ++it2)
				m_pressed.push_back(*it2);
		}

		return true;
	}

	bool AnEvent::addForbid(std::string keys)
	{
		std::vector<std::string> strs(parseStr(keys));
		if(strs.empty())
			return false;

		for(std::vector<std::string>::iterator it=strs.begin(); it!=strs.end(); ++it)
		{
			std::vector<SDLKey> k=aKey(*it);
			if(k.empty())
				return false;

			for(std::vector<SDLKey>::iterator it2=k.begin(); it2!=k.end(); ++it2)
				m_released.push_back(*it2);
		}

		return true;
	}

	std::vector<SDLKey> AnEvent::aKey(std::string str) const
	{
		std::vector<SDLKey> keys;

		if(str.size() <= 0)
			return keys;

		bool error=false;

		switch(str[0])
		{
			case 'C': // ctrl
				if(str.size() > 1)
					error=true;
				else
				{
					keys.push_back(SDLK_LCTRL);
					keys.push_back(SDLK_RCTRL);
				}
				break;
			case 'A': // alt
				if(str.size() > 1)
					error=true;
				else
				{
					keys.push_back(SDLK_LALT);
					keys.push_back(SDLK_RALT);
				}
				break;
			case 'S': // shift
				if(str.size() > 1)
					error=true;
				else
				{
					keys.push_back(SDLK_LSHIFT);
					keys.push_back(SDLK_RSHIFT);
				}
				break;
			case 'W': // super
				if(str.size() > 1)
					error=true;
				else
				{
					keys.push_back(SDLK_LSUPER);
					keys.push_back(SDLK_RSUPER);
				}
				break;
			default: // autres
				if(str[0] >= 'a'
						&& str[0] <= 'z')
					keys.push_back( static_cast<SDLKey>(str[0]) );
				else
					error=true;
				break;
		}

		if(error)
			keys.clear();
		return keys;
	}

	std::vector<std::string> AnEvent::parseStr(std::string str) const
	{
		std::vector<std::string> keys;
		size_t pos=str.find_first_of('-');

		while(pos != std::string::npos)
		{
			keys.push_back(str.substr(0,pos));
			str=str.substr(pos+1);
			pos=str.find_first_of('-');
		}

		keys.push_back(str);

		return keys;
	}

	void AnEvent::setPlace(const SDL_Rect& place)
	{
		m_usePlace = true;
		m_place = place;
	}

	void AnEvent::unsetPlace()
	{
		m_usePlace = false;
	}

	boost::optional<SDL_Rect> AnEvent::getPlace() const
	{
		if(m_usePlace)
			return m_place;
		else
			return boost::none;
	}
};

