/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers.

Assume that there will only be one solution

Example: 
given array S = {-1 2 1 -4}, 
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)


*/

int Solution::threeSumClosest(vector<int> &A, int B){
    int n = A.size();
    sort(A.begin(), A.end());
    int j,k, sum;
    int best_sum = A[0]+A[1]+A[2];
    for(int i=0; i<(n-2); i++){
        j = i+1;
        k = n-1;
        while(k>j){
            sum = A[i]+A[j]+A[k];
            if (sum == B){
                // cout<<A[i]<<" "<<A[j]<<" "<<A[k]<<endl;
                return B;
            }
            if(abs(sum-B)<abs(best_sum-B)){
                best_sum = sum;
            }
            if(sum>B){
                k--;
            }
            else{
                j++;
            }
        }
    }
    return best_sum;
}