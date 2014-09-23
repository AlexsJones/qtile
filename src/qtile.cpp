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
#include "cartographer.h"
#include <iostream>
#define TILE_DIAMETER 25

int main(int argc, char **argv) {
  srand(time(NULL));

  gameworld *game_world = new gameworld((char*)"game",1000,1000);

  cartographer *_cartographer = new cartographer(); 
  tilemap *tile_map = new tilemap(TILE_DIAMETER,game_world, 2);
  tile_map->generate_map();

  sf::Vector2i start_t;
  sf::Vector2i end_t;

start_again:

  bool was_okay = tile_map->nominate_random_start(&start_t);
  if(!was_okay) {
    game_world->log("Encountered a problem assigning start location..trying again");
    goto start_again; 
  }
  std::cout << "Start at ["<<start_t.x << ":" << start_t.y << "]" << std::endl;
end_again:

  was_okay = tile_map->nominate_random_end(&end_t);
  if(!was_okay) {
    game_world->log("Encountered a problem assigning end location..trying again");
    goto end_again;
  }
  std::cout << "End at ["<<end_t.x << ":" << end_t.y << "]" << std::endl;

  tile_map->generate_noise();

  //crux of the example
  std::list<node*> *node_path = _cartographer->generate_path(start_t,end_t,tile_map);

  std::list<tile*> *tile_path = new std::list<tile*>();
  std::list<node*>::iterator i;
  for(i = node_path->begin(); i != node_path->end(); ++i) {
    tile *t = (*i)->this_tile;
    tile_path->push_back(t);
  }
  tile_map->update_best_path(tile_path);

  delete node_path;
  delete tile_path;

  while(game_world->get_window()->isOpen()) {
    while(game_world->poll_event()) {
      if((game_world->get_event()->type == sf::Event::KeyReleased) && (game_world->get_event()->key.code == sf::Keyboard::Escape)) {
        game_world->get_window()->close();
      }
      if(game_world->get_event()->type == sf::Event::Closed) {
        game_world->get_window()->close();
      }
      if((game_world->get_event()->type == sf::Event::KeyReleased) && (game_world->get_event()->key.code == sf::Keyboard::Space)){

      }
    }
    game_world->get_window()->clear(sf::Color::Black);
    tile_map->draw();

    game_world->get_window()->display();
  }
  
  return 0;
}
