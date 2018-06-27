/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example :

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"

*/

string Solution::fractionToDecimal(int numerator, int denominator) {
    string ans="";
    long q = abs((long)numerator)/abs((long)denominator);
    long r = abs((long)numerator)%abs((long)denominator);
    if(((long long)numerator)*((long long)denominator)<0){
        ans="-";
    }
    // long q = (((long) numerator)-r)/((long)denominator);
    // cout<<q<<endl;
    ans += to_string(q);
    if(r==0){
        return ans;
    }
    ans += ".";
    // cout<<"*"<<r<<endl;
    int i = ans.length();
    int start = -1;
    unordered_map<long, int> M;
    while(r!=0){
        if(M.find(r)!=M.end()){
            start = M[r];
            ans+= ')';
            break;
        }
        M[r] = i;
        q = (r*10)/abs((long)denominator);
        r = (r*10)%abs((long)denominator);
        char c = '0'+ q;
        ans += c;
        i++;
    }
    if(r!=0){
        ans.insert(ans.begin()+start, '(');
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
