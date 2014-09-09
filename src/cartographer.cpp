/*
 * =====================================================================================
 *
 *       Filename:  cartographer.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/09/2014 18:43:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include "cartographer.h"

using namespace std;

std::list<node>* cartographer::get_surrounding_nodes(node *target,tilemap *tile_map) {
  std::list<node> *node_list = new std::list<node>();
  return node_list;
}
std::list<tile*>* cartographer::generate_path(sf::Vector2i start, sf::Vector2i end, tilemap *tile_map) {

  std::list<tile*> *output_path = new std::list<tile*>();  

  std::list<node> open_list;
  std::list<node> closed_list;

  //The parent node is null for the start point!
  node start_node(&(tile_map->_tile_matrix[start.x][start.y]),NULL);
  open_list.push_front(start_node);
  //get_surrounding_tiles will only add additional tiles, not the start tile!
  std::list<node> *additional_nodes = get_surrounding_nodes(&start_node,tile_map);
  
  for(int _x = 0; _x < additional_nodes->size(); ++_x) {
    node n = additional_nodes->front();
    open_list.push_back(n);
    additional_nodes->pop_front();
    cout << "Adding neighbour to start node [" << n.this_tile->x << "|" << n.this_tile->y << endl;
  }
  delete additional_nodes;

  
  return output_path;
}
