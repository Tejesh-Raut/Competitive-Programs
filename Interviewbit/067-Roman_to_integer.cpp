/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Read more details about roman numerals at Roman Numeric System

Example :

Input : "XIV"
Return : 14
Input : "XX"
Output : 20

*/

int val(char c){
    if(c=='I'){
        return 1;
    }
    if(c=='V'){
        return 5;
    }
    if(c=='X'){
        return 10;
    }
    if(c=='L'){
        return 50;
    }
    if(c=='C'){
        return 100;
    }
    if(c=='D'){
        return 500;
    }
    if(c=='M'){
        return 1000;
    }
    else{
        return 0;
    }
}
int Solution::romanToInt(string A) {
    int n = A.length();
    int sub, num;
    sub=0;
    num = 0;
    char last, curr;
    int lasti, curri;
    last = A[0];
    lasti = val(last);
    curri = val(A[0]);
    for(int i=1; i<n; i++){
        curr = A[i];
        curri = val(curr);
        if(lasti<curri){
            sub += lasti;
        }
        else{
            num -= sub;
            num += lasti;
            sub = 0;
        }
        lasti = curri;
        // cout<<i<<" "<<num<<endl;
    }
    num -= sub;
    num += curri;
    return num;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
