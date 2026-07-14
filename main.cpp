#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <ctime>


struct Food {
  int x;
  int y;
};

void generate_food_spawn(Food &food) {
  food.x = rand() % 5;
  food.y = rand() % 5;
}

void display_grid(int x, int y, Food &food) {
  std::cout << "\033[H\033[2J"; 
  
  for (size_t i{}; i < 5; i++) {
    for (size_t j{}; j < 5; j++) {
      if (j == x && i == y) {
        std::cout << "+ ";
      }
      else if (j == food.x && i == food.y) {
        std::cout << "* ";
      }
      else {
        std::cout << ". ";
      }
    }
    std::cout << "\n";
  }
}

int main() {
  srand(time(NULL));
  
  Food food = {0, 0};
  generate_food_spawn(food);
  
  bool active = true;
  int player_x = 2, player_y = 2;


  void (*display)(int, int, Food&) = display_grid;

  display(player_x, player_y, food);

  while(active) {
    if(_kbhit()) {
      char key = _getch();

      if(key == 'w' && player_y > 0) player_y--;
      if(key == 's' && player_y < 4) player_y++;
      if(key == 'a' && player_x > 0) player_x--;
      if(key == 'd' && player_x < 4) player_x++;
      if(key == 'q') active = false;

      // 3. Check if player stepped on the food!
      if (player_x == food.x && player_y == food.y) {
          generate_food_spawn(food);
      }

      display(player_x, player_y, food);
    }
  }
  return 0;
}