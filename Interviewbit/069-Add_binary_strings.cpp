/*
Given two binary strings, return their sum (also a binary string).

Example:

a = "100"

b = "11"
Return a + b = “111”.


*/

string Solution::addBinary(string A, string B) {
    int n = A.length();
    int m = B.length();
    string str="";
    bool carry= false;
    bool ans = false;
    int i, j;
    i=n-1;
    j=m-1;
    if(m>n){
        for(int i=0; i<(m-n); i++){
            A = '0'+A;
        }
        i = m-1;
        j = m-1;
    }
    else{
        for(int i=0; i<(n-m); i++){
            B = '0'+B;
        }
        i = n-1;
        j = n-1;
    }
    while((i>=0)&&(j>=0)){
        if((A[i]=='1')&&(B[j]=='1')){
            if(carry){
                ans = true;
            }
            else{
                ans = false;
            }
            carry = true;
        }
        else{
            if(((A[i]=='1')&&(B[j]=='0'))||((A[i]=='0')&&(B[j]=='1'))){
                if(carry){
                    ans = false;
                    carry = true;
                }
                else{
                    ans = true;
                    carry = false;
                }
            }
            else{
                if((A[i]=='0')&&(B[j]=='0')){
                    if(carry){
                        ans = true;
                    }
                    else{
                        ans = false;
                    }
                    carry = false;
                }
                else{
                    return "";
                }
            }
        }
        if(ans){
            str = '1'+str;
        }
        else{
            str = '0'+str;
        }
        i--;
        j--;
    }
    if(carry){
        str = '1'+str;
    }
    return str;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
