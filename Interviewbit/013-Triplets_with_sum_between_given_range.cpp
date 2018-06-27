/*
Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 . 
Return 1 for true or 0 for false.

Example:

Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

You should return 1

as

0.6+0.7+0.4=1.7

1<1.7<2

Hence, the output is 1.

O(n) solution is expected.

Note: You can assume the numbers in strings don’t overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed.
*/

bool liesinX(string str){
    int n = str.length();
    if(str[0]!='0'){
        return false;
    }
    if(int i=2; i<n; i++){
        if(str[i]>'6'){
            return false;
        }
        if(str[i]<'6'){
            return true;
        }
    }
    return true;
}
bool liesinY(string str){
    if(str[0]=='0'){
        return true;
    }
    if((str[0]<'0')||(str[0]>'9')){
        return false;
    }
    if(str[0]>='2'){
        return false;
    }
    if(str[0]=='1'){
        int n = str.length();
        for(int i=2; i<n; i++){
            if(str[i]!='0'){
                return false;
            }
        }
        return true;
    }
    return false;
}
bool liesinZ(string str){
    int n = str.length();
    if(str[0]=='1'){
        if(n>1){
            if(str[1]=='.'){
                return true;
            }
            else{
                return false;
            }
        }
        return true;
    }
    return false;
}
bool islessthan(string str1, string str2){
    int l1 = str1.length();
    int l2 = str2.length();
    if(l1<l2){
        for(int i=0; i<l1; i++){
            if(str1[i]<str2[i]){
                return true;
            }
            if(str1[i]>str2[i]){
                return false;
            }
        }
        return true;
    }
    else{
        for(int i=0; i<l2; i++){
            if(str1[i]<str2[i]){
                return true;
            }
            if(str1[i]>str2[i]){
                return false;
            }
        }
        return false;
    }
    return false;
}
int Solution::solve(vector<string> &A) {
    int n = A.size();
    // X = (0,2/3), Y = [2/3,1], Z = (1,2)
    vector<string> X;
    vector<string> Y;
    vector<string> Z;
    for(int i=0; i<n; i++){
        if(liesinX(A[i])){
            X.push_back(A[i]);
        }
        else{
            if(liesinY(A[i])){
                Y.push_back(A[i]);
            }
            else{
                if(liesinZ(A[i])){
                    Z.push_back(A[i]);
                }
            }
        }
    }
    int Xs = X.size();
    int Ys = Y.size();
    int Zs = Z.size();
    
    // |X| >= 3 and Xmax(1) + Xmax(2) + Xmax(3) >= 1
    // |X| >= 2, |Z| >= 1, and Xmin(1)+Xmin(2)+Zmin(1) <= 2
    // |X| >= 1, |Y| >= 2, and Xmin(1)+Ymin(1)+Ymin(2) <= 2
    // |X| >= 1, |Y| >= 1, |Z| >= 1, and Xmin(1)+Ymin(1)+Zmin(1) <= 2
    // |X| >= 2, |Y| >= 1, and Xmax(1) + Xmax(2) + Ymin(1) < 2
    // |X| >= 2, |Y| >= 1, and Xmin(1) + Xmin(2) + Ymax(1) > 1)
    return 0;
}
