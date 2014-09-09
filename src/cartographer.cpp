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
  sf::Vector2i start = sf::Vector2i(target->this_tile->grid_x,target->this_tile->grid_y);

  const int offset_x[3] = { start.x -1,start.x, start.x + 1 };
  const int offset_y[3] = { start.y - 1,start.y, start.y + 1 };

  for(int x=0;x<3; ++x) {
    for(int y=0;y<3; ++y) {
      
      tile *current_neighbour = &(tile_map->_tile_matrix[offset_x[x]][offset_y[y]]);
     
      if(current_neighbour != target->this_tile) {
        
        if(current_neighbour->current_state != OBSTRUCTION ) {
          node adding_neighbour(current_neighbour,target);
          node_list->push_back(adding_neighbour);  
        }
     
      }
    }
  }
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
  int an_len = additional_nodes->size();

  for(int _x = 0; _x < an_len; ++_x) {
    node n = additional_nodes->front();
    open_list.push_back(n);
    additional_nodes->pop_front();
    cout << "Adding neighbour to start node [" << n.this_tile->grid_x << "|" << n.this_tile->grid_y << "]" << endl;
  }
  delete additional_nodes;


  return output_path;
}
