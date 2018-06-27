/*
A hotel manager has to process N advance bookings of rooms for the next season. His hotel has K rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .

Input:


First list for arrival time of booking.
Second list for departure time of booking.
Third is K which denotes count of rooms.

Output:

A boolean which tells whether its possible to make a booking. 
Return 0/1 for C programs.
O -> No there are not enough rooms for N booking.
1 -> Yes there are enough rooms for N booking.
Example :

Input : 
        Arrivals :   [1 3 5]
        Departures : [2 6 8]
        K : 1

Return : False / 0 

At day = 5, there are 2 guests in the hotel. But I have only one room. 

*/

void merge(vector<int> &A,vector<bool> &adf, int l, int m, int r){
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r - m;
    vector<int> L(n1, 0);
    vector<bool> Lf(n1,false);
    vector<int> R(n2, 0);
    vector<bool> Rf(n2, false);
    for(i=0; i<n1; i++){
        L[i] = A[l+i];
        Lf[i] = adf[l+i];
    }
    for(i=0; i<n2; i++){
        R[i] = A[m+1+i];
        Rf[i] = adf[m+1+i];
    }
    i=0;
    j=0;
    k=l;
    while ((i<n1)&&(j<n2)){
        if(L[i]<R[j]){
            A[k] = L[i];
            adf[k] = Lf[i];
            i++;
        }
        else{
            A[k] = R[j];
            adf[k] = Rf[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        A[k] = L[i];
        adf[k] = Lf[i];
        i++;
        k++;
    }
    while(j<n2){
        A[k] = R[j];
        adf[k] = Rf[j];
        j++;
        k++;
    }
}
void mergesort(vector<int> &A,vector<bool> &adf, int l, int r){
    if(l<r){
        int m = l + (r-l)/2;
        mergesort(A, adf, l, m);
        mergesort(A, adf, m+1, r);
        merge(A, adf, l, m, r);
    }
}
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int n = arrive.size();
    vector<int> ad((2*n), 0);
    vector<bool> adf((2*n), false);
    for(int i=0; i<n; i++){
        ad[i] = arrive[i];
        ad[n+i] = depart[i];
        adf[i] = true;
    }
    mergesort(ad, adf, 0, (2*n-1));
    int curr, max;
    curr=0;
    max=0;
    for(int i=0; i<(2*n); i++){
        if(adf[i]){
            curr++;
            if(curr>max){
                max = curr;
            }
        }
        else{
            curr--;
        }
        // cout<<curr<<endl;
    }
    // cout<<"*"<<endl;
    if(max<=K){
        return true;
    }
    else{
        return false;
    }
}
