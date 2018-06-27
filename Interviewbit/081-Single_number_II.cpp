/*
Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?

Example :

Input : [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Output : 4

*/

int Solution::singleNumber(const vector<int> &A) {
    int ones = 0;
    int twos = 0;
    int common = 0;
    int n = A.size();
    for(int i=0; i<n; i++){
        twos |= ones&A[i];
        ones ^= A[i];
        common = ~(ones & twos);
        ones &= common;
        twos &= common;
    }
    return ones;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
