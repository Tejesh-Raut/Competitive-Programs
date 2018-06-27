/*
Pretty print a json object using proper indentation.

Every inner brace should increase one indentation to the following lines.
Every close brace should decrease one indentation to the same line and the following lines.
The indents can be increased with an additional ‘\t’
Example 1:

Input : {A:"B",C:{D:"E",F:{G:"H",I:"J"}}}
Output : 
{ 
    A:"B",
    C: 
    { 
        D:"E",
        F: 
        { 
            G:"H",
            I:"J"
        } 
    } 
}
Example 2:

Input : ["foo", {"bar":["baz",null,1.0,2]}]
Output : 
[
    "foo", 
    {
        "bar":
        [
            "baz", 
            null, 
            1.0, 
            2
        ]
    }
]
[] and {} are only acceptable braces in this case.

Assume for this problem that space characters can be done away with.

Your solution should return a list of strings, where each entry corresponds to a single line. The strings should not have “\n” character in them.


*/

vector<string> Solution::prettyJSON(string A) {
    int i=0;
    vector<string> ans;
    string s="";
    string tabs = "";
    while(A[i]!='\0'){
        s += A[i];
        if((A[i]=='[')||(A[i]=='{')){
            ans.push_back(s);
            tabs += '\t';
            s = tabs;
        }
        else{
            if((A[i]==',')){
                ans.push_back(s);
                s = tabs;
            }
            else{
                // if((A[i]==']')||(A[i]=='}')){
                //     ans.push_back(s);
                //     s = tabs;
                // }
                // else{
                    if((A[i]==':')&&((A[i+1]=='[')||(A[i+1]=='{'))){
                        ans.push_back(s);
                        s = tabs;
                    }
                    // s += A[i];
                // }
            }
        }
        if((A[i+1]==']')||(A[i+1]=='}')){
            ans.push_back(s);
            tabs.pop_back();
            s = tabs;
        }
        i++;
    }
    if(s.length()>0){
        ans.push_back(s);
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
