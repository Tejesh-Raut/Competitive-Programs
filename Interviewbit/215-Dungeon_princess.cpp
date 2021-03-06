/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0’s) or contain magic orbs that increase the knight’s health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Write a function to determine the knight’s minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path

RIGHT-> RIGHT -> DOWN -> DOWN.

Dungeon Princess: Example 1



Input arguments to function:
Your function will get an M*N matrix (2-D array) as input which represents the 2D grid as described in the question. Your function should return an integer corresponding to the knight’s minimum initial health required. 



 Note:
The knight’s health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

*/

int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int n = A.size();
    if(n==0){
        return 0;
    }
    int m = A[0].size();
    vector<int> temp(m, 0);
    vector<vector<int> > p(n, temp);
    p[n-1][m-1] = 1-A[n-1][m-1];
    if(p[n-1][m-1]<1){
        p[n-1][m-1] = 1;
    }
    int p1=0, p2=0;
    for(int i=(n-1); i>=0; i--){
        for(int j=(m-1); j>=0; j--){
            if((i==(n-1))&&(j==(m-1))){
                continue;
            }
            if(i>=(n-1)){
                p1 = INT_MAX;
            }
            else{
                p1 = p[i+1][j] - A[i][j];
                if(p1<1){
                    p1 = 1;
                }
            }
            if(j>=(m-1)){
                p2 = INT_MAX;
            }
            else{
                p2 = p[i][j+1] - A[i][j];
                if(p2<1){
                    p2 = 1;
                }
            }
            if(p1<p2){
                p[i][j] = p1;
            }
            else{
                p[i][j] = p2;
            }
        }
    }
    return p[0][0];
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
