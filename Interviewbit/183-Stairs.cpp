/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example :

Input : 3
Return : 3

Steps : [1 1 1], [1 2], [2 1]


*/

int myFunction(int A, map<int, int> &M){
    if(M.find(A)==M.end()){
        int ans = myFunction(A-1, M)+myFunction(A-2, M);
        M[A] = ans;
    }
    // cout<<"* "<<A<<" "<<M[A]<<endl;
    return M[A];
}
int Solution::climbStairs(int A) {
    map<int, int> M;
    M[1] = 1;
    M[2] = 2;
    int ans = myFunction(A, M);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
