/// Backtracking: N-Queen Problem

#include <iostream>

using namespace std;

int board[100][100], N;

int validQueen(int row, int col){
    // Check to the left
    for(int j=col-1;j>=0;j--){
        if(board[row][j]==1)
            return 0;
    }
    // Upper diagonal
    int i=row-1, j=col-1;
    while(i>=0 && j>=0){
        if(board[i][j]==1)
            return 0;
        i--;
        j--;
    }
    // Lower diagonal
    i=row+1, j=col-1;
    while(i<N && j>=0){
        if(board[i][j]==1)
            return 0;
        i++;
        j--;
    }

    return 1;
}

int placeQueen(int col){
    if(col==N)
        return 1;

    for(int row=0;row<N;row++){
        if(validQueen(row, col)){
            board[row][col] = 1;
            if(placeQueen(col+1))
                return 1;
            board[row][col] = 0;
        }
    }

    return 0;
}

int main(){
    cin >> N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j] = 0;
        }
    }

    board[0][0] = 1;
    board[2][1] = 1;

    if(placeQueen(0)){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "There is no solution";
    }


}
