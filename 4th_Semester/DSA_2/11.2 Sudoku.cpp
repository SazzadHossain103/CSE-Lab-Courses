#include <bits/stdc++.h>
using namespace std;

bool sudoku_check(int sudoku[9][9],int x,int  y,int v){
    for(int i=0;i<9;i++){
        if(sudoku[i][y]==v)return false;
    }
    for(int i=0;i<9;i++){
        if(sudoku[x][i]==v)return false;
    }

    int x1=x-x%3;
    int y1=y-y%3;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(sudoku[x1+i][y1+j]==v)return false;
        }
    }
    return true;
}


bool sudoku_solve(int sudoku[9][9],int x,int y){
    if(x==8 && y>8)return 1;
    if(y==9){
        x++;
        y=0;
    }

    if(sudoku[x][y]>0)return sudoku_solve(sudoku,x,y+1);
    for(int i=1;i<=9;i++){
        if(sudoku_check(sudoku,x,y,i)){
            sudoku[x][y]=i;
            if(sudoku_solve(sudoku,x,y+1))return true;
        }
        sudoku[x][y]=0;
    }
    return false;
}

int main(){

    int sudoku[9][9]={

    { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
    { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
    { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
    { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
    { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
    { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
    { 0, 0, 5, 2, 0, 6, 3, 0, 0 }

    };
    cout<<"Given Sudoku: "<<endl;
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cout<<sudoku[i][j]<<"   ";
        }
        cout<<"\n\n";
    }
    cout<<"Solved Sudoku: "<<endl;
    if(sudoku_solve(sudoku,0,0)){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<sudoku[i][j]<<"   ";
            }
            cout<<"\n\n";
        }
    }else cout<<"NO solution Exist\n";

  return 0;
}

