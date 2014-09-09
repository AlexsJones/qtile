/*
 * =====================================================================================
 *
 *       Filename:  cartographer.h
 *
 *    Description
 *
 *        Version:  1.0
 *        Created:  08/09/2014 18:42:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __CARTOGRAPHER_H__
#define __CARTOGRAPHER_H__
#include <list>
#include "tilemap.h"

class node {
  public:
    node(tile *t,tile *p) {
      this_tile = t;
      this_parent = p ? p : NULL;
    }
  tile *this_tile;
  tile *this_parent;
};

class cartographer {
  public:
  std::list<tile*>* generate_path(sf::Vector2i start, sf::Vector2i end, tilemap *tile_map);
  private:
  std::list<node>* get_surrounding_nodes(node *target,tilemap *tile_map);
};

#endif
