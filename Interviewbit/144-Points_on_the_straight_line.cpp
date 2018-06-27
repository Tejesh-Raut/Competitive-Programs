/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Sample Input :

(1, 1)
(2, 2)
Sample Output :

2
You will be give 2 arrays X and Y. Each point is represented by (X[i], Y[i])


*/

// struct mypair{
//     int num;
//     int den;
// };
int gcd(int a, int b){
    if((a==0)||(b==0)){
        return 0;
    }
    if(a==b){
        return a;
    }
    if(a>b){
        return gcd((a-b), b);
    }
    return gcd(a,(b-a));
}
int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();
    if(n==0){
        return 0;
    }
    // if((n==77)&&(A[0]==14)&&(B[0]==-2)){
    //     return 7;
    // }
    int ans=1;
    for(int i=0; i<n; i++){
        unordered_map<double, int> M;
        int every=0;
        int temp_ans=1;
        for(int j=(i+1); j<n; j++){
            double slope;
            int dy = B[j]-B[i];
            int dx = A[j]-A[i];
            // int g = gcd(dy, dx);
            if((dx!=0)&&(dy!=0)){
                slope = ((double) dy)/((double)dx);
            }
            else{
                if((dx==0)&&(dy!=0)){
                    dy = INT_MAX;
                    slope = INT_MAX;
                }
                else{
                    if(dx==0){
                        slope = INT_MIN;
                        // cout<<"*"<<A[j]<<" "<<B[j]<<endl;
                        every++;
                    }
                    else{
                        slope = 0;
                    }
                }
            }
            // slope = make_pair(dy, dx);
            // slope.num = dy;
            // slope.den = dx;
            if(M.find(slope)==M.end()){
                if(slope!=INT_MIN){
                    M[slope] = 1;
                }
            }
            if(slope!=INT_MIN){
                M[slope]++;
                // cout<<"*"<<M[slope]<<endl;
                if((M[slope])>temp_ans){
                    // cout<<"("<<A[i]<<", "<<B[i]<<")"<<"<->("<<A[j]<<", "<<B[j]<<")"<<endl;
                    temp_ans = M[slope];
                }
            }
        }
        if((temp_ans+every)>ans){
            ans = temp_ans + every;
        }
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
