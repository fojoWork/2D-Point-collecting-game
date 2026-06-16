#include <chrono>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include "classes.hpp"
#include <thread>
#include <iostream>

extern int points;

int main() {

    double time_limit = 1.5;
    auto start_time = std::chrono::steady_clock::now();

    bool isactive = true;
    Movement movement;
    Food food;
    Map game;
    
    while(isactive) {
        system("cls");

        auto cur_time = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed = cur_time - start_time;
        double time_left = time_limit - elapsed.count();

        if (time_left <= 0) {
                    isactive = false;
                    system("cls");
                    std::cout << "Final Score: " << points << " points" << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    system("pause");
                    break;
                }

        game.display_grid(food, movement, start_time, time_left);
        
        if(_kbhit()) {
            char key = _getch();
            if (key == 'w') movement.move_up();
            if (key == 's') movement.move_down();
            if (key == 'a') movement.move_left();
            if (key == 'd') movement.move_right();
            if (key == 'q') isactive = false; 
        }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    return 0;
}