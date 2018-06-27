/*
Given an absolute path for a file (Unix-style), simplify it.

Examples:

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Note that absolute path always begin with ‘/’ ( root directory )
Path will not have whitespace characters.


*/
string Solution::simplifyPath(string A) {
    stack<string> S;
    int i=0;
    string folder="";
    while(A[i]!='\0'){
        if(A[i]!='/'){
            folder += A[i];
        }
        else{
            if(folder.compare("..")==0){
                if(!S.empty()){
                    S.pop();
                }
            }
            else{
                if(folder.compare(".")==0){
                    
                }
                else{
                    if(folder.length()>0){
                        S.push(folder);
                    }
                }
            }
            folder = "";
            
        }
        i++;
    }
    if(folder.length()>0){
        if(folder.compare("..")==0){
            if(!S.empty()){
                S.pop();
            }
        }
        else{
            if(folder.compare(".")==0){
                
            }
            else{
                S.push(folder);
            }
        }
    }
    stack<string> S2;
    while(!S.empty()){
        S2.push(S.top());
        S.pop();
    }
    ostringstream ans;
    ans<<"/";
    // string ans="";
    while(!S2.empty()){
        ans<<S2.top();
        // ans = '/'+ ans;
        S2.pop();
        if(!S2.empty()){
            ans<<"/";
        }
    }
    // if(ans.length()==0){
    //     return "/";
    // }
    return ans.str();
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
