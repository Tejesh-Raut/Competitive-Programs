/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line.

Pad extra spaces ‘ ‘ when necessary so that each line has exactly L characters.
Extra spaces between words should be distributed as evenly as possible.
If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.

Your program should return a list of strings, where each string represents a single line.

Example:

words: ["This", "is", "an", "example", "of", "text", "justification."]

L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]
 Note: Each word is guaranteed not to exceed L in length. 

*/

vector<string> Solution::fullJustify(vector<string> &A, int B) {
    int num_words = 0;
    int curr_spaces = 1;
    int num_spaces = 0;
    int n = A.size();
    int len = 0;
    int i=0;
    vector<string> ans;
    while(i<n){
        // vector<string> line_vec;
        // line_vec.push_back(A[i]);
        num_words = 1;
        len = A[i].length();
        i++;
        if(i<n){
            while((len+num_words+A[i].length())<=B){
                // line_vec.push_back(A[i]);
                num_words++;
                len += A[i].length();
                i++;
                if(i>=n){
                    break;
                }
            }
        }
        // cout<<len<<endl;
        string line="";
        if(i<n){
            line = A[i-1];
            num_spaces = B-len;
            for(int j= (num_words-1); j>0; j--){
                curr_spaces = num_spaces/j;
                num_spaces -= curr_spaces;
                for(int k=0; k<curr_spaces; k++){
                    line = ' '+line;
                }
                line = A[i+j-num_words-1]+line;
                // cout<<"*"<<line<<endl;
            }
            num_spaces = B - line.length();
            for(int k=0; k<num_spaces; k++){
                line = line + ' ';
            }
        }
        else{
            num_spaces = B-len-(num_words-1);
            for(int k = 0; k<num_spaces; k++){
                line = ' '+ line;
            }
            line = A[i-1]+line;
            for(int j= (num_words-1); j>0; j--){
                line = A[i+j-num_words-1]+' '+line;
            }
        }
        // cout<<line<<endl;
        ans.push_back(line);
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
