/*
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)

*/

void merge(vector<int> &A, vector<int> &indices, int l, int m, int r){
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r - m;
    vector<int> L(n1, 0);
    vector<int> Li(n1,0);
    vector<int> R(n2, 0);
    vector<int> Ri(n2, 0);
    for(i=0; i<n1; i++){
        L[i] = A[l+i];
        Li[i] = indices[l+i];
    }
    for(i=0; i<n2; i++){
        R[i] = A[m+1+i];
        Ri[i] = indices[m+1+i];
    }
    i=0;
    j=0;
    k=l;
    while ((i<n1)&&(j<n2)){
        if(L[i]<=R[j]){
            A[k] = L[i];
            indices[k] = Li[i];
            i++;
        }
        else{
            A[k] = R[j];
            indices[k] = Ri[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        A[k] = L[i];
        indices[k] = Li[i];
        i++;
        k++;
    }
    while(j<n2){
        A[k] = R[j];
        indices[k] = Ri[j];
        j++;
        k++;
    }
}
void mergesort(vector<int> &A, vector<int> &indices, int l, int r){
    if(l<r){
        int m = l + (r-l)/2;
        mergesort(A, indices, l, m);
        mergesort(A, indices, m+1, r);
        merge(A, indices, l, m, r);
    }
}
int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    /*
    bool noSolution = true;
    for(int i=1;i<n; i++){
        if(A[i]>=A[i-1]){
            noSolution = false;
        }
    }
    if(noSolution){
        return -1;
    }
    */
    int ans = 0;
    vector<int> B(n,0);
    vector<int> indices(n,0);
    for(int i=0; i<n; i++){
        B[i] = A[i];
        indices[i] = i;
    }
    mergesort(B, indices, 0, (n-1));
    int max = 0;
    vector<int> max_indices(n,0);
    for(int i=(n-1); i>=0; i--){
        if(max<indices[i]){
            max = indices[i];
        }
        max_indices[i] = max;
    }
    for(int i=0; i<n; i++){
        if((max_indices[i] - indices[i])>ans){
            ans = max_indices[i] - indices[i];
        }
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
