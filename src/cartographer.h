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
    node(tile *t,node *p) {
      this_tile = t;
      this_parent = p ? p : NULL;
    }
    tile *this_tile;
    node *this_parent;
};



class cartographer {
  public:
    cartographer();
    std::list<tile*>* generate_path(sf::Vector2i start, sf::Vector2i end, tilemap *tile_map);
  private:
    std::list<tile*>*generate_output_path(node *target);
    std::list<node*>* get_surrounding_nodes(node *target,tilemap *tile_map,std::list<node*>*closed_list);
    void add_surrounding_nodes_to_list(node *target, tilemap *tile_map, std::list<node*>*list,std::list<node*>*closed_list);
    std::list<node*>::iterator find_node_in_list(std::list<node*>*list,node *start_node);
    bool node_exists_in_list(std::list<node*>*list,node *start_node);
    void delete_node_from_list(std::list<node*>*list,node *node);
    int estimate_manhatton_distance(node *a, node *b);
    int estimate_movement_cost(node *a, node *b);
    std::list<node*>::iterator find_lowest_cost_node(std::list<node*>*list,node *end_node);
    int _diagonal_cost;
    int _lateral_cost;
};

#endif
