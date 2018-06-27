/*
Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.


*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
void merge(vector<Interval> &A, int l, int m, int r){
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r - m;
    vector<Interval> L;
    for(int i=0; i<n1; i++){
        Interval inter; // = new Interval();
        L.push_back(inter);
    }
    vector<Interval> R;
    for(int i=0; i<n2; i++){
        Interval inter; // = new Interval();
        R.push_back(inter);
    }
    for(i=0; i<n1; i++){
        L[i].start = A[l+i].start;
        L[i].end = A[l+i].end;
    }
    for(i=0; i<n2; i++){
        R[i].start = A[m+1+i].start;
        R[i].end = A[m+1+i].end;
    }
    i=0;
    j=0;
    k=l;
    while ((i<n1)&&(j<n2)){
        if(L[i].start<=R[j].start){
            A[k].start = L[i].start;
            A[k].end = L[i].end;
            i++;
        }
        else{
            A[k].start = R[j].start;
            A[k].end = R[j].end;
            j++;
        }
        k++;
    }
    while(i<n1){
        A[k].start = L[i].start;
        A[k].end = L[i].end;
        i++;
        k++;
    }
    while(j<n2){
        A[k].start = R[j].start;
        A[k].end = R[j].end;
        j++;
        k++;
    }
}
void mergesort(vector<Interval> &A, int l, int r){
    if(l<r){
        int m = l + (r-l)/2;
        mergesort(A, l, m);
        mergesort(A, m+1, r);
        merge(A, l, m, r);
    }
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    vector<Interval> ans;
    int n= A.size();
    mergesort(A, 0, (n-1));
    int first =0;
    int last = 0;
    int max = A[0].end;
    for(int i=1; i<n; i++){
        if(A[i].start>max){
            Interval inter(A[first].start, A[last].end); // = new Interval(A[first].start, A[last].end);
            ans.push_back(inter);
            first = i;
            last = i;
            max = A[i].end;
        }
        if(max<A[i].end){
            max = A[i].end;
            last = i;
        }
    }
    Interval inter(A[first].start, A[last].end); // = new Interval(A[first].start, A[last].end);
    ans.push_back(inter);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
