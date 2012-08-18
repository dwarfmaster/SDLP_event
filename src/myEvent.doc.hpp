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
 * \file myEvent.doc.hpp
 * \brief Contient la doc de la classe MyEvent.
 */

/*!
 * \class sdl::MyEvent
 * \brief Interface pour les gestionnaires d'évènement.
 */

/*!
 * \fn virtual void sdl::MyEvent::update() =0
 * \brief Détecte les évènements et met à jour la classe.
 */

/*!
 * \fn virtual void sdl::MyEvent::updateFrom(SDL_Event* event) =0
 * \brief Met à jour la classe à partir du paramètre.
 * \param event Un pointeur sur l'évènement à utiliser pour mettre à jour la classe.
 */

/*!
 * \fn virtual bool sdl::MyEvent::isKeyPressed(unsigned int key) const =0
 * \brief Indique si la touche key est pressée.
 * \param key La touche à tester.
 * \return L'état de la touche (true = pressée, false = relachée).
 */

/*!
 * \fn virtual bool sdl::MyEvent::operator[](unsigned int key) const =0
 * \brief Indique si la touche key est pressée.
 * \param key La touche à tester.
 * \return L'état de la touche (true = pressée, false = relachée).
 */

/*!
 * \fn virtual bool sdl::MyEvent::isButtonPressed(unsigned int button) const =0
 * \brief Indique si le boutton button est appuyé.
 * \param button Le boutton à tester.
 * \return L'état du boutton (true = appuyé, false = relaché).
 */

/*!
 * \fn virtual SDL_Rect sdl::MyEvent::posMouse() const =0
 * \brief Donne la position de la souris.
 * \return La position de la souris.
 */

/*!
 * \fn virtual SDL_Rect sdl::MyEvent::relMouse() const =0
 * \brief Donne la position de la souris par rapport au dernier appel à update.
 * \return La position de la souris par rapport au dernier update.
 */

/*!
 * \fn virtual SDL_Rect sdl::MyEvent::windowsize() const =0
 * \brief Donne la taille de la fenêtre.
 * \return La taille de la fenêtre.
 */

/*!
 * \fn virtual bool sdl::MyEvent::hasMouseFocus() const =0
 * \brief Indique si la fenêtre à la focus de la souris.
 * \return Si la fenêtre à le focus true, sinon false.
 */

/*!
 * \fn virtual bool sdl::MyEvent::hasInputFocus() const =0
 * \brief Indique si la fenêtre à la focus du clavier.
 * \return Si la fenêtre à le focus true, sinon false.
 */

/*!
 * \fn virtual bool sdl::MyEvent::isIconify() const =0
 * \brief Indique si la fenêtre est iconifiée.
 * \return Si la fenêtre est iconifiée true, sinon false.
 */

/*!
 * \fn virtual bool sdl::MyEvent::quit() const =0
 * \brief Indique si l'évènement quit à été capté.
 * \return S'il faut quitter le programme.
 */


