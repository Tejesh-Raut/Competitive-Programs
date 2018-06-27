/*
Given N * M field of O's and X's, where O=white, X=black
Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)

Example:

OOOXOOO
OOXXOXO
OXOOOXO

answer is 3 shapes are  :
(i)    X
     X X
(ii)
      X
 (iii)
      X
      X
Note that we are looking for connected shapes here.

For example,

XXX
XXX
XXX
is just one single connected black shape.


*/

void mark(vector<string> &A, int x, int y){
    A[x][y] = 'O';
    if(x>0){
        if(A[x-1][y] == 'X'){
            mark(A, (x-1), y);
        }
    }
    if(y>0){
        if(A[x][y-1] == 'X'){
            mark(A, x, (y-1));
        }
    }
    if(x<(A.size()-1)){
        if(A[x+1][y] == 'X'){
            mark(A, (x+1), y);
        }
    }
    if(y<(A[0].length() - 1)){
        if(A[x][y+1] == 'X'){
            mark(A, x, (y+1));
        }
    }
    return;
}
int Solution::black(vector<string> &A) {
    int n = A.size();
    if(n==0){
        return 0;
    }
    int m = A[0].length();
    int ans =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j]=='X'){
                mark(A, i, j);
                ans++;
            }
        }
    }
    return ans;
    // Do not write main() function.
    //Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
