/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

Example :

Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.


*/

int Solution::numDecodings(string A) {
    int n= A.length();
    if(n==0){
        return 0;
    }
    int c, d;
    c= A[0] - '0';
    if(c==0){
        return 0;
    }
    for(int i=1; i<n; i++){
        d = A[i] - '0';
        if((d==0)&&((c==0)||(c>2))){
            return 0;
        }
        c = A[i] - '0';
    }
    if(n==1){
        return 1;
    }
    vector<int> v(n,0);
    v[n-1] = 1;
    c = A[n-2] - '0';
    d = A[n-1] - '0';
    if(d==0){
        v[n-1] = 0;
    }
    if((c==0)||(c>2)){
        v[n-2] = 1;
    }
    else{
        if(c==1){
            v[n-2] = 1+v[n-1];
        }
        else{
            if(d<=6){
                v[n-2] = 1+v[n-1];
            }
            else{
                v[n-2] = 1;
            }
        }
    }
    if(c==0){
        v[n-2] = 0;
    }
    for(int i=(n-3); i>=0; i--){
        c = A[i] - '0';
        d = A[i+1] - '0';
        if(c==0){
            v[i] = 0;
            continue;
        }
        if((c>2)){
            v[i] = v[i+1];
        }
        else{
            if(c==1){
                v[i] = v[i+1]+v[i+2];
            }
            else{
                if(d<=6){
                    v[i] = v[i+1]+v[i+2];
                }
                else{
                    v[i] = v[i+1];
                }
            }
        }
    }
    return v[0];
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
