/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell. 
The same letter cell may be used more than once.

Example :

Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns 1,
word = "SEE", -> returns 1,
word = "ABCB", -> returns 1,
word = "ABFSAB" -> returns 1
word = "ABCD" -> returns 0
Note that 1 corresponds to true, and 0 corresponds to false.


*/

bool myFunction(vector<string> &A, string B, int i, int j, int pos){
    if(pos >= B.length()){
        return true;
    }
    if(A[i][j]!= B[pos]){
        return false;
    }
    int n = A.size();
    int m = A[0].size();
    if(i>0){
        if(myFunction(A, B, (i-1), j, (pos+1))){
            return true;
        }
    }
    if(i<(n-1)){
        if(myFunction(A, B, (i+1), j, (pos+1))){
            return true;
        }
    }
    if(j>0){
        if(myFunction(A, B, i, (j-1), (pos+1))){
            return true;
        }
    }
    if(j<(m-1)){
        if(myFunction(A, B, i, (j+1), (pos+1))){
            return true;
        }
    }
    return false;
}
int Solution::exist(vector<string> &A, string B) {
    int n = A.size();
    if(n==0){
        return 0;
    }
    int m = A[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(myFunction(A, B, i, j, 0)){
                return 1;
            }
        }
    }
    return 0;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
