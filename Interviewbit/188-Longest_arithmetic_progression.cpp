/*
Find longest Arithmetic Progression in an integer array and return its length. More formally, find longest sequence of indeces, 0 < i1 < i2 < … < ik < ArraySize(0-indexed) such that sequence A[i1], A[i2], …, A[ik] is an Arithmetic Progression. Arithmetic Progression is a sequence in which all the differences between consecutive pairs are the same, i.e sequence B[0], B[1], B[2], …, B[m - 1] of length m is an Arithmetic Progression if and only if B[1] - B[0] == B[2] - B[1] == B[3] - B[2] == … == B[m - 1] - B[m - 2].
Examples
1) 1, 2, 3(All differences are equal to 1)
2) 7, 7, 7(All differences are equal to 0)
3) 8, 5, 2(Yes, difference can be negative too)

Samples
1) Input: 3, 6, 9, 12
Output: 4

2) Input: 9, 4, 7, 2, 10
Output: 3(If we choose elements in positions 1, 2 and 4(0-indexed))


*/

int Solution::solve(const vector<int> &A) {
    int n = A.size();
    if(n<=2){
        return n;
    }
    vector<int> B(n,0);
    for(int i=0; i<n; i++){
        B[i] = A[i];
    }
    sort(B.begin(), B.end());
    int mxl = 2;
    vector<vector<int> > dp(n, vector<int>(n));
    for(int i=0; i<n; i++){
        dp[i][n-1] = 2;
    }
    for(int j=(n-2); j>=1; j--){
        int i= j-1;
        int k= j+1;
        while((i>=0)&&(k<n)){
            // cout<<"* "<<i<<" "<<j<<" "<<k<<endl;
            if((B[i]+B[k])==2*B[j]){
                dp[i][j]=dp[j][k]+1;
                if(mxl<dp[i][j]){
                    mxl = dp[i][j];
                }
                i--;
                k++;
            }
            else{
                if((B[i]+B[k])<2*B[j]){
                    k++;
                }
                else{
                    dp[i][j]=2;
                    i--;
                }
            }
            // cout<<"** "<<i<<" "<<j<<" "<<k<<endl;
        }
        while(i>=0){
            dp[i][j] = 2;
            i--;
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return mxl;
}
