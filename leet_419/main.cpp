#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>

using namespace std;

#define BATTLEFIELD_FILE "battlefield.txt"

class Solution {
public:
    int countBattleships(vector<vector<char> >& board) {
        int row = board.size();
        int col = board[0].size();
        int count = 0;
        vector<vector<int> > tmp = vector<vector<int> >(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(board[i][j] == 'X') {
                    int ship = belongsTo(tmp, i, j);
                    if (ship == 0) {
                        count ++;
                        tmp[i][j] = count;
                    } else {
                        tmp[i][j] = ship;
                    }
                }
            }
        }
        return count;
    }

    int belongsTo(vector<vector<int> >& tmp, int i, int j) {
        if ((i-1 >= 0) && tmp[i-1][j] > 0) return tmp[i-1][j];
        if ((j-1 >= 0) && tmp[i][j-1] > 0) return tmp[i][j-1];
        return 0;
    }
};

void readBoard(vector<vector<char> >& board) {
    int row, col;
    char c;
    ifstream ifs(BATTLEFIELD_FILE);
    if (!(ifs>>row) || !(ifs>>col))
        return;
    for (int i = 0; i < row; i++) {
        board.push_back(vector<char>());
        for (int j = 0; j < col; j++) {
            ifs>>c;
            board[i].push_back(c);
        }
    }
}

void printBoard(vector<vector<char> >& board) {
    int row = board.size();
    int col = board[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout<<board[i][j];
        }
        cout<<endl;
    }
}

int main() {
    Solution sln;
    vector<vector<char> > board;
    readBoard(board);
    printBoard(board);
    cout<<sln.countBattleships(board)<<endl;
    return 0;
}