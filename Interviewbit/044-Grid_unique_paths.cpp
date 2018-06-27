/*
A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).

Path Sum: Example 1

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :

Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)

*/

long long factorial(int a, int b){
    long long ans=1;
    for(int i=a; i<=b; i++){
        ans *=i;
    }
    return ans;
}
int Solution::uniquePaths(int A, int B) {
    // return factorial(3);
    long long ans;
    int a, b;
    if(A>B){
        a=A;
        b=B;
    }
    else{
        a=B;
        b=A;
    }
    ans = factorial(a, (a+b-2));
    ans = ans/factorial(1,(b-1));
    int final_ans;
    final_ans = (int) ans;
    return final_ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
