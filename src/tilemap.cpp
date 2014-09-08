/*
 * =====================================================================================
 *
 *       Filename:  tilemap.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/09/2014 17:07:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "tilemap.h"
#include <iostream>

tile::tile(unsigned int d,float pos_x, float pos_y, float w):diameter(d),x(pos_x),y(pos_y),weight(w),selected(false){
  std::cout << "Initializing tile at " << x << " " << y << std::endl;
}
tilemap::tilemap(sf::Vector2u dimension, unsigned int tile_d,gameworld *gw):_game_world(gw),_width(dimension.x),_height(dimension.y),tile_diameter(tile_d){

  _num_tiles_x = dimension.x / tile_diameter;
  _num_tiles_y = dimension.y / tile_diameter;
  _game_world = gw;

  std::cout << "Create new tile map for " <<_game_world->title << " with dimensions [" << _num_tiles_x << "|" << _num_tiles_y << "]"  << std::endl;
}
void tilemap::draw() {
  
  sf::RectangleShape rect(sf::Vector2f(tile_diameter,tile_diameter));
  rect.setOutlineThickness(1);
  rect.setOutlineColor(sf::Color(0,0,0));
  RenderWindow *window = _game_world->get_window();
  for(int x=0; x<_num_tiles_x; ++x) {
    for(int y=0;y<_num_tiles_y; ++y) {
      tile *current = &(_tile_matrix[x][y]);
      if(current->selected) {
        rect.setFillColor(sf::Color(0,0,0));
      }else {
        rect.setFillColor(sf::Color(255,255,255));
      }
      rect.setPosition(sf::Vector2f(current->x,current->y));
      window->draw(rect);
    }
  }
}
void tilemap::nominate_random_select() {
  
  srand(time(NULL));
  int x = rand() % _num_tiles_x;
  int y = rand() % _num_tiles_y;
  std::cout << "Nominating " << x << "|" << y <<std::endl;
  tile *current = &(_tile_matrix[x][y]);
  current->selected = true;
}
void tilemap::generate_map() {

  std::cout << _num_tiles_x << " | " << _num_tiles_y << std::endl;

  _tile_matrix = (tile**)calloc(_num_tiles_x,sizeof(tile));
  for(int x=0;x<_num_tiles_x;++x) {
    _tile_matrix[x] = (tile*)calloc(_num_tiles_y,sizeof(tile));
  }

  for(int x=0; x<_num_tiles_x; ++x) {
    for(int y=0;y<_num_tiles_y; ++y) {

      int pos_x = tile_diameter * x +1; 
      int pos_y = tile_diameter * y +1;
      tile *t = new tile(25,pos_x,pos_y,1);
      memcpy(&(_tile_matrix[x][y]),t,sizeof(tile));
    }
  }
}
