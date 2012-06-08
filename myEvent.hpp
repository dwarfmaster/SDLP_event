#ifndef DEF_SDLP_MY_EVENT
#define DEF_SDLP_MY_EVENT

#include <SDL/SDL.h>

namespace sdl
{
	class MyEvent
	{
		public:
			virtual void update() =0;
			virtual void updateFrom(SDL_Event* event) =0;

			virtual bool isKeyPressed(unsigned int key) const =0;
			virtual bool operator[](unsigned int key) const =0;

			virtual bool isButtonPressed(unsigned int button) const =0;
			virtual SDL_Rect posMouse() const =0;
			virtual SDL_Rect relMouse() const =0;

			virtual SDL_Rect windowsize() const =0;
			virtual bool hasMouseFocus() const =0;
			virtual bool hasInputFocus() const =0;
			virtual bool isIconify() const =0;

			virtual bool quit() const =0;

		private:
	};
};

#endif//DEF_SDLP_MY_EVENT
