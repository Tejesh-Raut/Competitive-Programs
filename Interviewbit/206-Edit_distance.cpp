/*
Given two words A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example : 
edit distance between
"Anshuman" and "Antihuman" is 2.

Operation 1: Replace s with t.
Operation 2: Insert i.

*/

int myFunc(string &A, string &B, int posA, int posB, int &nA, int &nB, vector<vector<int> > &M){
    int ans =0;
    if(posA>=nA){
        return (nB-posB);
    }
    if(posB>=nB){
        return (nA-posA);
    }
    if(M[posA][posB]!= -1){
        return M[posA][posB];
    }
    int iA, iB;
    iA = posA;
    iB = posB;
    while((iA<nA)&&(iB<nB)){
        if(A[iA]!=B[iB]){
            break;
        }
        iA++;
        iB++;
    }
    if((iA==nA)&&(iB==nB)){
        M[posA][posB] =0;
        return 0;
    }
    else{
        if(iA==nA){
            M[posA][posB] = (nB-iB);
            return (nB-iB);
        }
        if(iB==nB){
            M[posA][posB] = (nA-iA);
            return (nA-iA);
        }
    }
    int ans1, ans2, ans3;
    // replace
    ans1 = 1 + myFunc(A, B, (iA+1), (iB+1), nA, nB, M);
    // delete
    ans2 = 1 + myFunc(A, B, (iA+1), (iB), nA, nB, M);
    // insert
    ans3 = 1 + myFunc(A, B, (iA), (iB+1), nA, nB, M);
    if(ans1<ans2){
        if(ans1<ans3){
            M[posA][posB] = ans1;
            return ans1;
        }
        else{
            M[posA][posB] = ans3;
            return ans3;
        }
    }
    else{
        if(ans2<ans3){
            M[posA][posB] = ans2;
            return ans2;
        }
        else{
            M[posA][posB] = ans3;
            return ans3;
        }
    }
}
int Solution::minDistance(string A, string B) {
    int nA = A.length();
    int nB = B.length();
    vector<int> temp(nB, -1);
    vector<vector<int> > M(nA, temp);
    int posA=0, posB=0;
    int ans = myFunc(A, B, posA, posB, nA, nB, M);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
