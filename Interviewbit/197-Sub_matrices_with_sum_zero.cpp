/*
Given a 2D matrix, find the number non-empty sub matrices, such that the sum of the elements inside the sub matrix is equal to 0. (note: elements might be negative).

Example:

Input

-8 5  7
3  7 -8
5 -8  9
Output
2

Explanation
-8 5 7
3 7 -8
5 -8 9

-8 5 7
3 7 -8
5 -8 9


*/

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    if(n==0){
        return 0;
    }
    int m = A[0].size();
    vector<int> temp(m,0);
    vector<vector<int> > B(n, temp);
    for(int i=0; i<n; i++){
        int temp_sum=0;
        for(int j=0; j<m; j++){
            temp_sum += A[i][j];
            if(i==0){
                B[i][j] = temp_sum;
            }
            else{
                B[i][j] = B[i-1][j]+temp_sum;
            }
        }
    }
    int ans=0;
    for(int i1=0; i1<n; i1++){
        for(int j1=0; j1<m; j1++){
            for(int i2=i1; i2<n; i2++ ){
                for(int j2=j1; j2<m; j2++){
                    int sum = B[i2][j2];
                    if((i1-1)>=0){
                        sum -= B[i1-1][j2];
                    }
                    if((j1-1)>=0){
                        sum -= B[i2][j1-1];
                    }
                    if(((i1-1)>=0)&&((j1-1)>=0)){
                        sum += B[i1-1][j1-1];
                    }
                    if(sum==0){
                        ans++;
                    }
                }
            }
        }
    }
    return ans;
}
