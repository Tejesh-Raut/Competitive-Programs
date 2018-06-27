/*
Implement int sqrt(int x).

Compute and return the square root of x.

If x is not a perfect square, return floor(sqrt(x))

Example :

Input : 11
Output : 3
DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY


*/

int Solution::sqrt(int A) {
    long long l = 0;
    long long r = (long long) A;
    while(l<r){
        long long m = l +(r-l)/2+1;
        // if(m==l){
        //     break;
        // }
        long long sq = m*m;
        if(sq==A){
            return m;
        }
        if(sq>A){
            r = m-1;
        }
        else{
            l = m;
        }
    }
    return l;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
