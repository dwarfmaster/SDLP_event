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
 * \file myEvent.hpp
 * \brief Définit la classe abstraite MyEvent.
 */

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
