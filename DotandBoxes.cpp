
//includes
#include "grid.h"
#include <iostream>

//Helper functions: you may use them as a template.

// Check if no more tokens can be placed
bool isGridFull() {
    for (int row = 0; row < 2; ++row) {
        for (int col = 0; col < 2; ++col) {
            if (grid.fields(row, col) == ' ') {
                return false;
            }
        }
    }
    return true;
}

//Place a vertical or horizontal line, depending on direction
void drawLine(int row, int col, char direction) {
  
  //input row , cole , direction
  //horizontal
  if(row == 0 && col == 0 && direction == 'r' || row == 0 && col == 1 && direction == 'l')
  {
    grid.horizontal(0,0) = true;
  }
  if(row == 1 && col == 0 && direction == 'r' || row == 1 && col == 1 && direction == 'l')
  {
    grid.horizontal(1,0) = true;
  }
  if(row == 2 && col == 0 && direction == 'r' || row == 2 && col == 1 && direction == 'l')
  {
    grid.horizontal(2,0) = true;
  }
  if(row == 0 && col == 1 && direction == 'r' || row == 0 && col == 2 && direction == 'l')
  {
    grid.horizontal(0,1) = true;
  }
  if(row == 1 && col == 1 && direction == 'r' || row == 1 && col == 2&& direction == 'l')
  {
    grid.horizontal(1,1) = true;
  }
  if(row == 2 && col == 1 && direction == 'r' || row == 2 && col == 2 && direction == 'l' )
  {
    grid.horizontal(2,1) = true;
  }
  
  // vertical
  if(row == 0 && col == 0 && direction == 'd' || row == 1 && col == 0 && direction == 'u')
  {
    grid.vertical(0,0) = true;
  }
  if(row == 1 && col == 0 && direction == 'd' || row == 2 && col == 0 && direction == 'u')
  {
    grid.vertical(1,0) = true;
  }
  if(row == 0 && col == 1 && direction == 'd' || row == 1 && col == 1 && direction == 'u')
  {
    grid.vertical(0,1) = true;
  }
  if(row == 1 && col == 1 && direction == 'd' || row == 2 && col == 1 && direction == 'u')
  {
    grid.vertical(1,1) = true;
  }
  if(row == 0 && col == 2 && direction == 'd' || row == 1 && col == 2 && direction == 'u')
  {
    grid.vertical(0,2) = true;
  }
  if(row == 1 && col == 2 && direction == 'd' || row == 2 && col == 2 && direction == 'u')
  {
    grid.vertical(1,2) = true;
  }
  
  //Fehlermeldung
  if(row<=0 || row>=2 || col<=0 || col>=2 || direction !='r' || direction !='l' || direction !='u' || direction !='d')
  {
    std::cout << "Invalid move \n";
  }
  
  if(row == 0 || col == 0 || direction !='l' || direction !='u')
  {
    std::cout << "Invalid move \n";
  }
  
  //outoput soll eine lininie sein
  
}

//Does adding a line result in drawing an unclaimed box?
bool shouldPlaceToken(int row, int col) {
  if(grid.horizontal(0,0) && grid.horizontal(1,0) && grid.vertical(0,0) && grid.vertical(0,1) && grid.fields(0,0) == ' ')
  {
    return true;
  }
  
  if(grid.horizontal(1,0) && grid.horizontal(2,0) && grid.vertical(1,0) && grid.vertical(1,1) && grid.fields(1,0) == ' ')
  {
    return true;
  }
  
  if(grid.horizontal(0,1) && grid.horizontal(0,2) && grid.vertical(0,1) && grid.vertical(1,1) && grid.fields(0,1) == ' ')
  {
    return true;
  }
  
  if(grid.horizontal(1,1) && grid.horizontal(2,1) && grid.vertical(1,1) && grid.vertical(1,2) && grid.fields(1,1) == ' ')
  {
    return true;
  }
  
}

int main() {
  int row,col;
  char direction;
  
  grid.printGrid(); 
  
while(1)
{
  std::cin >> row >> col >> direction;
  drawLine(row,col,direction);
  
/*  if(shouldPlaceToken(row,col))         //abfrageb on token plazieren
  {
                          //plaziere token
                          //invertiere den speielr nocheinmal damit der gleiche spieler wieder dran ist.
  }
*/  
  // Feature-Demo: Print the grid.
  grid.printGrid();  
  
                                            // if() spiler invertieren A -> B -> A etc.

}
  return 0;
}
