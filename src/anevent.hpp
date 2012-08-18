/*
 * Copyright (C) 2012 Chabassier Luc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/*!
 * \file anevent.hpp
 * \brief Définit la classe AnEvent.
 */

#ifndef DEF_SDL_ANEVENT
#define DEF_SDL_ANEVENT

#include <vector>
#include <string>
#include <boost/optional.hpp>
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
			bool isMustReleased(Uint8 button) const;

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

			void setPlace(const SDL_Rect& place);
			void unsetPlace();
			boost::optional<SDL_Rect> getPlace() const;

		protected:
			std::vector<SDLKey> m_pressed; /*!< Touches devant être pressées. */
			std::vector<SDLKey> m_released; /*!< Touches devant êtres relachées. */
			std::vector<Uint8> m_buttonp; /*!< Bouttons devant être pressé. */
			std::vector<Uint8> m_buttonr; /*!< Bouttons devant être relaché. */

			bool m_usePlace; /*!< Si l'évènement utilise une localisation. */
			SDL_Rect m_place; /*!< Localisation de l'évènement. */

			std::vector<SDLKey> aKey(std::string str) const;
			std::vector<std::string> parseStr(std::string str) const;
	};
}

#endif//DEF_SDL_ANEVENT
