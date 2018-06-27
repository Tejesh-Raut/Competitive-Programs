/*
You are given an integer N. You have to find smallest multiple of N which consists of digits 0 and 1 only. Since this multiple could be large, return it in form of a string.

Note:

Returned string should not contain leading zeroes.
For example,

For N = 55, 110 is smallest multiple consisting of digits 0 and 1.
For N = 2, 10 is the answer.

*/

string Solution::multiple(int A) {
    string temp;
    temp +="1";
    queue<pair<string, int> > q;
    unordered_map<int, bool> M;
    q.push(make_pair(temp, 1));
    M[1] = true;
    pair<string, int> p;
    string t1, t2;
    int rem1, rem2;
    if(A==1){
        return temp;
    }
    while(true){
        p = q.front();
        q.pop();
        rem1 = (p.second*10)%A;
        rem2 = (p.second*10 + 1)%A;
        if(rem1==0){
            t1 = p.first+"0";
            return t1;
        }
        if(rem2==0){
            t2 = p.first+"1";
            return t2;
        }
        if(M.find(rem1)==M.end()){
            t1 = p.first+"0";
            q.push(make_pair(t1, rem1));
            M[rem1] = true;
        }
        if(M.find(rem2)==M.end()){
            t2 = p.first+"1";
            q.push(make_pair(t2, rem2));
            M[rem2] = true;
        }
    }
    return temp;
}
