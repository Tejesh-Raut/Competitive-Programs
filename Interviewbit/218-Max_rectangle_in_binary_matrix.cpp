/*
Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A : [  1 1 1
       0 1 1
       1 0 0 
    ]

Output : 4 

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)


*/

int maxHist(vector<int> &hist){
    int n = hist.size();
    stack<int> s;
    int max_area = 0;
    int tp;
    int area_with_top;
    int i=0;
    while (i < n){
        if (s.empty() || hist[s.top()] <= hist[i]){
            s.push(i++);
        }
        else{
            tp = s.top();
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            if (max_area < area_with_top){
                max_area = area_with_top;
            }
        }
    }
    while (s.empty() == false){
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
        if (max_area < area_with_top){
            max_area = area_with_top;
        }
    }
    return max_area;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {
    int n = A.size();
    if(n==0){
        return 0;
    }
    int m = A[0].size();
    vector<int> v(m,0);
    // cout<<"*"
    int ans = 0;
    int area = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j]==0){
                v[j]=0;
            }
            else{
                v[j]++;
            }
        }
        area = maxHist(v);
        // int max =0;
        if(area>ans){
            ans = area;
        }
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
