/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.


*/

bool compare(int A, int B){ // returns true if A is bigger than B
    stringstream ssAB;
    ssAB<<A<<B;
    stringstream ssBA;
    ssBA<<B<<A;
    
    string AB = ssAB.str();
    string BA = ssBA.str();
    int n = AB.length();
    for(int i=0; i<n; i++){
        if(AB[i]>BA[i]){
            return true;
        }
        if(AB[i]<BA[i]){
            return false;
        }
    }
    return true;
    /*
    int a = A.size();
    int b = B.size();
    int c;
    if(a<b){
        c= a;
    }
    else{
        c=b;
    }
    for(int i=0; i<c; i++){
        if(A[i]<B[i]){
            return false;
        }
        else{
            if(A[i]>B[i]){
                return true;
            }
        }
    }
    if(c==a){
        for(int i=c; i<b; i++){
            if(B[i]!=A[0]){
                if(B[i]>A[0]){
                    return false;
                }
                else{
                    return true;
                }
            }
        }
        return true;
    }
    else{
        for(int i=c; i<a; i++){
            if(A[i]!=A[0]){
                if(A[i]>=A[0]){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        return false;
    }
    return true;
    */
}
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
        if(compare(L[i], R[j])){
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
string Solution::largestNumber(const vector<int> &A) {
    int n = A.size();
    vector<int> B(n,0);
    for(int i=0; i<n; i++){
        B[i] = A[i];
    }
    stringstream ansss;
    mergesort(B, 0, (n-1));
    for(int i=0; i<n; i++){
        ansss<<B[i];
    }
    /*
    vector<bool> AsFlag(n, true);
    int max;
    int maxi = 0;
    for(int i=0; i<n; i++){
        max = 0;
        for(int j=0; j<n; j++){
            if(AsFlag[j]){
                if(compare(A[j], max)){
                    max = A[j];
                    maxi = j;
                }
            }
        }
        AsFlag[maxi] = false;
        ansss<<max;
    }
    */
    string ans = ansss.str();
    ans.erase(0, min(ans.find_first_not_of('0'), ans.size()-1));
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
