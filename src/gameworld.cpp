/*
 * =====================================================================================
 *
 *       Filename:  gameworld.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/09/2014 16:00:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "gameworld.h"

gameworld::gameworld(const char *title) {
  window = new sf::RenderWindow(sf::VideoMode(400,400),title);  
  next_event = new Event();
}
gameworld::~gameworld() {

}
RenderWindow *gameworld::get_window() {
  return window;
}
bool gameworld::poll_event() {
  return window->pollEvent(*next_event);
}
Event *gameworld::get_event() {
  return next_event;
}
