/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given

s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].
A solution is

[
  "cat sand dog", 
  "cats and dog"
]
Make sure the strings are sorted in your result.


*/

bool existDict(string A, vector<string> &dict){
    int n = dict.size();
    int nA = A.length();
    for(int i=0; i<n; i++){
        int nd = dict[i].length();
        if(nA!=nd){
            continue;
        }
        else{
            // cout<<":: "<<A<<" "<<dict[i]<<endl;
            int j=0;
            for(j=0; j<nd; j++){
                if(A[j]<dict[i][j]){
                    return false;
                }
                else{
                    if(A[j]>dict[i][j]){
                        break;
                    }
                }
            }
            if(j==nd){
                return true;
            }
        }
    }
    return false;
}
vector<string> myFunc(string A, vector<string> &dict){
    vector<string> ans;
    int n = A.length();
    if(n==0){
        return ans;
    }
    for(int i =0; i<n; i++){
        string anss;
        if(i<(n-1)){
            anss = A.substr(0,(i+1));
        }
        else{
            anss = A;
        }
        if(existDict(anss, dict)){
            // cout<<"** "<<anss<<" "<<i<<" in "<<A<<endl;
            if(i==(n-1)){
                ans.push_back(anss);
                return ans;
            }
            else{
                vector<string> t = myFunc(A.substr(i+1), dict);
                int ts = t.size();
                if(ts>0){
                    for(int j=0; j<ts; j++){
                        string anst = anss+" "+t[j];
                        ans.push_back(anst);
                    }
                }
            }
        }
        else{
            // cout<<"* "<<anss<<endl;
        }
    }
    return ans;
}
vector<string> Solution::wordBreak(string A, vector<string> &B) {
    sort(B.begin(), B.end());
    for(int i=0; i<B.size(); i++){
        // cout<<"*- "<<B[i]<<endl;
    }
    vector<string> ans;
    ans = myFunc(A, B);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
