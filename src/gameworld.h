/*
 * =====================================================================================
 *
 *       Filename:  gameworld.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/09/2014 15:53:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __GAMEWORLD_H__
#define __GAMEWORLD_H__
#include <SFML/Graphics.hpp>
#include <jnxc_headers/jnxlog.h>
using namespace sf;
class gameworld{
  public:
    gameworld(char *title,unsigned int w, unsigned int h);
    ~gameworld();
    RenderWindow *get_window();
    bool poll_event();
    Event *get_event();
    Vector2u get_window_size();
  
    char *title;
    unsigned int width;
    unsigned int height;
  private:
    JNX_LOG_CONTEXT(log_context);
    RenderWindow *window;
    Event *next_event;

};
#endif
