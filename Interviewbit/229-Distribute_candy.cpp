/*
There are N children standing in a line. Each child is assigned a rating value.

 You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Sample Input :

Ratings : [1 2]
Sample Output :

3
The candidate with 1 rating gets 1 candy and candidate with rating cannot get 1 candy as 1 is its neighbor. So rating 2 candidate gets 2 candies. In total, 2+1 = 3 candies need to be given out.


*/

int Solution::candy(vector<int> &ratings) {
    int n = ratings.size();
    int ans = 0;
    vector<int> v(n,1);
    for(int i=1; i<n; i++){
        if(ratings[i]>ratings[i-1]){
            v[i] = v[i-1]+1;
        }
    }
    for(int i=(n-1); i>0; i--){
        if(ratings[i-1]>ratings[i]){
            v[i-1] = max(v[i-1], (v[i]+1));
        }
    }
    for(int i=0; i<n; i++){
        ans += v[i];
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
