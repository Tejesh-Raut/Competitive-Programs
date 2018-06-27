/*
You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

Find i, j, k such that :
max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

**abs(x) is absolute value of x and is implemented in the following manner : **

      if (x < 0) return -x;
      else return x;
Example :

Input : 
        A : [1, 4, 10]
        B : [2, 15, 20]
        C : [10, 12]

Output : 5 
         With 10 from A, 15 from B and 10 from C. 

*/

int max(int a, int b, int c){
    int max  =a;
    if(b>max){
        max = b;
    }
    if(c>max){
        max = c;
    }
    return max;
}
int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int n1 = A.size();
    int n2 = B.size();
    int n3 = C.size();
    int score;
    int min_score = INT_MAX;
    int i=0;
    int j = 0;
    int k =0;
    while((i<n1)&&(j<n2)&&(k<n3)){
        score = max(abs(A[i]-B[j]),abs(B[j]-C[k]),abs(C[k]-A[i]));
        if(score<min_score){
            min_score = score;
        }
        if((A[i]<=B[j])&&(A[i]<=C[k])){
            i++;
        }
        else{
            if((B[j]<=C[k])&&(B[j]<=C[k])){
                j++;
            }
            else{
                k++;
            }
        }
    }
    return min_score;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
