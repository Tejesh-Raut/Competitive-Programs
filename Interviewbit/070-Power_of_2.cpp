/*
Find if Given number is power of 2 or not. 
More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:

number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:

return 1 if the number is a power of 2 else return 0

Example:

Input : 128
Output : 1

*/

string Divide(string N){
    // reverse(N.begin(), N.end());
    int data = 2;
    long long base = 10;
    string temp = "";
    for(int i = 0, rem = 0; i < N.size(); i++) {
        long long Cur = (N[i] - '0') + rem * base;
        int val = Cur / data;
        rem = Cur % data;
        temp += (val + '0');
    }
    
    while(temp.size() && !(temp[0] - '0'))
            temp.erase(temp.begin());
    
    return temp;

    /*
    string temp="";
    string ans="";
    int i=0;
    if(A[0]==1){
        temp="1";
        i=1;
    }
    int n = A.length();
    while(i<n){
        temp = temp+A[i];
        int c = stoi(temp);
        int d = c/2;
        int r = c%2;
        string ds = to_string(d);
        ans = ans+ds;
        if(r!=0){
            temp="1";
        }
        else{
            temp="";
        }
        i++;
    }
    ans.erase(0, min(ans.find_first_not_of('0'), ans.size()-1));
    return ans;
    */
}
int Solution::power(string A) {
    int n = A.length();
    if((n==1)&&(A[0]=='1')){
        return 0;
    }
    if((n==1)&&(A[0]=='0')){
        return 0;
    }
    if((A[n-1]=='1')||(A[n-1]=='3')||(A[n-1]=='5')||(A[n-1]=='7')||(A[n-1]=='9')){
        return 0;
    }
    while(n>2){
        A = Divide(A);
        n = A.length();
        if((A[n-1]=='1')||(A[n-1]=='3')||(A[n-1]=='5')||(A[n-1]=='7')||(A[n-1]=='9')){
            return 0;
        }
        // cout<<A<<endl;
    }
    int c = stoi(A);
    // cout<<"c "<<c<<endl;
    if((c==1)||(c==2)||(c==4)||(c==8)||(c==16)||(c==32)||(c==64)){
        return 1;
    }
    else{
        return 0;
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
