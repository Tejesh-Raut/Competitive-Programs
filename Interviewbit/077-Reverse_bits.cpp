/*
Reverse bits of an 32 bit unsigned integer

Example 1:

x = 0,

          00000000000000000000000000000000  
=>        00000000000000000000000000000000
return 0

Example 2:

x = 3,

          00000000000000000000000000000011 
=>        11000000000000000000000000000000
return 3221225472

Since java does not have unsigned int, use long


*/

unsigned int Solution::reverse(unsigned int A) {
    unsigned int reverse=0;
    for(int i=0; i<32; i++){
        reverse <<=1;
        reverse += A&1;
        A = A>>1;
    }
    return reverse;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
