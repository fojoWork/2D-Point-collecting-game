#include "classes.hpp"
#include <cstdlib>
#include <iostream>

void Movement::move_up() {
    if(cur_pos.y > 0) {
        cur_pos.y--;
    }
}

void Movement::move_down() {
    if(cur_pos.y < 4) {
        cur_pos.y++;
    }
}

void Movement::move_left() {
    if(cur_pos.x > 0) {
        cur_pos.x--;
    }
}

void Movement::move_right() {
    if(cur_pos.x < 4) {
        cur_pos.x++;
    }
}

void Food::generate_food_spawn() {
    pos_x = rand() % 5;
    pos_y = rand() % 5;
}

int points = 0;

void Map::display_grid(Food &food, Movement &movement) {
    
    const Movement::Position& p_pos = movement.get_cur_pos();
    int food_x = food.get_x();
    int food_y = food.get_y();
    
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            
            if (i == p_pos.y && j == p_pos.x) {
                std::cout << "+ ";
                
                if (p_pos.y == food_y && p_pos.x == food_x) {
                    food.generate_food_spawn();
                    points++;
                }
            }
            
            else if (i == food_y && j == food_x) {
                std::cout << "* ";
            }
            
            else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
        
    }
    
    std::cout << "Points: " << points;
}