/*
Given expression with operands and operators (OR , AND , XOR) , in how many ways can you evaluate the expression to true, by grouping in different ways? Operands are only true and false.
Input:

string :  T|F&T^T
here '|' will represent or operator 
     '&' will represent and operator
     '^' will represent xor operator
     'T' will represent true operand
     'F' will false
Output:

different ways % MOD
where MOD = 1003
Example:

string : T|F
only 1 way (T|F) => T
so output will be 1 % MOD = 1

*/

vector<int> myEvaluate(string A, int start, int end, vector<vector<vector<int> > > &M){
    // cout<<"*- "<<start<<" "<<end<<endl;
    if(!((M[start][end][0]==0)&&(M[start][end][1]==0))){
        return M[start][end];
    }
    vector<int> ans(2,0);
    if(start>end){
        // cout<<"*** "<<start<<" "<<end<<endl;
        return ans;
    }
    if(start==end){
        if(A[start]=='T'){
            ans[0] = 1;
            ans[1] = 0;
            // cout<<start<<" T"<<endl;
            M[start][end] = ans;
            return ans;
        }
        ans[0] = 0;
        ans[1] = 1;
        // cout<<start<<" F"<<endl;
        M[start][end] = ans;
        return ans;
    }
    for(int i=(start+1); i<end; i=i+2){
        vector<int> ansL = myEvaluate(A, start, (i-1), M);
        vector<int> ansR = myEvaluate(A, (i+1), end, M);
        if(A[i]=='|'){
            ans[1] += ansL[1]*ansR[1];
            ans[1] %= 1003;
            ans[0] += ansL[0]*ansR[0] + ansL[0]*ansR[1] + ansL[1]*ansR[0];
            ans[0] %= 1003;
        }
        else{
            if(A[i]=='&'){
                ans[0] += ansL[0]*ansR[0];
                ans[0] %= 1003;
                ans[1] += ansL[0]*ansR[1] + ansL[1]*ansR[0] + ansL[1]*ansR[1];
                ans[1] %= 1003;
            }
            else{
                if(A[i]=='^'){
                    ans[0] += ansL[0]*ansR[1] + ansL[1]*ansR[0];
                    ans[0] %= 1003;
                    ans[1] += ansL[0]*ansR[0] + ansL[1]*ansR[1];
                    ans[1] %= 1003;
                }
            }
        }
    }
    // cout<<"*"<<start<<" "<<end<<" "<<ans[0]<<" "<<ans[1]<<endl;
    M[start][end] = ans;
    return ans;
}
int Solution::cnttrue(string A) {
    int n = A.length();
    vector<int > temp(2,0);
    vector<vector<int> > temp1(n, temp);
    vector<vector<vector<int> > > M(n, temp1);
    vector<int> ans = myEvaluate(A, 0, (n-1), M);
    return ans[0];
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
