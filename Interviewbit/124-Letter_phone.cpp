/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.


*/

vector<string> getMap(char c){
    vector<string> ans;
    switch(c){
        case '0':
            ans.push_back("0");
        break;
        case '1':
            ans.push_back("1");
        break;
        case '2':
            ans.push_back("a");
            ans.push_back("b");
            ans.push_back("c");
            // cout<<ans[0]<<endl;
        break;
        case '3':
            ans.push_back("d");
            ans.push_back("e");
            ans.push_back("f");
        break;
        case '4':
            ans.push_back("g");
            ans.push_back("h");
            ans.push_back("i");
        break;
        case '5':
            ans.push_back("j");
            ans.push_back("k");
            ans.push_back("l");
        break;
        case '6':
            ans.push_back("m");
            ans.push_back("n");
            ans.push_back("o");
        break;
        case '7':
            ans.push_back("p");
            ans.push_back("q");
            ans.push_back("r");
            ans.push_back("s");
        break;
        case '8':
            ans.push_back("t");
            ans.push_back("u");
            ans.push_back("v");
        break;
        case '9':
            ans.push_back("w");
            ans.push_back("x");
            ans.push_back("y");
            ans.push_back("z");
        break;
    }
    return ans;
}
void findCombinations(vector<string> &ans, string &A, int start , int n){
    if(start==(n-1)){
        vector<string> temp = getMap(A[start]);
        int n1 = temp.size();
        for(int i=0; i<n1; i++){
            // string s = temp[i]+"";
            // cout<<"*"<<temp[i]<<endl;
            ans.push_back(temp[i]);
        }
    }
    else{
        findCombinations(ans, A, (start+1), n);
        vector<string> temp = getMap(A[start]);
        int n1 = temp.size();
        vector<string> ans1 = ans;
        int n2 = ans.size();
        for(int i=0; i<n2; i++){
            ans[i] = temp[0]+ans[i];
        }
        for(int i=1; i<n1; i++){
            for(int j=0; j<n2; j++){
                ans.push_back(temp[i]+ans1[j]);
            }
        }
    }
    return;
}
vector<string> Solution::letterCombinations(string A) {
    vector<string> ans;
    int n = A.length();
    findCombinations(ans, A, 0, n);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
