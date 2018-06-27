/*
Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

 Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise. 
Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.
If you do, we will disqualify your submission retroactively and give you penalty points.


*/

int Solution::atoi(const string &A) {
    int n = A.length();
    if(n==0){
        return 0;
    }
    int i=0;
    // cout<<"---"<<A[i]<<endl;
    while(A[i]==' '){
        cout<<i<<endl;
        i++;
        if(i>=n){
            return 0;
        }
    }
    bool neg = false;
    if(A[i]=='-'){
        neg = true;
        i++;
    }
    if(A[i]=='+'){
        i++;
    }
    
    // cout<<"*"<<i<<endl;
    int ans=0;
    long long ans_long=0;
    while(((A[i]-'0')>=0)&&((A[i]-'0')<=9)){
        int c = A[i]-'0';
        // cout<<c<<endl;
        ans = 10*ans + c;
        ans_long = 10*ans_long +c;
        if(((long long)ans)!=(ans_long)){
            if(neg){
                return INT_MIN;
            }
            else{
                return INT_MAX;
            }
        }
        // cout<<ans<<" "<<ans_long<<endl;
        i++;
    }
    if(neg){
        return ((-1)*ans);
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
