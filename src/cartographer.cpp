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

std::list<node*>* cartographer::get_surrounding_nodes(node *target,tilemap *tile_map) {

  std::list<node*> *node_list = new std::list<node*>();
  sf::Vector2i start = sf::Vector2i(target->this_tile->grid_x,target->this_tile->grid_y);

  int offset_x[3] = { start.x -1,start.x, start.x + 1 };
  int offset_y[3] = { start.y - 1,start.y, start.y + 1 };

  for(int x=0;x<3; ++x) {
    for(int y=0;y<3; ++y) {

      if(offset_x[x] < 0 || offset_y[y] < 0) {
        continue;
      }
      if(offset_x[x] > tile_map->_num_tiles_x || offset_y[y] > tile_map->_num_tiles_y) {
        continue;
      }
      tile *current_neighbour = &(tile_map->_tile_matrix[offset_x[x]][offset_y[y]]);

      if(current_neighbour != target->this_tile) {

        if(current_neighbour->current_state != OBSTRUCTION ) {
          node *adding_neighbour = new node(current_neighbour,target);
          node_list->push_back(adding_neighbour);  
        }

      }
    }
  }
  return node_list;
}
std::list<node*>::iterator cartographer::find_node_in_list(std::list<node*>*list, node *start_node) {

  std::list<node*>::iterator i;
  for(i = list->begin(); i != list->end(); ++i) {
    if((*i)->this_tile->grid_x ==  start_node->this_tile->grid_x  &&  
        (*i)->this_tile->grid_y == start_node->this_tile->grid_y) {
      cout << "Found node in list... sending up for deletion" << endl;
      return i;
    }
  }
  return i;
}
void cartographer::delete_node_from_list(std::list<node*>*list,node *node) {

}
int cartographer::estimate_manhatton_distance(node *a, node *b) {
  sf::Vector2i start = sf::Vector2i(a->this_tile->grid_x,a->this_tile->grid_y);
  sf::Vector2i end = sf::Vector2i(b->this_tile->grid_x,b->this_tile->grid_y);

  int offset_x = 0;
  if(start.x > end.x) {
    offset_x = start.x - end.x;
  }else {
    offset_x = end.x - start.x;
  }
  int offset_y = 0;
  if(start.y > end.y) {
    offset_y = start.y - end.y;
  }else {
    offset_y = end.y - start.y;
  }
  return (offset_x + offset_y) * 10;
}
int cartographer::estimate_movement_cost(node *a, node *b) {

  bool is_diagonal = false;
  int offset_x[4] = { a->this_tile->grid_x -1, a->this_tile->grid_x -1, a->this_tile->grid_x +1, a->this_tile->grid_x + 1};
  int offset_y[4] = { a->this_tile->grid_y -1, a->this_tile->grid_y +1, a->this_tile->grid_y +1, a->this_tile->grid_y - 1};

  for(int x=0;x<4;++x) {    // broken ???
    if(b->this_tile->grid_x == offset_x[x] && b->this_tile->grid_y == offset_y[x]) {
      cout << "Node ["<< b->this_tile->grid_x << ":" << b->this_tile->grid_x << "] is diagonal from " << a->this_tile->grid_x << ":" << a->this_tile->grid_y << endl;
      is_diagonal = true;
    }else {
      cout << "Node ["<< b->this_tile->grid_x << ":" << b->this_tile->grid_x << "] is not diagonal from " << a->this_tile->grid_x << ":" << a->this_tile->grid_y << endl;
    }
  }
  return is_diagonal ? _diagonal_cost : _lateral_cost;
}
std::list<node*>::iterator cartographer::find_lowest_cost_node(std::list<node*>*list,node *end_node) {
  std::list<node*>::iterator it;
  std::list<node*>::iterator lowest_it;
  int cheapest_thus_far = 1;
  for(it = list->begin(); it != list->end(); ++it) {
    node *current = *it;

    int cost = estimate_movement_cost(current,end_node) + estimate_manhatton_distance(current,end_node);
    cout << "Estimated cost of movement " << cost << " of node [" << current->this_tile->grid_x << "| " << current->this_tile->grid_y << " to [" << end_node->this_tile->grid_x << "|" << end_node->this_tile->grid_y << "]"<< endl;

    if(cheapest_thus_far == -1) {
      cheapest_thus_far = cost;
      lowest_it = it;
      continue;
    }
    if(cost < cheapest_thus_far) {
      cheapest_thus_far = cost;
      lowest_it = it;
    }
  }
  return lowest_it;
}
std::list<tile*>* cartographer::generate_path(sf::Vector2i start, sf::Vector2i end, tilemap *tile_map) {

  std::list<tile*> *output_path = new std::list<tile*>();  

  std::list<node*> *open_list = new std::list<node*>();
  std::list<node*> *closed_list = new std::list<node*>();

  //objective
  node *end_node = new node(&(tile_map->_tile_matrix[end.x][end.y]),NULL);
  //The parent node is null for the start point!
  node *start_node = new node(&(tile_map->_tile_matrix[start.x][start.y]),NULL);

  open_list->push_front(start_node);
  //get_surrounding_tiles will only add additional tiles, not the start tile!
  std::list<node*> *additional_nodes = get_surrounding_nodes(start_node,tile_map);
  int an_len = additional_nodes->size();

  for(int _x = 0; _x < an_len; ++_x) {
    node *n = additional_nodes->front();
    open_list->push_back(n);
    additional_nodes->pop_front();
    cout << "Adding neighbour to start node [" << n->this_tile->grid_x << "|" << n->this_tile->grid_y << "]" << endl;
  }
  delete additional_nodes;

  //drop A from the list for now
  open_list->erase(find_node_in_list(open_list,start_node));

  //look at the current list without the start_tile and  
//  std::list<node>::iterator it = find_lowest_cost_node(&open_list,&end_node);


  return output_path;
}
cartographer::cartographer():_diagonal_cost(15),_lateral_cost(10) {

}
