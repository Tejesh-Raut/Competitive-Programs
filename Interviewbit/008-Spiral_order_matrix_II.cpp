/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Given n = 3,

You should return the following matrix:

[
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
]

*/

void fill_square(vector<vector<int> >& ans, int x_start, int x_end, int num_start, int num_end, int iter)
{
    int curr_num = num_start;
    
    for(int i=x_start; i<=x_end; i++){
        // cout<<curr_num<<" 1"<<endl;
        ans[x_start][i] = curr_num;
        curr_num++;
    }
    for(int i=(x_start+1); i<=x_end; i++){
        // cout<<curr_num<<" 2"<<endl;
        ans[i][x_end] = curr_num;
        curr_num++;
    }
    for(int i=(x_end-1); i>=x_start; i--){
        // cout<<curr_num<<" 3"<<endl;
        ans[x_end][i] = curr_num;
        curr_num++;
    }
    for(int i=(x_end-1); i>=(x_start+1); i--){
        // cout<<curr_num<<" 4"<<endl;
        ans[i][x_start] = curr_num;
        curr_num++;
    }
    for(int i=x_start; i<=x_end; i++){
        for(int j=x_start; j<=x_end; j++){
            // cout<<"ans"<<i<<j<<" = "<<ans[i][j]<<" ";
        }
        // cout<<endl;
    }
    // cout<<"**"<<iter<<"**"<<endl;
    if(num_start<=num_end){
        fill_square(ans, (x_start+1), (x_end-1), curr_num, num_end, iter+1);
        return;
    }
    else{
        return;
    }
}

vector<vector<int> > Solution::generateMatrix(int A) {
    vector<int> temp_row(A,0);
    vector<vector<int> > ans (A, temp_row);
    fill_square(ans, 0, (A-1), 1, (A*A), 0);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}

