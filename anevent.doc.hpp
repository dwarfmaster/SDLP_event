/*!
 * \file anevent.doc.hpp
 * \brief La documentation de anevent.hpp.
 */

/*!
 * \namespace sdl
 * \brief Contient les fonctions des bibliothèques SDLP_qqchose.
 */

/*!
 * \class sdl::AnEvent
 * \brief Définit un évènement particulier.
 *
 * Celui-ci sous un ensemble de touches et de bouttons de souris devant être pressés ou relachés simultanéments pour le valider. Voir la classe sdl::Event pour l'usage.
 */

/*!
 * \typedef sdl::AnEvent::ckey_iterator
 * \brief Itérateur constant sur les touches.
 */

/*!
 * \typedef sdl::AnEvent::cbutton_iterator
 * \brief Itérateur constant sur les bouttons.
 */

/*!
 * \fn sdl::AnEvent::AnEvent()
 * \brief Initialise l'évènement comme vide.
 */

/*!
 * \fn sdl::AnEvent::AnEvent(SDLKey key)
 * \brief Initialise l'évènement avec key comme seule touche devant être pressée.
 * \param key La touche de l'évènement.
 */

/*! 
 * \fn sdl::AnEvent::AnEvent(std::vector<SDLKey> keys)
 * \brief Initialise l'évènement de telle sorte que les touches keys doivent être pressées.
 * \param keys Les touches devant être pressées.
 */

/*!
 * \fn sdl::AnEvent::AnEvent(std::vector<SDLKey> keys, std::vector<SDLKey> forbidden)
 * \brief Initialise l'évènement de façon que les touches keys doivent être pressées et les touches forbidden relachées.
 * \param keys Les touches devant être pressées.
 * \param forbidden Les touches devant être relachées.
 */

/*!
 * \fn sdl::AnEvent::AnEvent(const std::string& keys, const std::string& forb="")
 * \brief Initialise l'évènement de façon que les touches keys doivent être pressées et les touches forbidden relachées.
 * \param keys Les touches devant être pressées sous la forme "C-A-b" pour controle + alt + b.
 * \param forb Les touches devant être relachées sous la forme "a-z-e" pour a + z + b.
 */

/*!
 * \fn bool sdl::AnEvent::isNeed(SDLKey key) const
 * \brief Retourne si une touche doit être pressée.
 * \param key La touche à tester.
 * \return Un booléen indiquant si la touche doit être pressée.
 */

/*!
 * \fn bool sdl::AnEvent::isForbid(SDLKey key) const
 * \brief Retourne si une touche doit être relachée.
 * \param key La touche à tester.
 * \return Un booléen indiquant si la touche doit être relachée.
 */

/*!
 * \fn bool sdl::AnEvent::isMustPressed(Uint8 button) const
 * \brief Retourne si le boutton doit être pressé.
 * \param button Le boutton à tester.
 * \return Un booléen indiquant si le boutton doit être pressé.
 */

/*!
 * \fn bool sdl::AnEvent::isMustReleased(Uint8 button) const
 * \brief Retourne si le boutton doit être relaché.
 * \param button Le boutton à tester.
 * \return Un booléen indiquant si le boutton doit être relaché.
 */

/*!
 * \fn ckey_iterator sdl::AnEvent::keybegin() const
 * \brief L'itérateur de début sur les touches devant être pressées.
 * \return L'itérateur de début.
 */

/*!
 * \fn ckey_iterator sdl::AnEvent::keyend() const
 * \brief L'itérateur de fin sur les touches devant être pressées.
 * \return L'itérateur de fin.
 */

/*!
 * \fn ckey_iterator sdl::AnEvent::forbidbegin() const
 * \brief L'itérateur de début sur les touches devant être relachées.
 * \return L'itérateur de début.
 */

/*!
 * \fn ckey_iterator sdl::AnEvent::forbidend() const
 * \brief L'itérateur de fin sur les touches devant être relachées.
 * \return L'itérateur de fin.
 */

/*!
 * \fn cbutton_iterator sdl::AnEvent::buttonbegin() const
 * \brief L'itérateur de début sur les bouttons devant être pressées.
 * \return L'itérateur de début.
 */

/*!
 * \fn cbutton_iterator sdl::AnEvent::buttonend() const
 * \brief L'itérateur de fin sur les bouttons devant être pressées.
 * \return L'itérateur de fin.
 */

/*!
 * \fn cbutton_iterator sdl::AnEvent::buttonrbegin() const
 * \brief L'itérateur de début sur les bouttons devant être relachées.
 * \return L'itérateur de début.
 */

/*!
 * \fn cbutton_iterator sdl::AnEvent::buttonrend() const
 * \brief L'itérateur de fin sur les bouttons devant être relachées.
 * \return L'itérateur de fin.
 */

/*!
 * \fn bool sdl::AnEvent::addKey(SDLKey key)
 * \brief Ajoute la touche à celles devant être pressées.
 * \param key La touche à ajouter.
 * \return Indique si la touche à pu être ajoutée (false si elle y était déjà, ou si elle était dans les touches devant être relachées).
 */

/*!
 * \fn bool sdl::AnEvent::addKeys(std::vector<SDLKey> keys)
 * \brief Ajoute les touches à celles devant être pressées.
 * \param keys Les touches à ajouter.
 * \return Indique le nombre de touches qui ont pu être ajoutées.
 */

/*!
 * \fn bool sdl::AnEvent::addForbid(SDLKey key)
 * \brief Ajoute la touche à celles devant être relachées.
 * \param key La touche à ajouter.
 * \return Indique si la touche à pu être ajoutée (false si elle y était déjà, ou si elle était dans les touches devant être pressées).
 */

/*!
 * \fn bool sdl::AnEvent::addForbids(std::vector<SDLKey> keys)
 * \brief Ajoute les touches à celles devant être relachées.
 * \param keys Les touches à ajouter.
 * \return Indique le nombre de touches qui ont pu être ajoutées.
 */

/*!
 * \fn bool sdl::AnEvent::addButton(Uint8 button)
 * \brief Ajoute le bouttons à ceux devant être pressées.
 * \param button Le boutton à ajouter.
 * \return Indique si le boutton à pu être ajouté (false si il y était déjà, ou si il était dans les bouttons devant être relachés).
 */

/*!
 * \fn bool sdl::AnEvent::addButtons(std::vector<Uint8> buttons)
 * \brief Ajoute les bouttons à ceux devant être pressés.
 * \param button Les bouttons à ajouter.
 * \return Indique le nombre de bouttons qui ont pu être ajoutés.
 */

/*!
 * \fn bool sdl::AnEvent::addReleased(Uint8 button)
 * \brief Ajoute le bouttons à ceux devant être relachés.
 * \param button Le boutton à ajouter.
 * \return Indique si le boutton à pu être ajouté (false si il y était déjà, ou si il était dans les bouttons devant être pressés).
 */

/*!
 * \fn bool sdl::AnEvent::addReleased(std::vector<Uint8> buttons)
 * \brief Ajoute les bouttons à ceux devant être relachés.
 * \param button Les bouttons à ajouter.
 * \return Indique le nombre de bouttons qui ont pu être ajoutés.
 */

/*!
 * \fn void sdl::AnEvent::clear()
 * \brief Vide la classe, qui devient inutilisable.
 */

/*!
 * \fn bool sdl::AnEvent::addKeys(std::string keys)
 * \brief Ajoute les touches à celles devant être pressées.
 * \param keys Les touches sous la forme "C-b" pour controle + b.
 * \return Si les touches ont pu être ajoutées.
 */

/*!
 * \fn bool sdl::AnEvent::addForbid(std::string keys)
 * \brief Ajoute les touches à celles devant être relachées.
 * \param keys Les touches sous la forme "C-b" pour controle + b.
 * \return Si les touches ont pu être ajoutées.
 */

/*!
 * \fn void sdl::AnEvent::setPlace(const SDL_Rect& place)
 * \brief Définit un zone dans laquelle doit être la souris pour valider l'évènement.
 * \param place La zone.
 */

/*!
 * \fn void sdl::AnEvent::unsetPlace()
 * \brief Défait la zone (l'évènement est désormais valable n'importe où).
 */

/*!
 * \fn boost::optional<SDL_Rect> sdl::AnEvent::getPlace() const
 * \brief Retourne la zone de l'évènement.
 * \return La zone de l'évènement. Retourne boost:none s'il n'y en a pas.
 */

/*!
 * \fn std::vector<SDLKey> aKey(std::string str) const
 * \brief Retourne les touches équivalentes à une chaine.
 * \param str La chaine à parse (comme "C").
 * \return Les touches équivalentes (dans ce cas, [SDLK_LCTRL, SDLK_RCTRL]).
 */

/*!
 * \fn std::vector<std::string> parseStr(std::string str) const
 * \brief Sépare les touches d'une chaine.
 * \param str La chaine à séparer (comme "C-b").
 * \return La chaine découpée (dans ce cas, ["C", "b"]).
 */

