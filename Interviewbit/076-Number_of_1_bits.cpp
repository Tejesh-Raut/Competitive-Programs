/*
Write a function that takes an unsigned integer and returns the number of 1 bits it has.

Example:

The 32-bit integer 11 has binary representation

00000000000000000000000000001011
so the function should return 3.

Note that since Java does not have unsigned int, use long for Java


*/

int Solution::numSetBits(unsigned int A) {
    int count =0;
    while(A){
        count += A&1;
        A=A>>1;
    }
    return count;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
