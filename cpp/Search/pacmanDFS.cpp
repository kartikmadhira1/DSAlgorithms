#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

struct Node{
    int i;
    int j;
    bool visited;
};

vector<vector<string>> splitString(vector<string> grid, int r, int c);
void printBoard(vector<vector<int>> boardBinary,Node pacPos,int r,int c);


void dfs( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> grid) {

    //convert to the 2D string format
    vector<vector<string>> board = splitString(grid, r, c);

    //create a binary of nodes visited and not visited.
    vector<vector<int>> boardBinary(r, vector<int>(c));

    //create a stack
    stack<Node> stackDFS;
    //create a node for starting position
    Node currNode;
    currNode.i = pacman_r;
    currNode.j = pacman_c;
    currNode.visited = false;

    //make the walls of the graph to be visited
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == "%") {
                boardBinary[i][j] = 1;
            }
        }
    }

//    for (int i=0;i<r;i++) {
//        for (int j = 0; j < c; j++) {
//            cout<<boardBinary[i][j];
//        }
//        cout<<"\n";
//    }
//
//    cout<<boardBinary[currNode.i][currNode.j]<<"\n";
//    cout<<board[currNode.i][currNode.j];

    stackDFS.push(currNode);
    boardBinary[pacman_r][pacman_c]=1;
    while(stackDFS.size()!=0) {
        int rr = currNode.i;
        int cc = currNode.j;
        Node tempNode = currNode;
        if (boardBinary[tempNode.i + 1][tempNode.j] == 0) {
            //push this new node into the stack
            boardBinary[tempNode.i + 1][tempNode.j] = 1;
            Node newAdd = tempNode;
            newAdd.i = tempNode.i + 1;
            stackDFS.push(newAdd);
            currNode = stackDFS.top();
        } else if (boardBinary[tempNode.i][tempNode.j + 1] == 0) {
            boardBinary[tempNode.i][tempNode.j + 1] = 1;
            Node newAdd = tempNode;
            newAdd.j = tempNode.j + 1;
            stackDFS.push(newAdd);
            currNode = stackDFS.top();
        } else if (boardBinary[tempNode.i][tempNode.j - 1] == 0) {
            boardBinary[tempNode.i][tempNode.j - 1] = 1;
            Node newAdd = tempNode;
            newAdd.j = tempNode.j - 1;
            stackDFS.push(newAdd);
            currNode = stackDFS.top();
        } else if (boardBinary[tempNode.i - 1][tempNode.j] == 0) {
            boardBinary[tempNode.i - 1][tempNode.j] = 1;
            Node newAdd = tempNode;
            newAdd.i = tempNode.i - 1;
            stackDFS.push(newAdd);
            currNode = stackDFS.top();
        }
        if ((currNode.i == food_r) && (currNode.j == food_c)) {
            break;
        }
        if ((boardBinary[currNode.i][currNode.j + 1] != 0) && (boardBinary[currNode.i][currNode.j - 1] != 0) &&
            (boardBinary[currNode.i + 1][currNode.j] != 0) && (boardBinary[currNode.i - 1][currNode.j] != 0)) {
            currNode.visited = true;
            boardBinary[currNode.i][currNode.j] = 1;
            stackDFS.pop();
            currNode = stackDFS.top();
            boardBinary[currNode.i][currNode.j] = 0;
        }
        // printBoard(boardBinary,currNode,r,c);
    }
    stack<Node> reverseStack;
    cout<<stackDFS.size()<<"\n";
    while(stackDFS.size()!=0){
        Node temp=stackDFS.top();
        reverseStack.push(temp);
        stackDFS.pop();
    }

    while(reverseStack.size()!=0){
        Node temp=reverseStack.top();
        cout<<temp.i<<" "<<temp.j<<"\n";
        reverseStack.pop();
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

    dfs( r, c, pacman_r, pacman_c, food_r, food_c, grid);

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

void printBoard(vector<vector<int>> boardBinary, Node pacPos,int r,int c) {

    for (int i=0;i<r;i++) {
        for (int j = 0; j < c; j++) {
            if((i==pacPos.i) && (j==pacPos.j)){
                cout<<"P";
            }
            else if (boardBinary[i][j] == 1) {
                cout<<"%";
            }
            else if(boardBinary[i][j] == 0){
                cout<<"-";
            }
        }
        cout<<"\n";
    }
}

