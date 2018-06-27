/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Example:

Given “25525511135”,

return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)


*/

bool check(string &A){
    if(A.length()>1){
        if(A[0]=='0'){
            return false;
        }
    }
    int n = stoi(A);
    if((n>=0)&&(n<=255)){
        return true;
    }
    else{
        return false;
    }
}

vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> ans;
    int n = A.length();
    for(int i=1; i<4; i++){
        string first  =  A.substr(0, i);
        if (!check(first)){
            continue;
        }
        for (int j = 1; ((i + j) < n) && (j < 4); j++){
            string second  =  A.substr(i, j);
            if (!check(second)){
                continue;
            }
            for (int k = 1; ((i + j + k) < n) && (k < 4); k++){
                string third = A.substr(i + j, k);
                string fourth = A.substr(i + j + k);
                if(check(third)&&(check(fourth))){
                    string curr = first+"."+second+"."+third+"."+fourth;
                    ans.push_back(curr);
                }
            }
        }
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
