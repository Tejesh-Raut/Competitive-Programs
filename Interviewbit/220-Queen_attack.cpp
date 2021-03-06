/*
On a N * M chessboard, where rows are numbered from 1 to N and columns from 1 to M, there are queens at some cells. Return a N * M array A, where A[i][j] is number of queens that can attack cell (i, j). While calculating answer for cell (i, j), assume there is no queen at that cell.

Notes:

Queen is able to move any number of squares vertically, horizontally or diagonally on a chessboard. A queen cannot jump over another queen to attack a position.
You are given an array of N strings, each of size M. Each character is either a 1 or 0 denoting if there is a queen at that position or not, respectively.
Expected time complexity is worst case O(N*M).
For example,

Let chessboard be,
[0 1 0]
[1 0 0]
[0 0 1]

where a 1 denotes a queen at that position.

Cell (1, 1) is attacked by queens at (2, 1), (1,2) and (3,3).
Cell (1, 2) is attacked by queen at (2, 1). Note that while calculating this, we assume that there is no queen at (1, 2).
Cell (1, 3) is attacked by queens at (3, 3) and (1, 2).
and so on...

Finally, we return matrix
[3, 1, 2]
[1, 3, 3]
[2, 3, 0]


*/

void myFunction(vector<vector<int> > &ans, vector<string> &A, int x, int y, int &n, int &m){
    // horizontal
    int i=0, j=0;
    for(i=(y-1); i>=0; i--){
        if(A[x][i]=='1'){
            ans[x][i]++;
            break;
        }
        ans[x][i]++;
    }
    for(i=(y+1); i<m; i++){
        if(A[x][i]=='1'){
            ans[x][i]++;
            break;
        }
        ans[x][i]++;
    }
    //vertical
    for(i=(x-1); i>=0; i--){
        if(A[i][y]=='1'){
            ans[i][y]++;
            break;
        }
        ans[i][y]++;
    }
    for(i=(x+1); i<n; i++){
        if(A[i][y]=='1'){
            ans[i][y]++;
            break;
        }
        ans[i][y]++;
    }
    // left diagonal
    i=(x-1);
    j=(y-1);
    while((i>=0)&&(j>=0)){
        if(A[i][j]=='1'){
            ans[i][j]++;
            break;
        }
        ans[i][j]++;
        i--;
        j--;
    }
    i=(x+1);
    j=(y+1);
    while((i<n)&&(j<m)){
        if(A[i][j]=='1'){
            ans[i][j]++;
            break;
        }
        ans[i][j]++;
        i++;
        j++;
    }
    // right diagonal
    i=(x-1);
    j=(y+1);
    while((i>=0)&&(j<m)){
        if(A[i][j]=='1'){
            ans[i][j]++;
            break;
        }
        ans[i][j]++;
        i--;
        j++;
    }
    i=(x+1);
    j=(y-1);
    while((i<n)&&(j>=0)){
        if(A[i][j]=='1'){
            ans[i][j]++;
            break;
        }
        ans[i][j]++;
        i++;
        j--;
    }
    return;
}
vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    int n = A.size();
    if(n==0){
        vector<vector<int> > temp;
        return temp;
    }
    int m = A[0].length();
    vector<int> temp(m,0);
    vector<vector<int> > ans(n, temp);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j]=='1'){
                myFunction(ans, A, i, j, n, m);
            }
        }
    }
    return ans;
}
