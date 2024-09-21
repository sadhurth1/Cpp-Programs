/*Question : A Mars rover is directed to move within a square matrix. It accepts a sequence of commands to move in any of the four directions from each cell: [UP, DOWN, LEFT or RIGHT]. The rover starts from cell 0. and may not move diagonally or outside of the boundary.

Each cell in the matrix has a position equal to:
(row * size) + column
where row and column are zero-indexed, size = row length of the matrix.

Return the final position of the rover after all moves.

Example
n = 4
commands = [RIGHT, UP, DOWN, LEFT, DOWN, DOWN]

The rover path is shown below.

0	1	2	3
4	5 	6 	7
8 	9 	10 	11
12 	13 	14 	15

RIGHT: Rover moves to position 1
UP: Position unchanged, as the move would take the rover out of the boundary.
DOWN: Rover moves to Position 5.
LEFT: Rover moves to position 4
DOWN: Rover moves to position 8
DOWN: The rover ends up in position 12.

The function returns 12.
*/

//SOLUTION:
// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
#include<vector>
#include <unordered_map>
using namespace std;

int finalCells(int size, vector<string> arr)
{
    unordered_map<string,pair<int,int>> dir;
    dir["LEFT"]={-1,0};
    dir["RIGHT"]={1,0};
    dir["UP"]={0,-1};
    dir["DOWN"]={0,1};
    
    int cx=0,cy=0;
    for(auto cmd: arr )
    {
        int x=dir[cmd].first;
        int y=dir[cmd].second;
        
        int nx=x+cx;
        int ny=y+cy;
        if (nx<0 || nx>=size || ny<0 || ny>=size)
        continue;
        cx=nx;
        cy=ny;
    }
    return cy*size+cx;
}


int main() {
    // Write C++ code here
    vector<string> arr{ "RIGHT", "UP", "DOWN", "LEFT", "DOWN", "DOWN"};

    cout << finalCells(4, arr) << endl;
    return 0;
}
