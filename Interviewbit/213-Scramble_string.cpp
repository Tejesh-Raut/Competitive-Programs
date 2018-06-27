/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = “great”:


    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
 
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that “rgeat” is a scrambled string of “great”.

Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that “rgtae” is a scrambled string of “great”.

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1. Return 0/1 for this problem.


*/
int Solution::isScramble(const string A, const string B) {
    int n = A.length();
    if(n!=B.length()){
        // cout<<"* "<<n<<" "<<B.length()<<endl;
        // cout<<A<<" "<<B<<endl;
        return 0;
    }
    if(A==B){
        return 1;
    }
    unordered_map<char, int> M;
    for(int i=0; i<n; i++){
        if(M.find(A[i])==M.end()){
            M[A[i]]=1;
        }
        else{
            M[A[i]]++;
        }
    }
    for(int i=0; i<n; i++){
        if(M.find(B[i])==M.end()){
            return 0;
        }
        else{
            M[B[i]]--;
            if(M[B[i]]<0){
                // cout<<"*"<<B[i]<<" "<<A<<" "<<B<<endl;
                return 0;
            }
        }
    }
    for(int i=1; i<n; i++){
        if((isScramble(A.substr(i), B.substr(i))==1)&&(isScramble(A.substr(0,i), B.substr(0,i))==1)){  
            // cout<<"* "<<A<<" "<<B<<" "<<i<<endl;
            return 1;
        }
        if((isScramble(A.substr(i), B.substr(0,(n-i)))==1)&&(isScramble(A.substr(0,i), B.substr(n-i))==1)){
            // cout<<"** "<<A<<" "<<B<<" "<<i<<endl;
            return 1;
        }
    }
    return 0;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
