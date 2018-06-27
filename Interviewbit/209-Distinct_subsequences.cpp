/*
Given two sequences S, T, count number of unique ways in sequence S, to form a subsequence that is identical to the sequence T.

 Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none ) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not). 
Example :

S = "rabbbit" 
T = "rabbit"
Return 3. And the formations as follows:

S1= "ra_bbit" 
S2= "rab_bit" 
S3="rabb_it"
"_" marks the removed character.


*/

int myFunc(string &S, int posS, int &nS, string &T, int posT, int &nT, vector<vector<int> > &M){   
    int iS, iT;
    iS = posS;
    iT = posT;
    if(iT>=nT){
        return 1;
    }
    if(iS>=nS){
        return 0;
    }
    if(M[posS][posT]!=-1){
        return M[posS][posT];
    }
    while(S[iS]!=T[iT]){
        iS++;
        if(iS>=nS){
            return 0;
        }
    }
    int ans1 = myFunc(S,(iS+1),nS, T, (iT+1),nT, M);
    int ans2 = myFunc(S,(iS+1),nS, T,(iT),nT, M);
    M[posS][posT] = (ans1+ans2);
    // cout<<"*"<<posS<<":"<<posT<<endl;
    return (ans1+ans2);
}
int Solution::numDistinct(string S, string T) {
    int nS = S.length();
    int nT = T.length();
    vector<int> temp(nT, -1);
    vector<vector<int> > M(nS, temp);
    int ans = myFunc(S,0,nS, T,0,nT, M);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
