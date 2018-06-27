/*
Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.


*/

int Solution::solve(vector<int> &A) {
    int n = A.size();
    int initial=0;
    vector<int> B(n,0);
    for(int i=0; i<n; i++){
        if((A[i]>=0)&&(A[i]<n)){
            B[A[i]]++;
        }
        else{
            if(A[i]>=n){
                // cout<<"*"<<A[i]<<endl;
                initial++;
            }
        }
    }
    vector<int> C(n,initial);
    int sum=0;
    for(int i=(n-1); i>=0; i--){
        C[i] += sum;
        sum += B[i];
    }
    for(int i=0; i<n; i++){
        // cout<<i<<" "<<B[i]<<" "<<C[i]<<endl;
        if((i==C[i])&&(B[i]>0)){
            return 1;
        }
    }
    return -1;
}
