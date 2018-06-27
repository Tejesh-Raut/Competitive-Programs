/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.
Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.

Example :

S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC"

 Note:
If there is no such window in S that covers all characters in T, return the empty string ''.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index ).

*/

string Solution::minWindow(string S, string T) {
    string ans="";
    int ans_start=0;
    int ans_end=-1;
    
    unordered_map<char, int> Tc;
    unordered_map<char, int> Sc;
    
    int nT = T.length();
    
    for(int i=0; i<nT; i++){
        if(Sc.find(T[i]) == Sc.end()){
            Sc[T[i]] = 0;
        }
        if(Tc.find(T[i])==Tc.end()){
            Tc[T[i]] = 0;
        }
        Tc[T[i]]++;
    }
    
    int nS = S.length();
    for(int i=0; i<nS; i++){
        if(Sc.find(S[i]) == Sc.end()){
            Sc[S[i]] = 0;
        }
        if(Tc.find(S[i])==Sc.end()){
            Tc[S[i]] = 0;
        }
        Sc[S[i]]++;
    }
    int start=0;
    int end = nS-1;
    
    while(Sc[S[end]]>Tc[S[end]]){
        Sc[S[end]]--;
        end--;
        if(end<0){
            string temp = "";
            return temp;
        }
    }
    while(Sc[S[start]]>Tc[S[start]]){
        Sc[S[start]]--;
        start++;
        if(start>end){
            string temp = "";
            return temp;
        }
    }
    // cout<<start<<" "<<end<<endl;
    // return ans;
    // bool exists = false;
    for(int i=0; i<nT; i++){
        if(Sc[T[i]]<Tc[T[i]]){
            string temp = "";
            return temp;
        }
    }
    ans_start = start;
    ans_end = end;
    while(true){
        char c = S[start];
        Sc[S[start]]--;
        start++;
        if(start>=nS){
            break;
        }
        while((Sc[S[start]]>Tc[S[start]])){
            Sc[S[start]]--;
            start++;
            if(start>end){
                break;
            }
        }
        if(start>end){
            break;
        }
        end++;
        if(end>=nS){
            break;
        }
        while((S[end])!=c){
            Sc[S[end]]++;
            end++;
            if(end>=nS){
                break;
            }
        }
        Sc[S[end]]++;
        if(end>=nS){
            break;
        }
        while((Sc[S[start]]>Tc[S[start]])){
            Sc[S[start]]--;
            start++;
        }
        if((end-start)<(ans_end-ans_start)){
            ans_start = start;
            ans_end = end;
        }
    }
    for(int i=ans_start; i<=ans_end; i++){
        ans += S[i];
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
