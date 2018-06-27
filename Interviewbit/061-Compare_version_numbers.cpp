/*
Compare two version numbers version1 and version2.

If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 1.13 < 1.13.4

*/

int compareNum(string &A, int s1, int e1, string &B, int s2, int e2){
    if(e2<s2){
        for(int i=s1; i<=e1; i++){
            if(A[i]!='0'){
                return 1;
            }
        }
        return 0;
    }
    if(e1<s1){
        for(int i=s2; i<=e2; i++){
            if(B[i]!='0'){
                return -1;
            }
        }
        return 0;
    }
    if((e1-s1)>(e2-s2)){
        for(int i=s1; i<(s1+(e1-e2+s2-s1)); i++){
            // cout<<"-"<<i<<endl;
            if(A[i]!='0'){
                return 1;
            }
        }
        return 0;
    }
    if((e1-s1)<(e2-s2)){
        for(int i=s2; i<(s2-(e1-e2+s2-s1)); i++){
            // cout<<"+"<<i<<endl;
            if(B[i]!='0'){
                return -1;
            }
        }
        return 0;
    }
    // equal length
    int i=s1;
    int j=s2;
    while((i<=e1)&&(j<=e2)){
        if((A[i]-B[j])>0){
            return 1;
        }
        if((A[i]-B[j])<0){
            return -1;
        }
        i++;
        j++;
    }
    return 0;
}

int Solution::compareVersion(string A, string B) {
    int m, n;
    m = A.length();
    n = B.length();
    int s1, s2, e1, e2;
    s1  = s2 = e1 = e2 = 0;
    int i, j;
    i=0; j=0;
    while((i<m)||(j<n)){
        
        for(i=s1; i<m; i++){
            if(A[i]=='.'){
                e1 = i-1;
                break;
            }
        }
        if(i==m){
            e1 = m-1;
        }
        for(j=s2;j<n; j++){
            if(B[j]=='.'){
                e2 = j-1;
                break;
            }
        }
        if(j==n){
            e2 = n-1;
        }
        // cout<<"*"<<s1<<" "<<e1<<endl;
        // cout<<"*"<<s2<<" "<<e2<<endl;
        // cout<<"*"<<compareNum(A, s1, e1, B, s2, e2)<<endl;
        if(compareNum(A, s1, e1, B, s2, e2)==1){
            return 1;
        }
        else{
            if(compareNum(A, s1, e1, B, s2, e2)==-1){
                return -1;
            }
        }
        s1 = e1+2;
        s2 = e2+2;
    }
    return 0;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
