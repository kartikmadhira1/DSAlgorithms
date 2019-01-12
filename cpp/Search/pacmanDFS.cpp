#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;
vector<vector<string>> splitString(vector<string> grid, int r, int c);

struct Node{
    int i;
    int j;
};

void dfs( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> grid){

    //convert to the 2D string format
    vector<vector<string>> board = splitString(grid, r, c);

    //create a binary of nodes visited and not visited.
    vector<vector<int>> boardBinary(r,vector<int>(c));

    //create a stack
    stack<Node> stackDFS;
    //create a node for starting position
    Node currNode;
    currNode.i=pacman_r;
    currNode.j=pacman_c;

    //make the walls of the graph to be visited
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            if(board[i][j]=="%"){
                boardBinary[i][j]=1;
            }        
        }
    }

    
    if((boardBinary[currNode.i][currNode.j+1]==0) ||  (boardBinary[currNode.i][currNode.j-1]==0) || (boardBinary[currNode.i+1][currNode.j]==0) || (boardBinary[currNode.i-1][currNode.j]==0))
    {

    }
}

int main(void) {

    int r,c, pacman_r, pacman_c, food_r, food_c;

    cin >> pacman_r >> pacman_c;
    cin >> food_r >> food_c;
    cin >> r >> c;

    vector <string> grid;

    for(int i=0; i<r; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    //dfs( r, c, pacman_r, pacman_c, food_r, food_c, grid);
    vector<vector<string>> ff = splitString(grid, r, c);
    for (int i=0;i<r;i++) {
        for (int j = 0; j < c; j++) {
            cout<<ff[i][j];
        }
        cout<<"\n";
    }
}


vector<vector<string>> splitString(vector<string> grid, int r, int c) {
    vector<vector<string>> grid2D(r,std::vector<string>(c));
    for (int i=0;i<r;i++) {
        string temp=grid[i];
        for (int j = 0; j < c; j++) {
            grid2D[i][j]=temp[j];
        }
    }
    return grid2D;
}
