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
#include "tilemap.h"
#include <iostream>
#define TILE_DIAMETER 25

int main(int argc, char **argv) {
  srand(time(NULL));
  gameworld *game_world = new gameworld((char*)"game",400,400);
  
  tilemap *tile_map = new tilemap(game_world->get_window_size(),TILE_DIAMETER,game_world);

  tile_map->generate_map();
  tile_map->nominate_random_start();
  tile_map->nominate_random_end();
  tile_map->generate_noise();

  while(game_world->get_window()->isOpen()) {
    while(game_world->poll_event()) {
      if(game_world->get_event()->type == sf::Event::Closed) {
        game_world->get_window()->close();
      }
    }
    game_world->get_window()->clear(sf::Color::Black);
    tile_map->draw();

    game_world->get_window()->display();
  }
  return 0;
}
