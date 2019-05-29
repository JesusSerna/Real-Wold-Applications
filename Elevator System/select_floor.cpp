 #include "select_floor.h"
 #include "std_lib_facilities.h"
 #include "globals.h"
 #include "elevator.h"

 int select_floor(Elevator elevator, Vector<int> request) { 
   //
   // Determine the next stop for this elevator
   //
   int direction = elevator.is_going_up() ? 1 : -1;
   int floor = elevator.get_current_floor(); 

   // We scan each approach floor in the current direction for a non-filled request
   for (int floors = 0; floors < max_floor; ++floors) {
     floor += direction;

     // If we reach the end in one direction, scan in the opposite direction
     if (floor < 0 || floor > max_floor) {
        direction = -direction;
        floor = elevator.get_current_floor() + direction;
     }

     // If a request exists for this floor, schedule it and exit
     if (request[floor] == TRUE) {
         return floor;
     }
   }
   return -1;
 }