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

gameworld::gameworld(char *title,unsigned int w, unsigned int h):title(title),width(w),height(h) {
  window = new sf::RenderWindow(sf::VideoMode(w,h),title);  
  next_event = new Event();
}
gameworld::~gameworld() {
  delete next_event;
  delete window;
}
RenderWindow *gameworld::get_window() {
  return window;
}
Vector2u gameworld::get_window_size() {
  return window->getSize();
}
bool gameworld::poll_event() {
  return window->pollEvent(*next_event);
}
Event *gameworld::get_event() {
  return next_event;
}
void gameworld::log(const char *format, ...) {
  va_list argptr;
  va_start(argptr,format);
  JNX_LOG(log_context,format,argptr);
  va_end(argptr);
}
