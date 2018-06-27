/*
Given a string, find the rank of the string amongst its permutations sorted lexicographically. 
Note that the characters might be repeated. If the characters are repeated, we need to look at the rank in unique permutations. 
Look at the example for more details.

Example :

Input : 'aba'
Output : 2

The order permutations with letters 'a', 'a', and 'b' : 
aab
aba
baa
The answer might not fit in an integer, so return your answer % 1000003

 NOTE: 1000003 is a prime number
NOTE: Assume the number of characters in string < 1000003 

*/

long long factorial(int n, vector<long long> &M){
    if(n<=1){
        M[n] = ((long long)1);
        return M[n];
    }
    if(M[n]!=-1){
        return M[n];
    }
    long long ans = (((long long)n)*factorial(n-1, M));
    ans %= 1000003;
    return ans;
}
int Solution::findRank(string A){
    int n=A.length();
    vector<char> map1;
    vector<int> map2;
    int map_size=0;
    int ans = 1;
    int len = n-1;
    vector<long long> M(n, -1);
    for(int i=0; i<n; i++){
        bool present =false;
        for(int j=0; j<map_size; j++){
            if(map1[j]==A.at(i)){
                present = true;
                map2[j]++;
                break;
            }
        }
        if(!present){
            map1.push_back(A.at(i));
            map2.push_back(1);
            map_size++;
        }
    }
    
    cout<<"********"<<endl;
    for(int j=0; j<map_size; j++){
        cout<<map1[j]<<" "<<map2[j]<<endl;
    }
    cout<<"********"<<endl;
    
    for(int i=0; i<n; i++){
        int temp =0;
        int x=1;
        char c = A.at(i);
        for(int j=0; j<map_size; j++){
            if(map1[j]<c){
                temp += map2[j];
            }
        }
        for(int j=0; j<map_size; j++){
            x = x*factorial(map2[j], M);
            if(map1[j]==c){
                map2[j]--;
            }
        }
        // cout<<"denom "<<x<<endl;
        ans = ans + (temp * ((factorial(len, M)) / x));
        ans %= 1000003;
        // cout<<ans<<endl;
        len--;
    }
    return ans;
}
/*
int Solution::findRank(string A) {
    // return factorial(19);
    int n = A.length();
    char curr;
    int curr_rank;
    long long rank=1;
    for(int i=0; i<n; i++){
        curr = A.at(i);
        curr_rank = 0;
        vector<char> temp;
        vector<int> temp1;
        int temp_size = 0;
        int mult_factor2=0;
        for(int j=(i+1); j<n; j++){
            if(A.at(j)<curr){
                mult_factor2++;
                // temp_size = temp.size();
                // curr_rank++;
                bool present1=false;
                for(int k=0; k<temp_size; k++){
                    if(temp[k] == A.at(j)){
                        // temp1[k]++;
                        present1=true;
                        break;
                    }
                }
                if(!present1){
                    curr_rank++;
                }
            }
            bool present = false;
            for(int k=0; k<temp_size; k++){
                if(temp[k]==A.at(j)){
                    temp1[k]++;
                    present = true;
                    break;
                }
            }
            if(!present){
                temp.push_back(A.at(j));
                temp1.push_back(1);
                temp_size++;
            }
        }
        cout<<"curr_rank "<<curr_rank<<endl;
        long long mult_factor = mult_factor2*factorial(n-1-i);
        for(int k=0; k<temp_size; k++){
            mult_factor = mult_factor/(factorial(temp1[k]));
            cout<<"factorial of "<<temp1[k]<<endl;
        }
        cout<<"mult_factor "<<mult_factor<<endl;
        rank = rank + ((long long)curr_rank)*mult_factor;
        // cout<<"rank "<<rank<<endl;
    }
    long long ans = (rank%((long long)1000003));
    int final_ans = ans;
    return final_ans;
}
*/
