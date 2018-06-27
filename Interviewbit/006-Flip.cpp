/*
You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

Notes:

Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
For example,

S = 010

Pair of [L, R] | Final string
_______________|_____________
[1 1]          | 110
[1 2]          | 100
[1 3]          | 101
[2 2]          | 000
[2 3]          | 001

We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].
Another example,

If S = 111

No operation can give us more than three 1s in final string. So, we return empty array [].
*/

vector<int> Solution::flip(string A) {
    int len = A.length();
    vector<int> ans(2,1);
    vector<int> num1(len, 0);
    vector<int> num0(len, 0);
    vector<int> score(len, 0);
    if(A.at(0) == '0'){
        num0[0] = 1;
    }
    else{
        num1[0] = 1;
    }
    score[0] = num0[0] - num1[0];
    for(int i=1; i<len; i++){
        if(A.at(i) == '0'){
            num0[i] = num0[i-1] +1;
            num1[i] = num1[i-1];
        }
        else{
            num0[i] = num0[i-1];
            num1[i] = num1[i-1]+1;
        }
        score[i] = num0[i] - num1[i];
    }
    if(num0[len-1] == 0){
        vector<int> ans0;
        return ans0;
    }
    vector<int> mini(len, 0);
    vector<int> minii(len, 0);
    vector<int> maxi(len, 0);
    vector<int> maxii(len, 0);
    mini[0] = 0;
    minii[0] = -1;
    for(int i=1; i<len; i++){
        if(score[i-1]<mini[i-1]){
            mini[i] = score[i-1];
            minii[i] = (i-1);
        }
        else{
            mini[i] = mini[i-1];
            minii[i] = minii[i-1];
        }
    }
    maxi[len-1] = score[len-1];
    maxii[len-1] = len-1;
    for(int i=(len-2); i>=0; i--){
        if(maxi[i+1]<=score[i]){
            maxi[i] = score[i];
            maxii[i] = i;
        }
        else{
            maxi[i] = maxi[i+1];
            maxii[i] = maxii[i+1];
        }
    }
    int max = score[0];
    for(int i=0; i<len; i++){
        if((maxi[i]-mini[i])>max){
            max = maxi[i] - mini[i];
            ans[0] = minii[i]+2;
            ans[1] = maxii[i]+1;
        }
    }
    return ans;
}
