 #ifndef __ELEVATOR_H
 #define __ELEVATOR_H 2016
 class Elevator {
   public:
     Elevator() : top_floor(9) {}
     Elevator(int max_floors) : top_floor(max_floors) {}

     class Invalid_floor {}; // Exception
     void goto_floor(int floor);
     void move();

     int get_current_floor();
     int get_desired_floor();
     bool is_going_up();
     bool has_arrived();
     bool is_idle();

   private:
     int top_floor;
     int current_floor = 1;
     int desired_floor = 1;
     bool going_up = true;
     bool idle = false;
 };
 #endif
