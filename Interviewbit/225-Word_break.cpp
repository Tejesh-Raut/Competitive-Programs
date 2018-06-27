/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given

s = "myinterviewtrainer",
dict = ["trainer", "my", "interview"].
Return 1 ( corresponding to true ) because "myinterviewtrainer" can be segmented as "my interview trainer".

Return 0 / 1 ( 0 for false, 1 for true ) for this problem


*/
bool existDict(string &A, int start, int end, vector<string> &dict){
    int n = dict.size();
    int nA = end-start;
    for(int i=0; i<n; i++){
        int nd = dict[i].length();
        if(nA!=nd){
            continue;
        }
        else{
            int j=0;
            for(j=0; j<nd; j++){
                if(A[j+start]<dict[i][j]){
                    return false;
                }
                else{
                    if(A[j+start]>dict[i][j]){
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
bool myFunc(string &A, int start, int end, vector<string> &dict, vector<int> &M){
    if(M[start]!=-1){
        if(M[start]==1){
            return true;
        }
        else{
            return false;
        }
    }
    int n = end-start;
    if(n==0){
        return true;
    }
    for(int i =0; i<n; i++){
        if(existDict(A, start, (start+i+1), dict)){
            if(i==(n-1)){
                M[start] = 1;
                return true;
            }
            else{
                if(myFunc(A, (i+start+1), end, dict, M)){
                    M[start] = 1;
                    return true;
                }
            }
        }
    }
    M[start] = 0;
    return false;
}
int Solution::wordBreak(string A, vector<string> &B) {
    sort(B.begin(), B.end());
    // int n2= B.size();
    // vector<int> dict2(n2,0);
    // for(int i=0; i<n2; i++){
    //     dict2[i] = B[i].length();
    // }
    bool ans;
    int n = A.size();
    vector<int> M((n+1), -1);
    ans = myFunc(A, 0, n, B, M);
    if(ans){
        return 1;
    }
    else{
        return 0;
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
