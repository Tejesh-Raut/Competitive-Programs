/*
You are given two positive integers A and B. For all permutations of [1, 2, …, A], we create a BST. Count how many of these have height B.

Notes:

Values of a permutation are sequentially inserted into the BST by general rules i.e in increasing order of indices.
Height of BST is maximum number of edges between root and a leaf.
Return answer modulo 109 + 7.
Expected time complexity is worst case O(N4).
1 ≤ N ≤ 50
For example,

A = 3, B = 1

Two permutations [2, 1, 3] and [2, 3, 1] generate a BST of height 1.
In both cases the BST formed is

    2
   / \
  1   3  


Another example,
A = 3, B = 2
Return 4.

Next question, can you do the problem in O(N3)?


*/

int myFunc2(int A, int B, vector<vector<int> > &M1, vector<vector<int> > &M2){
    if(M2[A][B]!=-1){
        return M2[A][B];
    }
    if(A<=1){
        M2[A][B] = 1;
    }
    if(B==0){
        M2[A][B] = 0;
    }
    int ans =0;
    for(int i=1; i<=A; i++){
        ans += myFunc2((i-1), (B-1), M1, M2)*myFunc2((A-i), (B-1), M1, M2);
    }
    M2[A][B] = ans;
    return ans;
}
int myFunc1(int A, int B, vector<vector<int> > &M1, vector<vector<int> > &M2){
    if(M1[A][B]!=-1){
        return M1[A][B];
    }
    if(A==0){
        M1[A][B] = 0;
    }
    if(B==0){
        M1[A][B] = 0;
    }
    int ans =0;
    for(int i=1; i<=A; i++){
        ans += myFunc1((i-1), (B-1), M1, M2)*myFunc1((A-i), (B-1), M1, M2);
        ans += myFunc1((i-1), (B-1), M1, M2)*myFunc2((A-i), (B-2), M1, M2);
        ans += myFunc2((i-1), (B-2), M1, M2)*myFunc1((A-i), (B-1), M1, M2);
    }
    // cout<<"*"<<A<<" "<<B<<" : "<<ans<<endl;
    M1[A][B] = ans;
    return ans;
}
int Solution::cntPermBST(int A, int B) {
    vector<int> temp((B+1),-1);
    vector<vector<int> > M1((A+1), temp);
    vector<vector<int> > M2((A+1), temp); // height less than or equal to B
    M1[0][0] = 1;
    M1[1][0] = 1;
    M2[1][0] = 1;
    M2[1][0] = 1;
    int ans = myFunc1(A, B, M1, M2);
    return ans;
}
