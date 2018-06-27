/*
Given a N cross M matrix in which each row is sorted, find the overall median of the matrix. Assume N*M is odd.

For example,

Matrix=
[1, 3, 5]
[2, 6, 9]
[3, 6, 9]

A = [1, 2, 3, 3, 5, 6, 6, 9, 9]

Median is 5. So, we return 5.
Note: No extra memory is allowed.


*/

int Solution::findMedian(vector<vector<int> > &A) {
    int n= A.size();
    if(n==0){
        return -1;
    }
    int m = A[0].size();
    int min = A[0][0];
    int max= A[0][0];
    for(int i=0; i<n; i++){
        if(min>A[i][0]){
            min = A[i][0];
        }
        if(max<A[i][m-1]){
            max = A[i][m-1];
        }
    }
    int element = (n*m+1)/2;
    while(min<max){
        // cout<<"min "<<min<<" max "<<max<<endl;
        int mid = min + (max - min) / 2;
        int count = 0;
        for(int i=0; i<n; i++){
            // cout<<i<<endl;
            int count1=0;
            int l = 0;
            int r = m-1;
            while(l<=r){
                int mid1= l+(r-l)/2;
                if(A[i][mid1]==mid){
                    // count1 = mid1+1;
                    // count1++;
                }
                if(A[i][mid1]<=mid){
                    count1 +=(mid1+1-l);
                    l = mid1+1;
                }
                else{
                    r =mid1 -1;
                }
            }
            // cout<<"count1 "<<count1<<endl;
            count += count1;
        }
        // cout<<count<<endl;
        if(count<element){
            min = mid +1;
        }
        else{
            max = mid;
        }
    }
    return min;
}
