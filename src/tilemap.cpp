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
#include <string.h>
#include "tilemap.h"
#include <iostream>

tile::tile(unsigned int d,float pos_x, float pos_y, float w,int gx,int gy):diameter(d),x(pos_x),y(pos_y),weight(w),current_state(UNSELECTED),grid_x(gx),grid_y(gy){
}
tilemap::tilemap(unsigned int tile_d,gameworld *gw, int noise_factor):_game_world(gw),_width(gw->width),_height(gw->height),tile_diameter(tile_d),_noise_factor(noise_factor){

  _num_tiles_x = gw->width / tile_diameter;
  _num_tiles_y = gw->height / tile_diameter;
  _game_world = gw;
}
void tilemap::draw() {

  sf::RectangleShape rect(sf::Vector2f(tile_diameter,tile_diameter));
  rect.setOutlineThickness(1);
  rect.setOutlineColor(sf::Color(0,0,0));
  RenderWindow *window = _game_world->get_window();
  for(int x=0; x<_num_tiles_x; ++x) {
    for(int y=0;y<_num_tiles_y; ++y) {
      tile *current = &(_tile_matrix[x][y]);

      switch(current->current_state) {
        case UNSELECTED: 
          rect.setFillColor(sf::Color(255,255,255));
          break;
        case START:
          rect.setFillColor(sf::Color(0,255,0));
          break;
        case END:
          rect.setFillColor(sf::Color(255,0,0));
          break;
        case PATHCONFIRMED:
          rect.setFillColor(sf::Color(0,0,255));
          break;
        case PATHFINDING:
          rect.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
          break;
        case OBSTRUCTION:
          rect.setFillColor(sf::Color(0,0,0));
          break;
        case PATH:
          rect.setFillColor(sf::Color(0,0,255));
        default:
          rect.setFillColor(sf::Color(255,255,255));
      }
      rect.setPosition(sf::Vector2f(current->x,current->y));
      window->draw(rect);
    }
  }
}

void tilemap::generate_noise(void) {

  int num = rand() % (_num_tiles_x * _num_tiles_y) / _noise_factor;
  std::cout << "Generating "<< num << " random tiles" << std::endl;
  for(int i=0;i<num;++i) {
    sf::Vector2i pos;
    if (nominate_random(OBSTRUCTION,&pos)) {
      //okay
    }
  }
}
bool tilemap::nominate_random(STATE s, sf::Vector2i *out_vector) {
  int x = rand() % _num_tiles_x;
  int y = rand() % _num_tiles_y;
  tile *current = &(_tile_matrix[x][y]);
  if(current->current_state == UNSELECTED) {
    current->current_state = s;
  }else {
    *out_vector = sf::Vector2i(0,0);
    return false;
  }
  *out_vector = sf::Vector2i(x,y);
  return true;
}
bool tilemap::nominate_random_end(sf::Vector2i *out_vector) {
  return nominate_random(END,out_vector);
}
bool tilemap::nominate_random_start(sf::Vector2i *out_vector) {
  return nominate_random(START,out_vector); 
}
void tilemap::update_best_path(std::list<tile*> *path) {
  int len = path->size();
  for(int x =0; x < len; ++x) {
    tile *t = path->front();
    if(t->current_state != END) 
    {
      t->current_state = PATHCONFIRMED;
    }
    path->pop_front();
  }
}
void tilemap::generate_map() {

  _tile_matrix = (tile**)calloc(_num_tiles_x,sizeof(tile));
  for(int x=0;x<_num_tiles_x;++x) {
    _tile_matrix[x] = (tile*)calloc(_num_tiles_y,sizeof(tile));
  }

  for(int x=0; x<_num_tiles_x; ++x) {
    for(int y=0;y<_num_tiles_y; ++y) {

      int pos_x = tile_diameter * x +1; 
      int pos_y = tile_diameter * y +1;
      tile *t = new tile(25,pos_x,pos_y,1,x,y);
      memcpy(&(_tile_matrix[x][y]),t,sizeof(tile));
    }
  }
}
