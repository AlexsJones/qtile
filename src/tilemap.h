/*
 * =====================================================================================
 *
 *       Filename:  tilemap.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/09/2014 17:04:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __TILEMAP_H__
#define __TILEMAP_H__
#include <SFML/Graphics.hpp>
#include <list>
#include "gameworld.h"

typedef enum STATE { 
UNSELECTED,
START,
PATH,
END,
OBSTRUCTION,
}STATE;

class tile {
  public:
    tile(unsigned int diameter,float x, float y, float weight);
    float x, y, weight;
    unsigned int diameter;
    STATE current_state;
};

class tilemap {
  public:
    tilemap(sf::Vector2u dimension, unsigned int tile_diameter,gameworld *game_world);
    void draw(void);
    void generate_map(void);
    sf::Vector2i nominate_random_start(void);
    sf::Vector2i nominate_random_end(void);
    void generate_noise(void);
    void update_best_path(std::list<tile*> *path);
    tile **_tile_matrix;
  private:
    sf::Vector2i nominate_random(STATE s);
    unsigned int _width;
    unsigned int _height;
    float tile_diameter;
    int _num_tiles_x;
    int _num_tiles_y;
    gameworld *_game_world;

};
#endif
