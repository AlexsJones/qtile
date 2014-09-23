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


class cartographer_configuration {

  typedef bool (node_conditionality_functor)(node *);

  public: 
  cartographer_configuration(int diagonal_cost = 15, int lateral_cost = 10):_diagonal_cost(diagonal_cost),
  _lateral_cost(lateral_cost),_usr_comparison_function(NULL){
  }
  /* This allows the user to assign a C function to process whether a node should be added to the open list e.g. exclude certain nodes based on height etc.. */
  void add_custom_node_conditionality(node_conditionality_functor *fnctr) {
    _usr_comparison_function = fnctr;
  }
  bool check_conditions_on_node(node *n) {
    if(!_usr_comparison_function) {
      return true;
    }
    return _usr_comparison_function(n);
  }
  int _diagonal_cost;
  int _lateral_cost;
  node_conditionality_functor *_usr_comparison_function; 
};

class cartographer {

  public:
    cartographer(cartographer_configuration *configuration);
    ~cartographer();
    std::list<node*>* generate_path(sf::Vector2i start, sf::Vector2i end, tilemap *tile_map);

  private:
    std::list<node*>*generate_output_path(node *target);
    std::list<node*>* get_surrounding_nodes(node *target,tilemap *tile_map,std::list<node*>*closed_list);
    void add_surrounding_nodes_to_list(node *target, tilemap *tile_map, std::list<node*>*list,std::list<node*>*closed_list);
    std::list<node*>::iterator find_node_in_list(std::list<node*>*list,node *start_node);
    bool node_exists_in_list(std::list<node*>*list,node *start_node);
    void delete_node_from_list(std::list<node*>*list,node *node);
    int estimate_manhatton_distance(node *a, node *b);
    int estimate_movement_cost(node *a, node *b);
    std::list<node*>::iterator find_lowest_cost_node(std::list<node*>*list,node *end_node);
    cartographer_configuration *configuration;
    std::list<node*> *open_list;
    std::list<node*> *closed_list;
    std::list<node*> *output_list;
};

#endif
