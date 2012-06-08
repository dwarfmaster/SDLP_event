#ifndef DEF_SDL_ANEVENT
#define DEF_SDL_ANEVENT

#include <vector>
#include <string>
#include <SDL/SDL.h>

namespace sdl
{
	class AnEvent
	{
		public:
			typedef std::vector<SDLKey>::const_iterator ckey_iterator;
			typedef std::vector<Uint8>::const_iterator cbutton_iterator;

			AnEvent();
			AnEvent(SDLKey key);
			AnEvent(std::vector<SDLKey> keys);
			AnEvent(std::vector<SDLKey> keys, std::vector<SDLKey> forbidden);
			AnEvent(const std::string& keys, const std::string& forb="");
			AnEvent(const AnEvent& cp);
			AnEvent& operator=(const AnEvent& cp);

			bool isNeed(SDLKey key) const;
			bool isForbidden(SDLKey key) const;
			bool isMustPressed(Uint8 button) const;
			bool isMustRelease(Uint8 button) const;

			ckey_iterator keybegin() const;
			ckey_iterator keyend() const;
			ckey_iterator forbidbegin() const;
			ckey_iterator forbidend() const;

			cbutton_iterator buttonbegin() const;
			cbutton_iterator buttonend() const;
			cbutton_iterator buttonrbegin() const;
			cbutton_iterator buttonrend() const;

			bool addKey(SDLKey key);
			int addKeys(std::vector<SDLKey> keys); // Retourne le nombre de keys ajoutées
			bool addForbid(SDLKey key);
			int addForbids(std::vector<SDLKey> keys); // idem

			bool addButton(Uint8 button);
			int addButtons(std::vector<Uint8> buttons);
			bool addReleased(Uint8 button);
			int addReleased(std::vector<Uint8> buttons);

			void clear();

			bool addKeys(std::string keys);
			bool addForbid(std::string keys);

		protected:
			std::vector<SDLKey> m_pressed; // Touches devant être pressées
			std::vector<SDLKey> m_released; // Touches devant êtres relachées
			std::vector<Uint8> m_buttonp; // Boutton devant être pressé
			std::vector<Uint8> m_buttonr; // Boutton devant être relaché

			std::vector<SDLKey> aKey(std::string str) const;
			std::vector<std::string> parseStr(std::string str) const;
	};
}

#endif//DEF_SDL_ANEVENT
