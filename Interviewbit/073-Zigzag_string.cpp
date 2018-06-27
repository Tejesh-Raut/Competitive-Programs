/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
**Example 2 : **
ABCD, 2 can be written as

A....C
...B....D
and hence the answer would be ACBD.


*/

string Solution::convert(string A, int B) {
    int n = A.length();
    string ans="";
    int gap1=0;
    int gap2=0;
    int gap =0;
    bool flag = true;
    for(int i=0;i<B;i++){
        gap1 = (B-i-1)*2; // ((B-i)*(B-i-1))/2 + 1;
        gap2 = i*2; // (i*(i+1))/2 + 1;
        if(gap1==0){
            gap1 = gap2;
        }
        if(gap2 == 0){
            gap2 = gap1;
        }
        if(B==1){
            gap1 = 1;
            gap2 = 1;
        }
        int j=i;
        flag = true;
        while(j<n){
            if(flag){
                gap = gap1;
            }
            else{
                gap = gap2;
            }
            flag = !flag;
            ans += A[j];
            // cout<<ans<<gap<<endl;
            j = j+gap;
        }
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
