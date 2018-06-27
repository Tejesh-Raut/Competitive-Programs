/*
Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list. Look at the sample case for clarification.

 Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp' 
 Note: All inputs will be in lower-case. 
Example :

Input : cat dog god tca
Output : [[1, 4], [2, 3]]
cat and tca are anagrams which correspond to index 1 and 4. 
dog and god are another set of anagrams which correspond to index 2 and 3.
The indices are 1 based ( the first element has index 1 instead of index 0).

 Ordering of the result : You should not change the relative ordering of the words / phrases within the group. Within a group containing A[i] and A[j], A[i] comes before A[j] if i < j.

*/

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map<int, bool> Mout;
    int n = A.size();
    vector<vector<int> > ans;
    for(int i=0; i<n; i++){
        if(Mout.find(i)== Mout.end()){
            Mout[i] = true;
            vector<int> temp;
            temp.push_back(i+1);
            int n1 = A[i].length();
            vector<int> charsi(26,0);
            for(int k=0; k<n1; k++){
                charsi[A[i][k]-'a']++;
            }
            for(int j=(i+1); j<n; j++){
                if(A[j].length()!= n1){
                    continue;
                }
                else{
                    vector<int> charsj(26,0);
                    for(int k=0; k<n1; k++){
                        charsj[A[j][k]-'a']++;
                    }
                    if(charsi == charsj){
                        temp.push_back(j+1);
                        Mout[j] = true;
                    }
                }
            }
            ans.push_back(temp);
        }
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
