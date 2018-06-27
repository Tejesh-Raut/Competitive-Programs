/*
Given an integer, convert it to a roman numeral, and return a string corresponding to its roman numeral version

Input is guaranteed to be within the range from 1 to 3999.

Example :

Input : 5
Return : "V"

Input : 14
Return : "XIV"
 Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to think of all the needed clarifications and see the expected response using “See Expected Output” For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations. 

*/

string Solution::intToRoman(int A) {
    int quo, rem;
    string ans="";
    quo = A/1000;
    A = A%1000;
    for(int i=0; i<quo; i++){
        ans = ans + 'M';
    }
    quo = A/100;
    if(A>=900){
        ans = ans + "CM";
    }
    else{
        if(A>=500){
            ans += 'D';
            for(int i=0; i<(quo-5); i++){
                ans +='C';
            }
        }
        else{
            if(A>=400){
                ans += "CD";
            }
            else{
                for(int i=0; i<quo; i++){
                    ans +='C';
                }
            }
        }
    }
    A = A%100;
    quo = A/10;
    if(A>=90){
        ans +="XC";
    }
    else{
        if(A>=50){
            ans +='L';
            for(int i=0; i<(quo-5); i++){
                ans +='X';
            }
        }
        else{
            if(A>=40){
                ans += "XL";
            }
            else{
                for(int i=0; i<quo; i++){
                    ans +='X';
                }
            }
        }
    }
    A = A%10;
    quo = A;
    if(A>=9){
        ans += "IX";
    }
    else{
        if(A>=5){
            ans += 'V';
            for(int i=0; i<(quo-5); i++){
                ans += 'I';
            }
        }
        else{
            if(A>=4){
                ans += "IV";
            }
            else{
                for(int i=0; i<quo; i++){
                    ans +='I';
                }
            }
        }
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
