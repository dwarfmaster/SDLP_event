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
 * \file event.hpp
 * \brief Définit la classe Event.
 */

#ifndef DEF_SDLP_EVENT
#define DEF_SDLP_EVENT

#include <SDL/SDL.h>

#include <boost/array.hpp>
#include <boost/function.hpp>
#include <boost/optional.hpp>

#include <vector>
#include <map>
#include <limits>

#include "myEvent.hpp"
#include "anevent.hpp"

namespace sdl
{
	class Event : public MyEvent
	{
		public:
			Event();
			Event(const Event& cp);
			Event& operator=(const Event& cp);

			virtual void update();
			virtual void updateFrom(SDL_Event* event);

			virtual bool isKeyPressed(unsigned int key) const;
			virtual bool operator[](unsigned int key) const;
			Uint32 timeKeyPressed(unsigned int key) const; // Retourne le temps écoulé depuis la pression de la key, et 0 si elle n'est pas pressée
			Uint32 lastKeyPress(unsigned int key) const;
			Uint32 lastKeyRelease(unsigned int key) const;

			virtual bool isButtonPressed(unsigned int button) const;
			Uint32 timeButtonPressed(Uint8 button) const;
			Uint32 lastButtonPress(Uint8 button) const;
			Uint32 lastButtonRelease(Uint8 button) const;
			virtual SDL_Rect posMouse() const;
			virtual SDL_Rect relMouse() const;

			virtual SDL_Rect windowsize() const;
			virtual bool hasMouseFocus() const;
			virtual bool hasInputFocus() const;
			virtual bool isIconify() const;

			virtual bool quit() const;
			bool alt() const;
			bool ctrl() const;
			bool shift() const;
			bool super() const;
			bool num() const;
			bool caps() const;

			void setOnCaptedEventCallback(boost::function<void (SDL_Event)> func);
			bool isOnCaptedEventCallback() const;
			void clearOnCaptedEventCallback();

			void setOnPressedKeyCallback(boost::function<void (SDL_keysym*)> func);
			bool isOnPressedKeyCallback() const;
			void clearOnPressedKeyCallback();
			void setOnReleaseKeyCallback(boost::function<void (SDL_keysym*)> func);
			bool isOnReleaseKeyCallback() const;
			void clearOnReleaseKeyCallback();

			void setOnMouseMovedCallback(boost::function<void (SDL_Rect, SDL_Rect)> func);
			bool isOnMouseMovedCallback() const;
			void clearMouseMovedCallback();

			void setOnPressedButtonCallback(boost::function<void (Uint8, SDL_Rect)> func);
			bool isOnPressedButtonCallback() const;
			void clearOnPressedButtonCallback();
			void setOnReleaseButtonCallback(boost::function<void (Uint8, SDL_Rect)> func);
			bool isOnReleaseButtonCallback() const;
			void clearOnReleaseButtonCallback();

			void setOnResizeWindowCallback(boost::function<void (SDL_Rect)> func);
			bool isOnResizeWindowCallBack() const;
			void clearOnResizeWindowCallback();

			void setOnGetMouseFocusCallback(boost::function<void ()> func);
			bool isOnGetMouseFocusCallback() const;
			void clearOnGetMouseFocusCallback();
			void setOnLoseMouseFocusCallback(boost::function<void ()> func);
			bool isOnLoseMouseFocusCallback() const;
			void clearOnLoseMouseFocusCallback();

			void setOnGetInputFocusCallback(boost::function<void ()> func);
			bool isOnGetInputFocusCallback() const;
			void clearOnGetInputFocusCallback();
			void setOnLoseInputFocusCallback(boost::function<void ()> func);
			bool isOnLoseInputFocusCallback() const;
			void clearOnLoseInputFocusCallback();

			void setOnIconifyCallback(boost::function<void ()> func);
			bool isOnIconifyCallback() const;
			void clearOnIconifyCallback();
			void setOnActiveCallback(boost::function<void ()> func);
			bool isOnActiveCallback() const;
			void clearOnActiveCallback();

			void addQuitKey(SDLKey key);
			void addQuitKeys(std::vector<SDLKey> keys);
			void setQuitKeys(std::vector<SDLKey> keys);
			void clearQuitKeys();
			std::vector<SDLKey> getQuitKeys() const;
			bool isQuitKey(SDLKey key) const;

			bool addPEvent(std::string name, AnEvent* ev, boost::function<void ()> callback, boost::optional<boost::function<void ()> > onquit=boost::none, Uint32 time=0, Uint32 repeat=0);
			bool changePEventCallback(std::string name, boost::function<void ()> callback);
			bool clearPEventCallback(std::string name);
			bool changePEventQuitCallback(std::string name, boost::function<void ()> callback);
			bool clearPEventQuitCallback(std::string name);
			bool changePEventTime(std::string name, Uint32 time, boost::optional<Uint32> repeat=boost::none);
			bool changePEventName(std::string name, std::string nname);
			bool deletePEvent(std::string name);
			bool existPEvent(std::string name) const;

		protected:
			// An event
			struct PressEvent
			{
				bool state; /*!< Pressé ou pas. */
				Uint32 lastPress; /*!< La dernière fois qu'on l'a pressé. */
				Uint32 lastRelease; /*!< La dernière fois qu'on l'a relaché. */
			};

			// Status
			boost::array<PressEvent, SDLK_LAST> m_keys; /*!< L'état du clavier. */
			SDL_Rect m_posMouse; /*!< La position de la souris. */
			SDL_Rect m_relMouse; /*!< La position de la souris par rapport à sa dernière position. */
			boost::array<PressEvent, 8> m_buttons; /*!< L'état des bouttons. */

			SDL_Rect m_sizeWindow; /*!< La taille de la fenêtre. */
			bool m_mouseFocus; /*!< Si la fenêtre a le focus de la souris. */
			bool m_inputFocus; /*!< Si la fenêtre a le focus du clavier. */
			bool m_iconify; /*!< Si la fenêtre est iconifiée. */

			// Quit
			std::vector<SDLKey> m_quitKeys; /*!< Les touches servant à quitter. */
			bool m_quit; /*!< S'il faut quitter. */

			// Specials events
			struct PersEvent
			{
				AnEvent* event; /*!< L'évènement. */
				Uint32 firstTime; /*!< temps pour l'activer (si 0 immédiatement). */
				Uint32 repeat; /*!< Temps entre chaque répétition (si 0 pas de répétitions). */
				boost::function<void ()> callback; /*!< La fonction à appeller. */
				boost::function<void ()> quitCallback; /*!< La fonction à appeller lorsque l'évènement devient faux. */
				bool launched; /*!< Si l'évènement est déjà lancé. */
				Uint32 lastLaunched; /*!< Le dernier lancement de l'évènement. */
			};
			std::map<std::string, PersEvent> m_persEvents; /*!< La liste des évènements personnalisés associés à leurs noms. */

			void testPEvents();
			void testPEvent(std::string name);

			// Callbacks
			boost::function<void (SDL_Event)> m_onCaptedEvent; /*!< Fonction appelée à chaque nouvel évènement. */

			boost::function<void (SDL_keysym*)> m_onPressedKey; /*!< Fonction appelée à chaque appui de touche. */
			boost::function<void (SDL_keysym*)> m_onReleaseKey; /*!< Fonction appelée à chaque relachement de touche. */
			boost::function<void (SDL_Rect, SDL_Rect)> m_onMouseMoved; /*!< Fonction appelée à chaque déplacement de la souris (le premier argument est la postion absolue et le deuxième la position relative). */
			boost::function<void (Uint8, SDL_Rect)> m_onPressedButton; /*!< Fonction appelée à chaque appui de boutton. */
			boost::function<void (Uint8, SDL_Rect)> m_onReleaseButton; /*!< Fonction appelée à chaque relachement de boutton. */

			boost::function<void (SDL_Rect)> m_onResizeWindow; /*!< Fonction appelée lors du redimensionnement de la fenêtre. */
			boost::function<void ()> m_onGetMouseFocus; /*!< Fonction appelée lors du gain du focus de la souris. */
			boost::function<void ()> m_onLoseMouseFocus; /*!< Fonction appelée lors de la perte du focus de la souris. */
			boost::function<void ()> m_onGetInputFocus; /*!< Fonction appelée lors du gain du focus du clavier. */
			boost::function<void ()> m_onLoseInputFocus; /*!< Fonction appelée lors de la perte du focus du clavier. */
			boost::function<void ()> m_onIconify; /*!< Fonction appelée lorsque la fenêtre est iconifiée. */
			boost::function<void ()> m_onActive; /*!< Fonction appelée lorsque la fenêtre est activée (restorée). */
	};
};

#endif//DEF_SDLP_EVENT
