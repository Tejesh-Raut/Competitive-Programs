/*
Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example :

Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2. 

*/

int Solution::majorityElement(const vector<int> &A) {
    int count=0;
    int ans=0;
    int n = A.size();
    for(int i=0; i<n; i++){
        if(count==0){
            ans = A[i];
        }
        if(A[i]==ans){
            count++;
        }
        else{
            count--;
        }
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
