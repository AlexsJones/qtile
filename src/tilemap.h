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
PATHCONFIRMED,
PATHFINDING,
OBSTRUCTION,
}STATE;

class tile {
  public:
    tile(unsigned int diameter,float x, float y, float weight, int grid_x, int grid_y);
    float x, y, weight;
    int grid_x,grid_y;
    unsigned int diameter;
    STATE current_state;
};

class tilemap {
  public:
    tilemap(unsigned int tile_diameter,gameworld *game_world,int noise_factor);
    void draw(void);
    void generate_map(void);
    sf::Vector2i nominate_random_start(void);
    sf::Vector2i nominate_random_end(void);
    void generate_noise(void);
    void update_best_path(std::list<tile*> *path);
    tile **_tile_matrix;
    int _num_tiles_x;
    int _num_tiles_y;
  private:
    sf::Vector2i nominate_random(STATE s);
    unsigned int _width;
    unsigned int _height;
    float tile_diameter;
    gameworld *_game_world;
    int _noise_factor;

};
#endif
