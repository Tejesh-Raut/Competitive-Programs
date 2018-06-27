/*
You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).


*/

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    int n = B.size();
    vector<int> ans;
    int lenA = A.length();
    if(n==0){
        for(int i=0; i<lenA; i++){
            ans.push_back(i);
        }
        return ans;
    }
    int len=B[0].length();
    unordered_map<string, vector<int> > M;
    for(int i=0; i<n; i++){
        if(M.find(B[i])!=M.end()){
            M[B[i]].push_back(i);
        }
        else{
            vector<int> temp1;
            temp1.push_back(i);
            M[B[i]] = temp1;
        }
    }
    for(int i=0; i<lenA; i++){
        // unordered_map<string, bool> M;
        int count = 0;
        bool myflag = true;
        vector<bool> flags(n, false);
        for(int j=0; j<n; j++){
            string temp = "";
            for(int k=(i+(j*len)); k<(i+((j+1)*len)); k++){
                temp += A[k];
            }
            if(M.find(temp)==M.end()){
                break;
            }
            int n2 = M[temp].size();
            int k=0;
            while(flags[M[temp][k]]){
                k++;
                if(k>=n2){
                    myflag = false;
                    break;
                }
            }
            if(k>=n2){
                myflag = false;
                break;
            }
            else{
                flags[M[temp][k]] = true;
            }
            count++;
            // M[temp] = true;
        }
        if(count == n){
            if(myflag){
                ans.push_back(i);
            }
        }
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
