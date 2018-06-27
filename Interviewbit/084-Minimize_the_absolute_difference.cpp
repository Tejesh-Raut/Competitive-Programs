/*
Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :

Input:

A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output:

1
Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.


*/

vector<int> myMax(int a, int b, int c){
    int max, maxi;
    max = a;
    maxi=0;
    if(b>max){
        max = b;
        maxi=1;
    }
    if(c>max){
        max = c;
        maxi = 2;
    }
    vector<int > ans(2,0);
    ans[0] = maxi;
    ans[1] = max;
    return ans;
}
vector<int> myMin(int a, int b, int c){
    int max, maxi;
    max = a;
    maxi=0;
    if(b<max){
        max = b;
        maxi=1;
    }
    if(c<max){
        max = c;
        maxi = 2;
    }
    vector<int > ans(2,0);
    ans[0] = maxi;
    ans[1] = max;
    return ans;
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int n1 = A.size();
    int n2 = B.size();
    int n3 = C.size();
    int score = INT_MAX;
    int curr;
    int i,j,k;
    i=0;
    j=0;
    k=0;
    vector<int> c,d;
    while((i<n1)&&(j<n2)&&(k<n3)){
        c = myMin(A[i], B[j], C[k]);
        d = myMax(A[i], B[j], C[k]);
        // cout<<i<<" "<<j<<" "<<k<<" "<<c
        if((d[1]-c[1])<score){
            score = d[1]-c[1];
        }
        if(c[0]==0){
           i++;
        }
        else{
            if(c[0]==1){
                j++;
            }
            else{
                if(c[0]==2){
                    k++;
                }
            }
        }
    }
    return score;
}
