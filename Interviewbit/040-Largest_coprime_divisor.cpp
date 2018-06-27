/*
You are given two positive numbers A and B. You need to find the maximum valued integer X such that:

X divides A i.e. A % X = 0
X and B are co-prime i.e. gcd(X, B) = 1
For example,

A = 30
B = 12
We return
X = 5

*/

int gcd(int a, int b){
    if((a==0)||(b==0)){
        return 0;
    }
    if(a==b){
        return a;
    }
    if(a>b){
        return gcd(a-b, b);
    }
    else{
        return gcd(a, b-a);
    }
}
int Solution::cpFact(int A, int B) {
    int n = -1;
    int gcdab = gcd(A,B);
    if(gcdab==1){
        return A;
    }
    int fac;
    for(int i=2; i<=A; i++){
        if((A%i)==0){
            fac = A/i;
            if(gcd(fac, B)==1){
                n = fac;
                break;
            }
        }
    }
    /*
    for(int i=1; i<=A; i++){
        if((A%i)==0){
            if(gcdab(i,B)==1){
                n = i;
            }
        }
    }
    */
    return n;
}
