/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:

int isMatch(const char *s, const char *p)
Some examples:

isMatch("aa","a") → 0
isMatch("aa","aa") → 1
isMatch("aaa","aa") → 0
isMatch("aa", "a*") → 1
isMatch("aa", ".*") → 1
isMatch("ab", ".*") → 1
isMatch("aab", "c*a*b") → 1
Return 0 / 1 ( 0 for false, 1 for true ) for this problem


*/

bool isMatch1(string s, string p){
    if (p.empty()){
        return s.empty();
    }
    if ('*' == p[1]){
        return (isMatch1(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch1(s.substr(1), p));
    }
    else{
        return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch1(s.substr(1), p.substr(1));
    }
}
int Solution::isMatch(const string &s, const string &p) {
    string s1 = s;
    string p1 = p;
    if(isMatch1(s1, p1)){
        return 1;
    }
    else{
        return 0;
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
