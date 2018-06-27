/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' : Matches any single character.
'*' : Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

The function prototype should be:

int isMatch(const char *s, const char *p)
Examples :

isMatch("aa","a") → 0
isMatch("aa","aa") → 1
isMatch("aaa","aa") → 0
isMatch("aa", "*") → 1
isMatch("aa", "a*") → 1
isMatch("ab", "?*") → 1
isMatch("aab", "c*a*b") → 0
Return 1/0 for this problem.


*/

/*
bool myFunc(string &s, int posS, int &ns, string &p, int posP, int &np, vector<vector<int> > &M){
    int is = posS;
    int ip = posP;
    if((ip==(np-1))&&(p[ip]=='*')){
        return true;
    }
    if((is>=ns)||(ip>=np)){
        if((is>=ns)&&(ip>=np)){
            return true;
        }
        else{
            if((ip==(np-1))&&(p[ip]=='*')){
                return true;
            }
            // cout<<"F "<<is<<"/"<<ns<<" "<<ip<<"/"<<np<<endl;
            return false;
        }
    }
    if(M[is][ip]!=-1){
        if(M[posS][posP]==0){
            return false;
        }
        else{
            return true;
        }
    }
    while((s[is]==p[ip])||(p[ip]=='?')){
        is++;
        ip++;
        if((is>=ns)||(ip>=np)){
            break;
        }
    }
    if((is>=ns)||(ip>=np)){
        if((is>=ns)&&(ip>=np)){
            M[posS][posP] = 1; 
            return true;
        }
        else{
            if((ip==(np-1))&&(p[ip]=='*')){
                M[posS][posP] = 1;
                return true;
            }
            // cout<<"F "<<is<<"/"<<ns<<" "<<ip<<"/"<<np<<endl;
            M[posS][posP] = 0;
            return false;
        }
    }
    else{
        if(p[ip]!='*'){
            // cout<<"F "<<is<<"/"<<ns<<" "<<ip<<"/"<<np<<endl;
            M[posS][posP]=0;
            return false;
        }
        else{
            while(p[ip]=='*'){
                ip++;
                if(ip>=np){
                    break;
                }
            }
            ip--;
            bool ans1 = myFunc(s, is, ns, p, (ip+1), np, M);
            if(ans1){
                M[posS][posP] = 1;
                return true;
            }
            bool ans2 = myFunc(s, (is+1), ns, p, ip, np, M);
            if(ans2){
                M[posS][posP] = 1;
            }
            else{
                M[posS][posP] = 0;
            }
            return (ans2);
        }
    }
}
*/
bool isMatch1(string s, string p){
    // cout<<"* "<<s<<" "<<p<<endl;
    if(p.empty()){
        return s.empty();
    }
    if('*'==p[0]){
        return ((isMatch1(s, p.substr(1)))||((!s.empty())&&isMatch1(s.substr(1), p)));
    }
    else{
        return ((!s.empty())&&(s[0] == p[0] || '?' == p[0])&&(isMatch1(s.substr(1), p.substr(1))));
    }
}
int Solution::isMatch(const string &s, const string &p) {
    int is, ip;
    string s1 = s;
    string p1 = p;
    if(isMatch1(s1, p1)){
        return 1;
    }
    else{
        return 0;
    }
    /*
    is = 0;
    ip = 0;
    int ns = s.length();
    int np = p.length();
    vector<int> temp(np, -1);
    vector<vector<int> > M(ns, temp);
    if(myFunc(s1, is, ns, p1, ip, np, M)){
        return 1;
    }
    else{
        return 0;
    }
    */
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
