/*!
 * \file event.doc.hpp
 * \brief Contient la doc de la classe Event.
 */

/*!
 * \class sdl::Event
 * \brief Capteur d'évènements.
 *
 * Permet de savoir à tout moment l'état des périphériques. Permet aussi de définir des callbacks et des évènements personnalisés.
 */

/*!
 * \fn virtual void sdl::Event::update()
 * \brief Détecte les évènements, met à jour la classe, teste les évènements personnalisés et appelle les callbacks nécessaires.
 */

/*!
 * \fn virtual void sdl::Event::updateFrom(SDL_Event* event)
 * \brief Détecte les évènements, met à jour la classe, teste les évènements personnalisés et appelle les callbacks nécessaires à partir du paramètre.
 * \param event Un pointeur sur l'évènement à utiliser pour mettre à jour la classe.
 */

/*!
 * \fn Uint32 sdl::Event::timeKeyPressed(unsigned int key) const
 * \brief Donne le temps durant lequel la touche a été pressée.
 * \param key La touche à tester.
 * \return Le temps en millisecondes durant lequel la touche est restée appuyée, et 0 si elle est relachée.
 */

/*!
 * \fn Uint32 sdl::Event::lastKeyPress(unsigned int key) const
 * \brief Donne le temps lorsque la touche a été pressée pour la dernière fois.
 * \param key La touche à tester.
 * \return Le temps retourné par SDL_GetTicks lors du dernier appui de la touche.
 */

/*!
 * \fn Uint32 sdl::Event::lastKeyRelease(unsigned int key) const
 * \brief Donne le temps lorsque la touche a été relachée pour la dernière fois.
 * \param key La touche à tester.
 * \return Le temps retourné par SDL_GetTicks lors du dernier relachement de la touche.
 */

/*!
 * \fn Uint32 sdl::Event::timeButtonPressed(Uint8 button) const
 * \brief Donne le temps durant lequel le boutton a été pressé.
 * \param button Le boutton à tester.
 * \return Le temps en millisecondes durant lequel le boutton est restée appuyé, et 0 si il est relaché.
 */

/*!
 * \fn Uint32 sdl::Event::lastButtonPress(Uint8 button) const
 * \brief Donne le temps lorsque le boutton a été pressé pour la dernière fois.
 * \param button Le boutton à tester.
 * \return Le temps retourné par SDL_GetTicks lors du dernier appui du boutton.
 */

/*!
 * \fn Uint32 sdl::Event::lastButtonRelease(Uint8 button) const
 * \brief Donne le temps lorsque le boutton a été relaché pour la dernière fois.
 * \param button Le boutton à tester.
 * \return Le temps retourné par SDL_GetTicks lors du dernier relachement du boutton.
 */

/*!
 * \fn bool sdl::Event::alt() const
 * \brief Indique si une des touches alt est pressée.
 * \return Si une des touches alt est pressée true, sinon false.
 */

/*!
 * \fn bool sdl::Event::ctrl() const
 * \brief Indique si une des touches ctrl est pressée.
 * \return Si une des touches ctrl est pressée true, sinon false.
 */

/*!
 * \fn bool sdl::Event::shift() const
 * \brief Indique si une des touches shift est pressée.
 * \return Si une des touches shift est pressée true, sinon false.
 */

/*!
 * \fn bool sdl::Event::super() const
 * \brief Indique si une des touches super est pressée.
 * \return Si une des touches super est pressée true, sinon false.
 */

/*!
 * \fn bool sdl::Event::num() const
 * \brief Indique si verr num est activé.
 * \return Si verr num est activé true, sinon false.
 */

/*!
 * \fn bool sdl::Event::caps() const
 * \brief Indique si caps lock est activé.
 * \return Si caps lock est activé true, sinon false.
 */

/*!
 * \fn void sdl::Event::setOnCaptedEventCallback(boost::function<void (SDL_Event)> func)
 * \brief Définit une fonction de callback appelée lorsqu'un évènement est capté.
 * \param func La fonction de callback. Doit prendre en paramètre un SDL_Event.
 */

/*!
 * \fn bool sdl::Event::isOnCaptedEventCallback() const
 * \brief Indique si une fonction de callback est définie pour les évènements captés.
 * \return Si ce callback est définit true, sinon false.
 */

/*!
 * \fn void sdl::Event::clearOnCaptedEventCallback()
 * \brief Supprime la fonction de callback pour les évènements captés.
 */

/*!
 * \fn void sdl::Event::setOnPressedKeyCallback(boost::function<void (SDL_keysym*)> func)
 * \brief Définit une fonction de callback appelée lorsqu'un appui de touche est capté.
 * \param func La fonction de callback. Doit prendre en paramètre un pointeur sur SDL_keysym.
 */

/*!
 * \fn bool sdl::Event::isOnPressedKeyCallback() const
 * \brief Indique si une fonction de callback est définie pour les appuis de touche.
 * \return Si ce callback est définit true, sinon false.
 */

/*!
 * \fn void sdl::Event::clearOnPressedKeyCallback()
 * \brief Supprime la fonction de callback pour les appuis de touche.
 */

/*!
 * \fn void sdl::Event::setOnReleaseKeyCallback(boost::function<void (SDL_keysym*)> func)
 * \brief Définit une fonction de callback appelée lorsqu'un relachement de touche est capté.
 * \param func La fonction de callback. Doit prendre en paramètre un pointeur sur SDL_keysym.
 */

/*!
 * \fn bool sdl::Event::isOnReleaseKeyCallback() const
 * \brief Indique si une fonction de callback est définie pour les relachements de touche.
 * \return Si ce callback est définit true, sinon false.
 */

/*!
 * \fn void sdl::Event::clearOnReleaseKeyCallback()
 * \brief Supprime la fonction de callback pour les relachements de touche.
 */

/*!
 * \fn void sdl::Event::setOnMouseMovedCallback(boost::function<void (SDL_Rect, SDL_Rect)> func)
 * \brief Définit un fonction de callback pour les déplacement de souris.
 * \param func La fonction de callback. Doit prendre en paramètre deux SDL_Rect, le premier pour la position absolue de la souris et l'autre pour sa position relative.
 */

/*!
 * \fn bool sdl::Event::isOnMouseMovedCallback() const
 * \brief Indique si une fonction de callback est définie pour les mouvements de souris.
 * \return Si ce callback est définit true, sinon false.
 */

/*!
 * \fn void sdl::Event::clearMouseMovedCallback()
 * \brief Supprime la fonction de callback pour les mouvements de souris.
 */

/*!
 * \fn void sdl::Event::setOnPressedButtonCallback(boost::function<void (Uint8, SDL_Rect)> func)
 * \brief Définit une fonction de callback appelée lorsqu'un appui de boutton est capté.
 * \param func La fonction de callback. Doit prendre en paramètre un Uint8 (le code du boutton) et un SDL_Rect (la position de la souris).
 */

/*!
 * \fn bool sdl::Event::isOnPressedButtonCallback() const
 * \brief Indique si une fonction de callback est définie pour les appuis de boutton.
 * \return Si ce callback est définit true, sinon false.
 */

/*!
 * \fn void sdl::Event::clearOnPressedButtonCallback()
 * \brief Supprime la fonction de callback pour les appuis de boutton.
 */

/*!
 * \fn void sdl::Event::setOnReleaseButtonCallback(boost::function<void (Uint8, SDL_Rect)> func)
 * \brief Définit une fonction de callback appelée lorsqu'un relachement de boutton est capté.
 * \param func La fonction de callback. Doit prendre en paramètre un Uint8 (le code du boutton) et un SDL_Rect (la position de la souris).
 */

/*!
 * \fn bool sdl::Event::isOnReleaseButtonCallback() const
 * \brief Indique si une fonction de callback est définie pour les relachements de boutton.
 * \return Si ce callback est définit true, sinon false.
 */

/*!
 * \fn void sdl::Event::clearOnReleaseButtonCallback()
 * \brief Supprime la fonction de callback pour les relachements de boutton.
 */

/*!
 * \fn void sdl::Event::setOnResizeWindowCallback(boost::function<void (SDL_Rect)> func)
 * \brief Définit un fonction de callback pour les redimensionnements.
 * \param func La fonction de callback. Doit prendre en paramètre un SDL_Rect, la nouvelle taille de la fenêtre.
 */

/*!
 * \fn bool sdl::Event::isOnResizeWindowCallBack() const
 * \brief Indique si une fonction de callback est définie pour les redimensionnements.
 * \return Si ce callback est définit true, sinon false.
 */

/*!
 * \fn void sdl::Event::clearOnResizeWindowCallback()
 * \brief Supprime la fonction de callback pour les redimensionnements.
 */

/*!
 * \fn void sdl::Event::setOnGetMouseFocusCallback(boost::function<void ()> func)
 * \brief Définit une fonction de callback appelée lorsque la fenêtre obtient le focus de la souris.
 * \param func La fonction de callback.
 */

/*!
 * \fn bool sdl::Event::isOnGetMouseFocusCallback() const
 * \brief Indique si une fonction de callback est définie pour l'obtention du focus de la souris.
 * \return Si ce callback est définit true, sinon false.
 */

/*!
 * \fn void sdl::Event::clearOnGetMouseFocusCallback()
 * \brief Supprime la fonction de callback pour l'obtention du focus de la souris.
 */

/*!
 * \fn void sdl::Event::setOnLoseMouseFocusCallback(boost::function<void ()> func)
 * \brief Définit une fonction de callback appelée lorsque la fenêtre pert le focus de la souris.
 * \param func La fonction de callback.
 */

/*!
 * \fn bool sdl::Event::isOnLoseMouseFocusCallback() const
 * \brief Indique si une fonction de callback est définie pour la perte du focus de la souris.
 * \return Si ce callback est définit true, sinon false.
 */

/*!
 * \fn void sdl::Event::clearOnLoseMouseFocusCallback()
 * \brief Supprime la fonction de callback pour la perte du focus de la souris.
 */

/*!
 * \fn void sdl::Event::setOnGetInputFocusCallback(boost::function<void ()> func)
 * \brief Définit une fonction de callback appelée lorsque la fenêtre obtient le focus du clavier.
 * \param func La fonction de callback.
 */

/*!
 * \fn bool sdl::Event::isOnGetInputFocusCallback() const
 * \brief Indique si une fonction de callback est définie pour l'obtention du focus du clavier.
 * \return Si ce callback est définit true, sinon false.
 */

/*!
 * \fn void sdl::Event::clearOnGetInputFocusCallback()
 * \brief Supprime la fonction de callback pour l'obtention du focus du clavier.
 */

/*!
 * \fn void sdl::Event::setOnLoseInputFocusCallback(boost::function<void ()> func)
 * \brief Définit une fonction de callback appelée lorsque la fenêtre pert le focus du clavier.
 * \param func La fonction de callback.
 */

/*!
 * \fn bool sdl::Event::isOnLoseInputFocusCallback() const
 * \brief Indique si une fonction de callback est définie pour la perte du focus du clavier.
 * \return Si ce callback est définit true, sinon false.
 */

/*!
 * \fn void sdl::Event::clearOnLoseInputFocusCallback()
 * \brief Supprime la fonction de callback pour la perte du focus du clavier.
 */

/*!
 * \fn void sdl::Event::setOnIconifyCallback(boost::function<void ()> func)
 * \brief Définit une fonction de callback appelée lorsque la fenêtre est iconifiée.
 * \param func La fonction de callback.
 */

/*!
 * \fn bool sdl::Event::isOnIconifyCallback() const
 * \brief Indique si une fonction de callback est définie pour l'iconification de la fenêtre.
 * \return Si ce callback est définit true, sinon false.
 */

/*!
 * \fn void sdl::Event::clearOnIconifyCallback()
 * \brief Supprime la fonction de callback pour l'iconification de la fenêtre.
 */

/*!
 * \fn void sdl::Event::setOnActiveCallback(boost::function<void ()> func)
 * \brief Définit une fonction de callback appelée lorsque la fenêtre est activée.
 * \param func La fonction de callback.
 */

/*!
 * \fn bool sdl::Event::isOnActiveCallback() const
 * \brief Indique si une fonction de callback est définie pour l'activation de la fenêtre.
 * \return Si ce callback est définit true, sinon false.
 */

/*!
 * \fn void sdl::Event::clearOnActiveCallback()
 * \brief Supprime la fonction de callback pour l'activation de la fenêtre.
 */

/*!
 * \fn void sdl::Event::addQuitKey(SDLKey key)
 * \brief Ajoute une touche comme touche pour quitter.
 * \param key La touche à ajouter.
 */

/*!
 * \fn void sdl::Event::addQuitKeys(std::vector<SDLKey> keys)
 * \brief Ajoute plusieures touches comme touche pour quitter.
 * \param keys Les touches à ajouter.
 */

/*!
 * \fn void sdl::Event::setQuitKeys(std::vector<SDLKey> keys)
 * \brief Définits des touches commes touches pour quitter.
 * \param keys Les touches à définir.
 */

/*!
 * \fn void sdl::Event::clearQuitKeys()
 * \brief Supprime les touches pour quitter.
 */

/*!
 * \fn std::vector<SDLKey> sdl::Event::getQuitKeys() const
 * \brief Donne les touches définies comme touches pour quitter.
 * \return Les touches pour quitter.
 */

/*!
 * \fn bool sdl::Event::isQuitKey(SDLKey key) const
 * \brief Indique si une touche est une touche pour quitter.
 * \param key La touche à tester.
 * \return Si la touche est une touche pour quitter true, sinon false.
 */

/*!
 * \fn bool sdl::Event::addPEvent(std::string name, AnEvent* ev, boost::function<void ()> callback, boost::optional<boost::function<void ()> > onquit=boost::none, Uint32 time=0, Uint32 repeat=0)
 * \brief Ajoute un évènement personnalisé.
 * \param name Le nom de l'évènement (utilisé pour y accéder par la suite).
 * \param ev Un pointeur sur l'évènement. L'évènement ne sera pas copié, il ne faut donc pas désallouer le pointeur.
 * \param callback La fonction à appeller lorsque que l'évènement est validé.
 * \param onquit La fonction à appeller lorsque l'évènement passe de l'état validé à l'état non validé.
 * \param time Le temps durant lequel l'évènement doit rester validé avant d'appeller la fonction de callback.
 * \param repeat Le temps entre chaque appel de la fonction de callback si l'évènement reste validé. Une valeur de 0 désactive la répétition.
 * \return Revoie true si l'évènement a pu être ajouté.
 */

/*!
 * \fn bool sdl::Event::changePEventCallback(std::string name, boost::function<void ()> callback)
 * \brief Change la fonction de callback pour l'évènement de nom name.
 * \param name Le nom de l'évènement dont on doit changer la fonction de callback.
 * \param callback La nouvelle fonction de callback.
 * \return Renvoie true si la fonction de callback a pu être changée.
 */

/*!
 * \fn bool sdl::Event::clearPEventCallback(std::string name)
 * \brief Supprime la fonction de callback pour un évènement.
 * \param name Le nom de l'évènement dont on doit supprimer le callback.
 * \return Renvoie true si le callback a pu être supprimé.
 */

/*!
 * \fn bool sdl::Event::changePEventQuitCallback(std::string name, boost::function<void ()> callback)
 * \brief Change la fonction de callback pour la fin de l'évènement de nom name.
 * \param name Le nom de l'évènement dont on doit changer la fonction de callback.
 * \param callback La nouvelle fonction de callback.
 * \return Renvoie true si la fonction de callback a pu être changée.
 */

/*!
 * \fn bool sdl::Event::clearPEventQuitCallback(std::string name)
 * \brief Supprime la fonction de callback pour la fin d'un évènement.
 * \param name Le nom de l'évènement dont on doit supprimer le callback.
 * \return Renvoie true si le callback a pu être supprimé.
 */

/*!
 * \fn bool sdl::Event::changePEventTime(std::string name, Uint32 time, boost::optional<Uint32> repeat=boost::none)
 * \brief Change le temps d'activation d'un évènement.
 * \param name Le nom de l'évènement qu'on doit modifier.
 * \param time Le nouveau temps d'activation.
 * \param repeat Le nouveau temps de répétition. N'est pas modifié si repeat faut boost::none.
 * \return Renvoie true si le temps a pu être changé.
 */

/*!
 * \fn bool sdl::Event::changePEventName(std::string name, std::string nname)
 * \brief Change le nom d'un évènement.
 * \param name Le nom de l'évènement que l'on doit modifier.
 * \param nname Le nouveau nom de l'évènement.
 * \return Renvoie true si le nom de l'évènement a pu être changé.
 */

/*!
 * \fn bool sdl::Event::deletePEvent(std::string name)
 * \brief Supprime un évènement.
 * \param name Le nom de l'évènement à supprimer.
 * \return Renvoie true si l'évènement a pu être supprimé.
 */

/*!
 * \fn bool sdl::Event::existPEvent(std::string name) const
 * \brief Teste l'existence d'un évènement.
 * \param name Le nom de l'évènement à tester.
 * \return Renvoie true si l'évènement existe.
 */

/*!
 * \struct sdl::Event::PressEvent
 * \brief Sert à stocker les informations relatives à l'appui sur une touche ou un boutton.
 */

/*!
 * \struct sdl::Event::PersEvent
 * \brief Sert à stocker un évènement personnalisé.
 */

/*!
 * \fn void sdl::Event::testPEvents()
 * \brief Parcoure et teste tous les évènements personnalisés.
 */

/*!
 * \fn void sdl::Event::testPEvent(std::string name)
 * \brief Teste un évènement personnalisé.
 * \param name Le nom de l'évènement personnalisé à tester.
 */




