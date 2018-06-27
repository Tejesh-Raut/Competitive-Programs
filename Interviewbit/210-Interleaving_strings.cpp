/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example,
Given:

s1 = "aabcc",
s2 = "dbbca",
When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem


*/

bool myFunc(string &A, int posA, int &nA, string &B, int posB, int &nB, string &C, int posC, int &nC){  
    if(posC>=nC){
        if((posA>=nA)&&(posB>=nB)){
            return true;
        }
        else{
            return false;
        }
    }
    if((posA>=nA)&&(posB>=nB)){
        return false;
    }
    int iA = posA;
    int iB = posB;
    int iC = posC;
    bool ans1, ans2;
    if((A[iA]!=C[iC])&&(B[iB]!=C[iC])){
        return false;
    }
    else{
        if((A[iA]==C[iC])&&(B[iB]!=C[iC])){
            return (myFunc(A, (iA+1), nA, B, posB, nB, C, (iC+1), nC));
        }
        else{
            if((A[iA]!=C[iC])&&(B[iB]==C[iC])){
                return (myFunc(A, posA, nA, B, (iB+1), nB, C, (iC+1), nC));
            }
            else{
                ans1 = myFunc(A, (iA+1), nA, B, posB, nB, C, (iC+1), nC);
                ans2 = myFunc(A, posA, nA, B, (iB+1), nB, C, (iC+1), nC);
                return (ans1||ans2);
            }
        }
    }
    // cout<<"* "<<posA<<"/"<<nA<<" "<<posB<<"/"<<nB<<" "<<posC<<"/"<<nC<<"**"<<ans1<<" "<<ans2<<endl;
}
int Solution::isInterleave(string A, string B, string C) {
    int nA = A.length();
    int nB = B.length();
    int nC = C.length();
    if(myFunc(A, 0, nA, B, 0, nB, C, 0, nC)){
        return 1;
    }
    else{
        return 0;
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
