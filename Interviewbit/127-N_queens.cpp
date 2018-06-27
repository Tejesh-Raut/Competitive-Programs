/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

N Queens: Example 1

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/

bool kills(int x1, int y1, int x2, int y2){
    if((x1==x2)||(y1==y2)){
        return true;
    }
    if(abs(x2-x1)==abs(y2-y1)){
        return true;
    }
    return false;
}
bool isValidConf(vector<string> &conf, int filled){
    int n = conf[0].length();
    vector<int> xpos;
    vector<int> ypos;
    for(int i=0; i<filled; i++){
        for(int j=0; j<n; j++){
            if(conf[i][j]=='Q'){
                xpos.push_back(i);
                ypos.push_back(j);
            }
        }
    }
    for(int i=0; i<filled; i++){
        for(int j=(i+1); j<filled; j++){
            if(kills(xpos[i], ypos[i], xpos[j], ypos[j])){
                return false;
            }
        }
    }
    return true;
}
vector<vector<string> > findSolution(vector<string> conf, int filled){
    int n = conf[0].length();
    vector<vector<string> > ans;
    vector<string> ansin;
    if(filled>=n){
        ans.push_back(conf);
        return ans;
    }
    for(int i=0; i<n; i++){
        ansin = conf;
        string s = "";
        for(int j=0; j<n; j++){
            if(j==i){
                s +='Q';
            }
            else{
                s +='.';
            }
        }
        ansin[filled] = s;
        if(isValidConf(ansin, (filled+1))){
            vector<vector<string> > temp = findSolution(ansin, (filled+1));
            int n1 = temp.size();
            for(int j=0; j<n1; j++){
                ans.push_back(temp[j]);
            }
        }
    }
    return ans;
}
vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string> > ans;
    vector<string> conf;
    if(A<=3){
        if(A==1){
            string s = "Q";
            conf.push_back(s);
            ans.push_back(conf);
        }
        return ans;
    }
    for(int i=0; i<A; i++){
        string s ="";
        for(int j=0; j<A; j++){
            s +=".";
        }
        conf.push_back(s);
    }
    ans = findSolution(conf, 0);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
