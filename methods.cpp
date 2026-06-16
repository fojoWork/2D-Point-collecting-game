#include "classes.hpp"
#include <cstdlib>
#include <iostream>

void Movement::move_up() {
    if(cur_pos[1] > 0) {
        cur_pos[1]--;
    }
}

void Movement::move_down() {
    if(cur_pos[1] < 4) {
        cur_pos[1]++;
    }
}

void Movement::move_left() {
    if(cur_pos[0] > 0) {
        cur_pos[0]--;
    }
}

void Movement::move_right() {
    if(cur_pos[0] < 4) {
        cur_pos[0]++;
    }
}

void Food::generate_food_spawn() {
    pos_x = rand() % 5;
    pos_y = rand() % 5;
}

int points = 0;

void Map::display_grid(Food &food, Movement &movement) {
    
    std::vector<int> p_pos = movement.get_cur_pos();
    int food_x = food.get_x();
    int food_y = food.get_y();
    
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            
            if (i == p_pos[1] && j == p_pos[0]) {
                std::cout << "+ ";
                
                if (p_pos[1] == food_y && p_pos[0] == food_x) {
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