/*
 * =====================================================================================
 *
 *       Filename:  qtile.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/09/2014 15:28:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "gameworld.h"

int main(int argc, char **argv) {

  gameworld *game_world = new gameworld("game");

  while(game_world->get_window()->isOpen()) {
    while(game_world->poll_event()) {
      if(game_world->get_event()->type == sf::Event::Closed) {
        game_world->get_window()->close();
      }
    }
     
  game_world->get_window()->clear(sf::Color::Black);
  
  game_world->get_window()->display();
  }
  return 0;
}
