/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Example :

n = 5
n! = 120 
Number of trailing zeros = 1
So, return 1

*/

int Solution::trailingZeroes(int A) {
    int fac = 5;
    int n=0;
    while((A/fac)>0){
        n = n+(A/fac);
        fac = fac*5;
    }
    return n;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
