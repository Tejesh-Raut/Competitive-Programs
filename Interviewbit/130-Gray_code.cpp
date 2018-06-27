/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
There might be multiple gray code sequences possible for a given n.
Return any such sequence.


*/

vector<int> Solution::grayCode(int A) {
    vector<int> ans;
    if(A==1){
        ans.push_back(0);
        ans.push_back(1);
        return ans;
    }
    ans = grayCode(A-1);
    int n = ans.size();
    for(int i=(n-1); i>=0; i--){
        ans.push_back(ans[i]+n);;
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
