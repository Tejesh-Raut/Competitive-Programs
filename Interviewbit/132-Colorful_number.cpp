/*
For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1

*/

int Solution::colorful(int A) {
    string s = to_string(A);
    int n = s.length();
    unordered_map<long long, bool> M;
    for(int i=0; i<n; i++){
        // cout<<"i "<<i<<endl;
        // string t = "";
        long long mul = 1;
        for(int j=i; j<n; j++){
            // cout<<"j "<<j<<endl;
            // t += s[j];
            mul *= (long long)(s[j]-'0');
            if(M.find(mul)==M.end()){
                // cout<<"*"<<mul<<endl;
                M[mul] = true;
            }
            else{
                return 0;
            }
        }
    }
    return 1;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
