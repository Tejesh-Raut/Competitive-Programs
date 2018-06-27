/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example:

Given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.

For this problem, return the maximum sum.


*/
int Solution::maxSubArray(const vector<int> &A) {
    int len = A.size();
    vector<int> sumi(len, 0);
    vector<int> maxi(len, 0); // max sumi after i
    vector<int> mini(len, 0); // min sumi before i
    
    sumi[0] = A[0];
    mini[0] = 0;
    for(int i=1; i<len; i++){
        sumi[i] = sumi[i-1] + A[i];
        if(sumi[i-1]<mini[i-1]){
            mini[i] = sumi[i-1];
        }
    }
    maxi[len-1] = sumi[len-1];
    for(int i=(len-2); i>=0; i--){
        if(maxi[i+1]<sumi[i]){
            maxi[i] = sumi[i];
        }
        else{
            maxi[i] = maxi[i+1];
        }
    }
    int max = A[0];
    for (int i=0; i<len; i++){
        if((maxi[i]-mini[i])>max){
            max = maxi[i] - mini[i];
        }
        /*
        {
            cout<<"*"<<i<<" "<<mini[i]<<" "<<maxi[i]<<" "<<sumi[i]<<" "<<max<<endl;
        }
        */
        }
    // cout<<endl;
    
    return max;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
