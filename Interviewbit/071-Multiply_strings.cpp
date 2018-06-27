/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

 Note: The numbers can be arbitrarily large and are non-negative.
Note2: Your answer should not have leading zeroes. For example, 00 is not a valid answer. 
For example, 
given strings "12", "10", your answer should be “120”.

NOTE : DO NOT USE BIG INTEGER LIBRARIES ( WHICH ARE AVAILABLE IN JAVA / PYTHON ). 
We will retroactively disqualify such submissions and the submissions will incur penalties.


*/

string Solution::multiply(string A, string B) {
    string ans="";
    int n1 = A.length();
    int n2 = B.length();
    if((n1==0)||(n2==0)){
        return "0";
    }
    vector<int> result((n1+n2), 0);
    int i_n1=0;
    int i_n2=0;
    for(int i=(n1-1); i>=0; i--){
        int carry = 0;
        int n1 = A[i]-'0';
        i_n2=0;
        for(int j=(n2-1); j>=0;j--){
            int n2 = B[j]-'0';
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            carry = sum/10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if (carry > 0){
            result[i_n1 + i_n2] += carry;
        }
        i_n1++;
    }
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0){
        i--;
    }
    if (i == -1){
        return "0";
    }
    while (i >= 0){
        ans += to_string(result[i--]);
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
