/*
The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.


*/

string Solution::countAndSay(int A) {
    int a =1;
    char curr='2';
    int l;
    int count =1;
    string s = "1";
    string s1="";
    if(A==1){
        return s;
    }
    for(int i=2;i<=A; i++){
        l = s.length();
        s1="";
        // cout<<"*"<<(i-1)<<" "<<s<<endl;
        for(int j=0; j<l; j++){
            // cout<<"curr "<<curr<<endl;
            // cout<<"count "<<count<<endl;
            if(j==0){
                curr = s[0];
                count = 1;
                continue;
            }
            if(s[j]==curr){
                count++;
            }
            else{
                s1 = s1+ to_string(count);
                s1 = s1 + curr;
                count = 1;
                curr = s[j];
            }
        }
        s1 = s1 + to_string(count);
        s1 = s1 +curr;
        s = s1;
    }
    return s;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
