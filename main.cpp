#include <chrono>
#include <conio.h>
#include <windows.h>
#include "classes.hpp"
#include <thread>
#include <windows.h>

void hideConsoleCursor() {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; 
    SetConsoleCursorInfo(out, &cursorInfo);
}

extern int points;

int main() {
    bool isactive = true;
    Movement movement;
    Food food;
    Map game;
    
    while(isactive) {
        system("cls");
        hideConsoleCursor();
        game.display_grid(food, movement);
        
        if(_kbhit()) {
            char key = _getch();
            if (key == 'w') movement.move_up();
            if (key == 's') movement.move_down();
            if (key == 'a') movement.move_left();
            if (key == 'd') movement.move_right();
            if (key == 'q') return 0; 
        }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}