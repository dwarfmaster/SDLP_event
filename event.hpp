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

			bool addPEvent(std::string name, AnEvent* ev, boost::function<void ()> callback, boost::optional<boost::function<void ()>> onquit=boost::none, Uint32 time=0, Uint32 repeat=0);
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
				bool state; // Pressé ou pas
				Uint32 lastPress; // La dernière foix qu'on l'a pressé
				Uint32 lastRelease; // La dernière foix qu'on l'a relaché
			};

			// Status
			boost::array<PressEvent, SDLK_LAST> m_keys;
			SDL_Rect m_posMouse;
			SDL_Rect m_relMouse;
			boost::array<PressEvent, 8> m_buttons;

			SDL_Rect m_sizeWindow;
			bool m_mouseFocus;
			bool m_inputFocus;
			bool m_iconify;

			// Quit
			std::vector<SDLKey> m_quitKeys;
			bool m_quit;

			// Events specials
			struct PersEvent
			{
				AnEvent* event;
				Uint32 firstTime; // temps pour l'activer (si 0 immédiatement)
				Uint32 repeat; // Temps entre chaque répétition (si 0 pas de répétitions)
				boost::function<void ()> callback; // La fonction à appeller
				boost::function<void ()> quitCallback; // La fonction à appeller lorsque l'évènement devient faux
				bool launched; // déjà lancé ?
				Uint32 lastLaunched;
			};
			std::map<std::string, PersEvent> m_persEvents;

			void testPEvents();
			void testPEvent(std::string name);

			// Callbacks
			boost::function<void (SDL_keysym*)> m_onPressedKey;
			boost::function<void (SDL_keysym*)> m_onReleaseKey;
			boost::function<void (SDL_Rect, SDL_Rect)> m_onMouseMoved;
			boost::function<void (Uint8, SDL_Rect)> m_onPressedButton;
			boost::function<void (Uint8, SDL_Rect)> m_onReleaseButton;

			boost::function<void (SDL_Rect)> m_onResizeWindow;
			boost::function<void ()> m_onGetMouseFocus;
			boost::function<void ()> m_onLoseMouseFocus;
			boost::function<void ()> m_onGetInputFocus;
			boost::function<void ()> m_onLoseInputFocus;
			boost::function<void ()> m_onIconify;
			boost::function<void ()> m_onActive; // Le contre de onIconify
	};
};

#endif//DEF_SDLP_EVENT
