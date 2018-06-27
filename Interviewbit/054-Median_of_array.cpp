/*
There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

The overall run time complexity should be O(log (m+n)).

Sample Input

A : [1 4 5]
B : [2 3]

Sample Output

3
 NOTE: IF the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element. 
For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5 

*/

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int n = A.size();
    int m = B.size();
    if(n==0){
        if((m%2)==0){
            return (((double)B[m/2]+(double)B[m/2-1])/2);
        }
        else{
            return B[m/2];
        }
    }
    if(m==0){
        if((n%2)==0){
            return (((double)A[n/2]+(double)A[n/2-1])/2);
        }
        else{
            return A[n/2];
        }
    }
    // vector<int> C((n+m),0);
    int i=0;
    int j=0;
    int mid = (n+m)/2;
    int l=0;
    int r=n-1;
    while(l<=r){
        i = l +(r-l)/2;
        j = mid -i-1;
        // cout<<"i "<<i<<" j "<<j<<endl;
        if((A[i]<=B[j+1])&&(B[j]<=A[i+1])){
            // cout<<"**i "<<i<<" j "<<j<<endl;
            if(((n+m)%2)!=0){
                if(A[i]>B[j]){
                    return A[i];
                }
                else{
                    return B[j];
                }
            }
            else{
                if(A[i]>B[j]){
                    if(A[i+1]<B[j+1]){
                        return (((double)A[i]+(double)A[i+1])/2);
                    }
                    else{
                        return (((double)A[i]+(double)B[j+1])/2);
                    }
                }
                else{
                    if(A[i+1]<B[j+1]){
                        return (((double)B[j]+(double)A[i+1])/2);
                    }
                    else{
                        return (((double)B[j]+(double)B[j+1])/2);
                    }
                }
            }
        }
        if(A[i]>B[j+1]){
            r = i;
        }
        else{
            l = i+1;
        }
    }
    return -1;
    // int tot=0;
    // while((i<n)&&(j<m)){
    //     for(int i1=1; tot<=mid; i1=(2*i1) ){
    //         if(A[(i+i1)]<B[j]){
    //             tot = i1;
    //         }
    //         else{
    //             break;
    //         }
    //     }
    // }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
