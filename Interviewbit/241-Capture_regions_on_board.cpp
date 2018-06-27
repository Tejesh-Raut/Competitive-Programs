/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

*/

void mark(vector<vector<char> > &A, int x, int y){
    int n = A.size();
    int m = A[0].size();
    A[x][y]='Y';
    if(x>0){
        if(A[x-1][y]=='O'){
            mark(A, x-1,y);
        }
    }
    if(x<(n-1)){
        if(A[x+1][y]=='O'){
            mark(A,x+1,y);
        }
    }
    if(y>0){
        if(A[x][y-1]=='O'){
            mark(A,x,y-1);
        }
    }
    if(y<(m-1)){
        if(A[x][y+1]=='O'){
            mark(A,x,y+1);
        }
    }
    return;
}
void Solution::solve(vector<vector<char> > &A) {
    int n = A.size();
    if(n==0){
        return ;
    }
    int m = A[0].size();
    for(int i=0; i<m; i++){
        if(A[0][i]=='O'){
            mark(A,0,i);
        }
        if(A[n-1][i]=='O'){
            mark(A,(n-1), i);
        }
    }
    for(int i=0; i<n; i++){
        if(A[i][0]=='O'){
            mark(A,i,0);
        }
        if(A[i][m-1]=='O'){
            mark(A,i,(m-1));
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j]!='Y'){
                A[i][j] = 'X';
            }
            else{
                A[i][j] = 'O';
            }
        }
    }
    return;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
