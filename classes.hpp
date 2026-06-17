#include <vector>

class Movement;
class Food;
class Map;

class Movement {
  public:
      struct Position {
          int x;
          int y;
      };
  protected: 
      Position cur_pos = {2,2};
  public:
      const Position& get_cur_pos() const { return cur_pos; }
      void move_up();
      void move_down();
      void move_left();
      void move_right();
};

class Map {
  protected:
      std::vector<std::vector<int>> grid{5, std::vector<int>(5,0)};
  public:
      void display_grid(Food &food, Movement &movement);
};

class Food {
   private:
     int pos_x;
     int pos_y;
   public:

       Food() {
           generate_food_spawn();
       }
       void generate_food_spawn();
       int get_x() {return pos_x;}
       int get_y() {return pos_y;}
};