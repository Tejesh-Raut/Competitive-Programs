/*
Validate if a given string is numeric.

Examples:

"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Clarify the question using “See Expected Output”

Is 1u ( which may be a representation for unsigned integers valid?
For this problem, no.
Is 0.1e10 valid?
Yes
-01.1e-10?
Yes
Hexadecimal numbers like 0xFF?
Not for the purpose of this problem
3. (. not followed by a digit)?
No
Can exponent have decimal numbers? 3e0.1?
Not for this problem.
Is 1f ( floating point number with f as prefix ) valid?
Not for this problem.
How about 1000LL or 1000L ( C++ representation for long and long long numbers )?
Not for this problem.
How about integers preceded by 00 or 0? like 008?
Yes for this problem

*/

int Solution::isNumber(const string &A) {
    bool dec, expn, end;
    end = false;
    dec = false;
    expn = false;
    int i=0;
    while(A[i]==' '){
        i++;
        if(A[i]=='\0'){
            return 0;
        }
    }
    // cout<<"*"<<A<<"*"<<endl;
    if((A[i]=='-')||(A[i]=='+')){
        i++;
        if((A[i]=='\0')||(A[i]==' ')){
            return 0;
        }
    }
    while(A[i]!='\0'){
        if(end){
            if(A[i]!=' '){
                return 0;
            }
        }
        if(((A[i]-'0')>=0)&&((A[i]-'0')<=9)){
            i++;
        }
        else{
            if(A[i]=='.'){
                if(expn){
                    // cout<<"e followed by ."<<endl;
                    return 0;
                }
                if(dec){
                    // cout<<". followed by ."<<endl;
                    return 0;
                }
                else{
                    dec = true;
                    i++;
                    if((A[i]=='\0')||(A[i]==' ')||(A[i]=='e')){
                        // cout<<"ended with ."<<endl;
                        return 0;
                    }
                }
            }
            else{
                if(A[i]=='e'){
                    if(expn){
                        return 0;
                    }
                    else{
                        expn = true;
                        i++;
                        if((A[i]=='\0')||(A[i]==' ')){
                            return 0;
                        }
                        if((A[i]=='-')||(A[i]=='+')){
                            i++;
                            if((A[i]=='\0')||(A[i]==' ')){
                                return 0;
                            }
                        }
                    }
                }
                else{
                    if(A[i]==' '){
                        if(i==0){
                            return 0;
                        }
                        end = true;
                        i++;
                    }
                    else{
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
