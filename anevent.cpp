#include "anevent.hpp"

namespace sdl
{
	AnEvent::AnEvent()
	{}

	AnEvent::AnEvent(SDLKey key)
	{
		m_pressed.push_back(key);
	}

	AnEvent::AnEvent(std::vector<SDLKey> keys)
		:m_pressed(keys)
	{}

	AnEvent::AnEvent(std::vector<SDLKey> keys, std::vector<SDLKey> forbidden)
		:m_pressed(keys), m_released(forbidden)
	{
	}

	AnEvent::AnEvent(const AnEvent& cp)
	{
		this->operator=(cp);
	}

	AnEvent::AnEvent(const std::string& keys, const std::string& forb)
	{
		addKeys(keys);
		addForbid(forb);
	}

	AnEvent& AnEvent::operator=(const AnEvent& cp)
	{
		m_pressed=cp.m_pressed;
		m_released=cp.m_released;

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

	void AnEvent::clear()
	{
		m_pressed.clear();
		m_released.clear();
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

};

