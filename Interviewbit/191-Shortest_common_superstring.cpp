/*
Given a set of strings. Find the length of smallest string which
has all the strings in the set as substring

Constraints:
1) 1 <= Number of strings <= 18
2) Length of any string in the set will not exceed 100.

Example:
Input: [“abcd”, “cdef”, “fgh”, “de”]
Output: 8 (Shortest string: “abcdefgh”)


*/

int min(int a, int b){
    return (a < b) ? a : b;
}
int findOverlappingPair(string str1, string str2, string &str){
    int max = INT_MIN;
    int len1 = str1.length();
    int len2 = str2.length();
    for (int i = 1; i <= min(len1, len2); i++){
        if (str1.compare(len1-i, i, str2, 0, i) == 0){
            if (max < i){
                max = i;
                str = str1 + str2.substr(i);
            }
        }
    }
    for (int i = 1; i <= min(len1, len2); i++){
        if (str1.compare(0, i, str2, len2-i, i) == 0){
            if (max < i){
                max = i;
                str = str2 + str1.substr(i);
            }
        }
    }
    return max;
}
int Solution::solve(vector<string> &A) {
    int n = A.size();
    while(n!=1){
        int max = INT_MIN;
        int l, r;
        string resStr;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                string str;
                int res = findOverlappingPair(A[i], A[j], str);
                if (max < res){
                    max = res;
                    resStr.assign(str);
                    l = i, r = j;
                }
            }
        }
        n--;
        if (max == INT_MIN){
            A[0] += A[n];
        }
        else{
            A[l] = resStr;
            A[r] = A[n];
        }
    }
    // cout<<"* "<<A[0]<<endl;
    return A[0].length();
}
