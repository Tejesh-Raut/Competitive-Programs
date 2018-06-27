/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
Make sure the returned list of strings are sorted.


*/

vector<string> findCombinations(int start, int close){
    vector<string> ans;
    if(start==close){
        if(start==0){
            return ans;
        }
        vector<string> temp = findCombinations((start-1), close);
        int n = temp.size();
        for(int i=0; i<n; i++){
            ans.push_back('('+temp[i]);
        }
    }
    else{
        if(start==0){
            string s="";
            for(int i=0; i<close; i++){
                s += ')';
            }
            ans.push_back(s);
        }
        else{
            vector<string> temp = findCombinations((start-1), close);
            int n = temp.size();
            for(int i=0; i<n; i++){
                ans.push_back('('+temp[i]);
            }
            vector<string> temp1 = findCombinations(start, (close-1));
            n = temp1.size();
            for(int i=0; i<n; i++){
                ans.push_back(')'+temp1[i]);
            }
        }
    }
    return ans;
}
vector<string> Solution::generateParenthesis(int A) {
    vector<string> ans;
    ans = findCombinations(A, A);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
