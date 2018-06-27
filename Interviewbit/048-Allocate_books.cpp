/*
N number of books are given. 
The ith book has Pi number of pages. 
You have to allocate books to M number of students so that maximum number of pages alloted to a student is minimum. A book will be allocated to exactly one student. Each student has to be allocated at least one book. Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.

NOTE: Return -1 if a valid assignment is not possible

Input:

List of Books
M number of students
Your function should return an integer corresponding to the minimum number.

Example:

P : [12, 34, 67, 90]
M : 2

Output : 113

There are 2 number of students. Books can be distributed in following fashion : 
  1) [12] and [34, 67, 90]
      Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
  2) [12, 34] and [67, 90]
      Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
  3) [12, 34, 67] and [90]
      Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages

Of the 3 cases, Option 3 has the minimum pages = 113. 


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
int Solution::books(vector<int> &C, int A) {
    int B=1;
    int n = C.size();
    if(n<A){
        return -1;
    }
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
    long long ans = l;
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
