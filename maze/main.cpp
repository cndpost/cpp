#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <iostream>
using namespace std;

const int width =20;
const int height =20;

bool maze[width][height];// = new bool[width][height]; // The maze
bool wasHere[width][height];// = new bool[width][height];
bool correctPath[width][height];// = new bool[width][height]; // The solution to the maze
int startX, startY; // Starting X and Y values of maze
int endX, endY;     // Ending X and Y values of maze

void generateMaze()
{
    //bool m[][] = new bool[width][height];
    for (int i=0; i< width; i++) {
        for (int j=0;j< height; j++){
            int c = std::rand();
            if (c % 5 == 0)
              maze[i][j] = true;
            else 
              maze[i][j] =  false; 
        }
    }
};



bool recursiveSolve(int x, int y) {
    if (x == endX && y == endY) return true; // If you reached the end
    if (maze[x][y] || wasHere[x][y]) return false;
    // If you are on a wall or already were here
    wasHere[x][y] = true;
    if (x != 0) // Checks if not on left edge
        if (recursiveSolve(x-1, y)) { // Recalls method one to the left
            correctPath[x][y] = true; // Sets that path value to true;
            return true;
        }
    if (x != width - 1) // Checks if not on right edge
        if (recursiveSolve(x+1, y)) { // Recalls method one to the right
            correctPath[x][y] = true;
            return true;
        }
    if (y != 0)  // Checks if not on top edge
        if (recursiveSolve(x, y-1)) { // Recalls method one up
            correctPath[x][y] = true;
            return true;
        }
    if (y != height - 1) // Checks if not on bottom edge
        if (recursiveSolve(x, y+1)) { // Recalls method one down
            correctPath[x][y] = true;
            return true;
        }
    return false;
};

bool solveMaze() {
    generateMaze(); // Create Maze (false = path, true = wall)
    for (int row = 0; row < height; row++)  
        // Sets boolean Arrays to default values
        for (int col = 0; col < width; col++){
            wasHere[row][col] = false;
            correctPath[row][col] = false;
        }
    bool b = recursiveSolve(startX, startY);
    // Will leave you with a boolean array (correctPath) 
    // with the path indicated by true values.
    // If b is false, there is no solution to the maze
};

int main()
{
   startX =0;
   startY =0;
   endX = 19;
   endY = 19;

    if (solveMaze()) {
     cout << "Solved " << std::endl;
     for (int i=0; i<width; i++) {
         for (int j=0; j< height; j++) {
             cout << " " << maze[i][j] << " "  ;
         };
         cout << endl;
     }

     int step =0;
     cout << "path is " << std::endl;
     for (int i=0; i<width; i++) {
         for (int j=0; j< height; j++) {
             if (correctPath[i][j]) {
              cout << " " << "*" << " " ;
             }
             else 
              cout << "   ";
         };
         cout << endl;
     }
    }
    else 
     cout << "No path exist"  << std::endl;
}