#pragma once
#include <cassert>
#include <cstdlib>
#include <iostream>


class Board{
    int N;
    int **grid;
    bool **immutable;
    bool **infeasible;

public:

 
    Board(int _N) : N(_N){


        grid = new int*[N];
        for(int i = 0; i < N; i++){
            grid[i] = new int[N];
        }
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                grid[i][j] = 0;

      
        immutable = new bool*[N];
        for(int i = 0; i < N; i++){
            immutable[i] = new bool[N];
        }

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                immutable[i][j] = true;

       
        infeasible = new bool*[N];
        for(int i = 0; i < N; i++){
            infeasible[i] = new bool[N];
        }

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                infeasible[i][j] = false;

    }

   
    ~Board(){
        for(int i = 0; i < N; i++){
            delete [] grid[i];
        }
        delete [] grid;

        for(int i = 0; i < N; i++){
            delete [] immutable[i];
        }
        delete [] immutable;

        for(int i = 0; i < N; i++){
            delete [] infeasible[i];
        }
        delete [] infeasible;
    }

    void printPuzzle(); 
    bool checkPuzzle(); 
    void clearPuzzle(); 
    bool inBounds(int val); 
    bool feasibleUser(int row, int col, int val);

   
    int& operator() (int x, int y){
        assert(x < N && y < N);
        return grid[x][y];
    }

    
    void assignValue(int x, int y, int val){
        (*this)(x,y) = val;
    }

   
    void assignImmutable(int x, int y, bool val){
        immutable[x][y] = val;
    }

   
    bool checkImmutable(int x, int y){
        return immutable[x][y];
    }

   
    bool isProblem(int x, int y){
        return infeasible[x][y];
    }


    int getSize(){
        return N;
    }

    
    void setFromArray(int a[4][4]){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                grid[i][j] = a[i][j];
    }

};

bool feasible(Board &b, int row, int col, int val);
bool solve(Board &b, int row, int col);
int* genPerm(int N);
Board generatePuzzle(int n, int nobs);
