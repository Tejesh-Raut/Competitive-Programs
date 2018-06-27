/*
Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]
Sample Output:

1
If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1


*/

int Solution::repeatedNumber(const vector<int> &A) {
    int n= A.size();
    vector<bool> B((n-1),false);
    int ans = 0;
    for(int i=0; i<n; i++){
        if(B[A[i]-1]){
            ans = A[i];
            break;
        }
        B[A[i]-1] = true;
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
