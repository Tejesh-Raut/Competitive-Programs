/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example :
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

If it is not possible to reach the end index, return -1.


*/

int Solution::jump(vector<int> &A) {
    int n = A.size();
    if(n<=1){
        return 0;
    }
    if(A[0]==0){
        return -1;
    }
    int max_reach = A[0];
    int step = A[0];
    int jump = 1;
    
    int i=1;
    for(i=1; i<n; i++){
        if(i==(n-1)){
            return jump;
        }
        if((i+A[i])>max_reach){
            max_reach = i+A[i];
        }
        step--;
        if(step==0){
            jump++;
            if(i>=max_reach){
                return -1;
            }
            step = max_reach -i;
        }
    }
    return -1;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
