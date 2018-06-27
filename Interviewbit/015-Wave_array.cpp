/*
Given an array of integers, sort the array into a wave like array and return it, 
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

Example

Given [1, 2, 3, 4]

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]
 NOTE : If there are multiple answers possible, return the one thats lexicographically smallest. 
So, in example case, you will return [2, 1, 4, 3] 

*/

void merge(vector<int> &A, int l, int m, int r){
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r - m;
    vector<int> L(n1, 0);
    vector<int> R(n2, 0);
    for(i=0; i<n1; i++){
        L[i] = A[l+i];
    }
    for(i=0; i<n2; i++){
        R[i] = A[m+1+i];
    }
    i=0;
    j=0;
    k=l;
    while ((i<n1)&&(j<n2)){
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        A[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        A[k] = R[j];
        j++;
        k++;
    }
}
void mergesort(vector<int> &A, int l, int r){
    if(l<r){
        int m = l + (r-l)/2;
        mergesort(A, l, m);
        mergesort(A, m+1, r);
        merge(A, l, m, r);
    }
}
vector<int> Solution::wave(vector<int> &A) {
    int n= A.size();
    vector<int> B(n,0);
    for(int i=0; i<n; i++){
        B[i] = A[i];
    }
    mergesort(B, 0, (n-1));
    // return B;
    vector<int> C(n,0);
    int j=1;
    for(int i=0; i<n; i= i+2){
        C[j] = B[i];
        j = j+2;
    }
    j=0;
    for(int i=1; i<n; i =i+2){
        C[j] = B[i];
        j = j+2;
    }
    if((n%2)!=0){
        C[n-1] = B[n-1];
    }
    return C;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
