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
#include <SFML/Graphics.hpp>
using namespace sf;
class gameworld{
  
  public:
    gameworld(const char *title);
    ~gameworld();
    RenderWindow *get_window();
    bool poll_event();
    Event *get_event();
  private:
    RenderWindow *window;
    Event *next_event;
};
