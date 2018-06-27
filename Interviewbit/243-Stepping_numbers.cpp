/*
Given N and M find all stepping numbers in range N to M

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.
e.g 123 is stepping number, but 358 is not a stepping number

Example:

N = 10, M = 20
all stepping numbers are 10 , 12 
Return the numbers in sorted order.


*/

void myFunction(int &A, int &B, int stepNum, vector<int> &ans){
    if(stepNum>=A && stepNum<=B){
        ans.push_back(stepNum);
    }
    if(stepNum==0 || stepNum>B){
        return;
    }
    int last = stepNum %10;
    int a1 = stepNum*10+ last+1;
    int a2 = stepNum*10+ last-1;
    if(last>0 && last<9){
        myFunction(A, B, a1, ans);
        myFunction(A, B, a2, ans);
        return;
    }
    if(last==0){
        myFunction(A, B, a1, ans);
        return;
    }
    if(last==9){
        myFunction(A, B, a2, ans);
        return;
    }
}
vector<int> Solution::stepnum(int A, int B) {
    vector<int> ans;
    for(int i=0; i<=9; i++){
        myFunction(A, B, i, ans);
    }
    sort(ans.begin(), ans.end());
    int len = ans.size();
    if(len==0){
        return ans;
    }
    vector<int> final_ans;
    final_ans.push_back(ans[0]);
    for(int i=1; i<len; i++){
        if(ans[i]!=ans[i-1]){
            final_ans.push_back(ans[i]);
        }
    }
    return final_ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
