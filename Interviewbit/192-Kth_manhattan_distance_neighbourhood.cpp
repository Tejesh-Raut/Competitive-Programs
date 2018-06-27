/*
Given a matrix M of size nxm and an integer K, find the maximum element in the K manhattan distance neighbourhood for all elements in nxm matrix. 
In other words, for every element M[i][j] find the maximum element M[p][q] such that abs(i-p)+abs(j-q) <= K.

Note: Expected time complexity is O(N*N*K)

Constraints:

1 <= n <= 300
1 <= m <= 300
1 <= K <= 300
0 <= M[i][j] <= 1000
Example:

Input:
M  = [[1,2,4],[4,5,8]] , K = 2

Output:
ans = [[5,8,8],[8,8,8]]


*/

vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    int n = B.size();
    if(n==0){
        vector<vector<int> > temp_ans; 
        return temp_ans;
    }
    int m = B[0].size();
    vector<int> temp(m,0);
    vector<vector<int> > ans(n, temp);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int max = B[i][j];
            for(int i1=(i-A); i1<=(i+A); i1++){
                if((i1<0)||(i1>=n)){
                    continue;
                }
                for(int j1=(j-A+abs(i1-i)); j1<=(j+A-abs(i1-i)); j1++){
                    if((j1<0)||(j1>=m)){
                        continue;
                    }
                    if(B[i1][j1]>max){
                        max = B[i1][j1];
                    }
                }
            }
            ans[i][j] = max;
        }
    }
    return ans;
}
