/*
Given a positive integer N, print all the integers from 1 to N. But for multiples of 3 print “Fizz” instead of the number and for the multiples of 5 print “Buzz”. Also for number which are multiple of 3 and 5, prints “FizzBuzz”.

Example

N = 5
Return: [1 2 Fizz 4 Buzz]
Note: Instead of printing the answer, you have to return it as list of strings.


*/

vector<string> Solution::fizzBuzz(int A) {
    int n=A;
    vector<string> ans;
    
    for(int i=1; i<(n+1); i++){
        string temp;
        temp = to_string(i);
        if(((i%3)==0)&&((i%5)==0)){
            temp = "FizzBuzz";
        }
        else{
            if((i%3)==0){
                temp = "Fizz";
            }
            if((i%5)==0){
                temp = "Buzz";
            }
        }
        ans.push_back(temp);
    }
    return ans;
}
