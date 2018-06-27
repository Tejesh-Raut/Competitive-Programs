/*
Given an array of integers, find the length of longest subsequence which is first increasing then decreasing.

**Example: **

For the given array [1 11 2 10 4 5 2 1]

Longest subsequence is [1 2 10 4 2 1]

Return value 6


*/

void fillLis(vector<int> &lis, const vector<int> &A, int n){
    int ans;
    int max;
    for(int i=0; i<n; i++){
        ans = 1;
        max = 0;
        for(int j=0; j<i; j++){
            if((lis[j]>max)&&(A[j]<A[i])){
                max = lis[j];
            }
        }
        ans += max;
        lis[i] = ans;
    }
    return;
}
void fillLds(vector<int> &lds, const vector<int> &A, int n){
    int ans;
    int max;
    for(int i=(n-1); i>=0; i--){
        ans = 1;
        max = 0;
        for(int j=(n-1); j>i; j--){
            if((lds[j]>max)&&(A[j]<A[i])){
                max = lds[j];
            }
        }
        ans += max;
        lds[i] = ans;
    }
    return;
}
int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    // cout<<"* ";
    // for(int i=0; i<n ;i++){
    //     cout<<A[i]<<" ";
    // }
    // cout<<endl;
    int max = 0;
    int score;
    vector<int> lis(n, 0);
    vector<int> lds(n, 0);
    fillLis(lis, A, n);
    // cout<<"* ";
    // for(int i=0; i<n ;i++){
    //     cout<<lis[i]<<" ";
    // }
    // cout<<endl;
    fillLds(lds, A, n);
    // cout<<"* ";
    // for(int i=0; i<n ;i++){
    //     cout<<lds[i]<<" ";
    // }
    // cout<<endl;
    for(int i=0; i<n; i++){
        score= lis[i]+lds[i]-1;
        if(score>max){
            max = score;
        }
    }
    return max;
}
