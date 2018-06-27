/*
Given a 3Xn board, find the number of ways to color it using at most 4 colors such that no two adjacent boxes have same color. Diagonal neighbors are not treated as adjacent boxes. 
Output the ways%1000000007 as the answer grows quickly.

1<= n < 100000

Example:
Input: n = 1
Output: 36


*/

int Solution::solve(int A) {
    int ans;
    if(n==0){
        return -1;
    }
    if(n==1){
        return 36;
    }
    long long ans = (long long)solve(A-1);
    
}
