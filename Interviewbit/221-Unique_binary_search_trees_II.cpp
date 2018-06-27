/*
Given A, how many structurally unique BST’s (binary search trees) that store values 1...A?

Example :

Given A = 3, there are a total of 5 unique BST’s.


   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


*/

int myFunc(int A, vector<int> &M){
    if(M[A]!=0){
        return M[A];
    }
    int ans =0;
    for(int i=1; i<=A; i++){
        ans += myFunc((i-1), M)* myFunc((A-i), M);
    }
    M[A]=ans;
    return ans;
}
int Solution::numTrees(int A) {
    if(A==0){
        return 0;
    }
    if(A==1){
        return 1;
    }
    int ans = 0;
    vector<int> M((A+1),0);
    M[0]=1;
    for(int i=1; i<=A; i++){
        ans += myFunc((i-1), M)*myFunc((A-i), M);
        // cout<<"* "<<i<<" "<<ans<<endl;
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
