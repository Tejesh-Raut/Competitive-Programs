/*
Given a string s, partition s such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["a","a","b"]
    ["aa","b"],
  ]
 Ordering the results in the answer : Entry i will come before Entry j if :
len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
*
*
*
(len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
In the given example,
["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")


*/

bool isPalindrome(string &s, int start, int i){
    int j = start;
    int k = i;
    while(j<k){
        if(s[j]!=s[k]){
            return false;
        }
        j++;
        k--;
    }
    return true;
}
vector<vector<string> > findCombinations(string A, int start, int n){
    vector<vector<string> > ans;
    int nout, nin;
    string s = "";
    for(int i=start; i<n; i++){
        s += A[i];
        if(isPalindrome(A, start, i)){
            if(i==(n-1)){
                vector<string> ansin;
                ansin.push_back(s);
                ans.push_back(ansin);
            }
            else{
                vector<vector<string> > temp = findCombinations(A, (i+1), n);
                nout = temp.size();
                for(int j=0; j<nout; j++){
                    vector<string> ansin;
                    ansin.push_back(s);
                    nin = temp[j].size();
                    for(int k=0; k<nin; k++){
                        ansin.push_back(temp[j][k]);
                    }
                    ans.push_back(ansin);
                }
            }
        }
    }
    return ans;
}
vector<vector<string> > Solution::partition(string A) {
    vector<vector<string> > ans;
    int n = A.length();
    ans = findCombinations(A, 0, n);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
