/*
You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K painters available and you are also given how much time a painter takes to paint 1 unit of board. You have to get this job done as soon as possible under the constraints that any painter will only paint contiguous sections of board.

2 painters cannot share a board to paint. That is to say, a board
cannot be painted partially by one painter, and partially by another.
A painter will only paint contiguous boards. Which means a
configuration where painter 1 paints board 1 and 3 but not 2 is
invalid.
Return the ans % 10000003

Input :
K : Number of painters
T : Time taken by painter to paint 1 unit of board
L : A List which will represent length of each board

Output:
     return minimum time to paint all boards % 10000003
Example

Input : 
  K : 2
  T : 5
  L : [1, 10]
Output : 50
*/
bool isPossible(long long t, int num_workers, vector<int> &C){
    long long sum=0;
    int n = C.size();
    int k=0;
    for(int i=0; i<n; i++){
        sum = sum + (long long )C[i];
        if(sum>t){
           k++;
           sum = (long long)C[i];
           if(sum>t){
               return false;
           }
        }
    }
    k++;
    if(k<=num_workers){
        // cout<<"*"<<k<<endl;
        return true;
    }
    else{
        return false;
    }
}
int Solution::paint(int A, int B, vector<int> &C) {
    int n = C.size();
    long long l, r;
    l =0;
    r = 0;
    for(int i=0; i<n; i++){
        r = r + (long long ) C[i];
    }
    long long oldm=-1;
    while(l<r){
        // cout<<"l "<<l<<" r "<<r<<endl;
        long long m = l +(r-l)/2 ;
        if(oldm==l){
            break;
        }
        if(isPossible(m, A, C)){
            // cout<<"possible with "<<m<<endl;
            r = m;
        }
        else{
            // cout<<"not possible with "<<m<<endl;
            l = m+1;
        }
        oldm = m;
    }
    long long ans = (l*((long long)B))%10000003;
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
