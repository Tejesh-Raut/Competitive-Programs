/*
Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.' 
You may assume that there will be only one unique solution.



A sudoku puzzle,



and its solution numbers marked in red.

Example :

For the above given diagrams, the corresponding input to your program will be

[[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], [7...2...6], [.6....28.], [...419..5], [....8..79]]
and we would expect your program to modify the above array of array of characters to

[[534678912], [672195348], [198342567], [859761423], [426853791], [713924856], [961537284], [287419635], [345286179]]

*/

bool findSolution(vector<vector<int> > &soln, int x, int y){
    
    vector<bool> flag(9, true);
    int rows = soln.size();
    int cols = soln[0].size();
    if((x==rows)&&(y==cols)){
        return true;
    }
    // if(x==8){
    //     cout<<"*"<<x<<"*"<<y<<endl;
    // }
    for(int i=0; i<rows; i++){
        if(soln[i][y]!=-1){
            flag[soln[i][y] - 1] = false;
        }
    }
    for(int i=0; i<cols; i++){
        if(soln[x][i]!=-1){
            flag[soln[x][i] - 1] = false;
        }
    }
    
    int x1 = x/3;
    int y1 = y/3;
    x1 = x1*3;
    y1 = y1*3;
    for(int i=x1; i<(x1+3); i++){
        for(int j=y1; j<(y1+3); j++){
            if(soln[i][j]!=-1){
                flag[soln[i][j] - 1] = false;
            }
        }
    }
    
    int i, j;
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            if((soln[i][j]==-1)){
                if((i==x)&&(j==y)){
                    continue;
                }
                break;
            }
        }
        if(j<cols){
            break;
        }
    }
    
    for(int k=0; k<9; k++){
        if(flag[k]){
            soln[x][y] = k+1;
            if(findSolution(soln, i, j)){
                return true;
            }
        }
    }
    soln[x][y] = -1;
    return false;
}
void Solution::solveSudoku(vector<vector<char> > &A) {
    vector<vector<int> > soln;
    int rows = A.size();
    if(rows==0){
        return ;
    }
    int cols = A[0].size();
    for(int i=0; i<rows; i++){
        vector<int> temp(cols, -1);
        for(int j=0; j<cols; j++){
            if(A[i][j]!='.'){
                temp[j] = A[i][j]- '0';
            }
        }
        soln.push_back(temp);
    }
    int i, j;
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            if(soln[i][j]==-1){
                break;
            }
        }
        if(j<cols){
            break;
        }
    }
    if(findSolution(soln, i, j)){
        for(i=0; i<rows; i++){
            for(j=0; j<cols; j++){
                if(A[i][j]=='.'){
                    A[i][j] = '0' + soln[i][j];
                    // cout<<soln[i][j]<<" ";
                }
            }
            // cout<<endl;
        }
    }
    return;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
