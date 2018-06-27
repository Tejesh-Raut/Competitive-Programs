/*
Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer


*/

int Solution::reverse(int A) {
    // cout<<A<<endl;
    long long B=0;
    int neg = false;
    if(A<0){
        neg = true;
        A = -A;
    }
    int C=0;
    while(A>0){
        C=B;
        B = B*10 + (long long)(A%10);
        A /= 10;
    }
    if(neg){
        B = -B;
    }
    if(((long long)((int)B))!=(B)){
        return 0;
    }
    return B;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
