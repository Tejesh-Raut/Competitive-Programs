/*
It’s Tushar’s birthday today and he has N friends. Friends are numbered [0, 1, 2, …., N-1] and i-th friend have a positive strength S(i). Today being his birthday, his friends have planned to give him birthday bombs (kicks :P). Tushar’s friends know Tushar’s pain bearing limit and would hit accordingly.
If Tushar’s resistance is denoted by R (>=0) then find the lexicographically smallest order of friends to kick Tushar so that the cumulative kick strength (sum of the strengths of friends who kicks) doesn’t exceed his resistance capacity and total no. of kicks hit are maximum. Also note that each friend can kick unlimited number of times (If a friend hits x times, his strength will be counted x times)

Note:

Answer format = Vector of indexes of friends in the order in which they will hit.
Answer should have the maximum no. of kicks that can be possibly hit. If two answer have the same no. of kicks, return one with the lexicographically smaller.
[a1, a2, …., am] is lexicographically smaller than [b1, b2, .., bm] if a1 < b1 or (a1 = b1 and a2 < b2) … .
Input cases are such that the length of the answer does not exceed 100000.
Example:
R = 11, S = [6,8,5,4,7]

ans = [0,2]
Here, [2,3], [2,2] or [3,3] also give the maximum no. kicks.


*/

vector<int> myFunction(int A, int start, vector<int> &B){
    int n = B.size();
    cout<<A<<endl;
    cout<<start<<endl;
    int sum = 0;
    vector<int> ans;
    if(start==(n-1)){
        while((sum+B[n-1])<=A){
            sum += B[n-1];
            ans.push_back(n-1);
        }
        return ans;
    }
    int max = 0;
    vector<int> temp;
    int temp_sum = 0;
    vector<int> temp1;
    int temp1_sum = 0;
    int temp1n;
    while(temp_sum<=A){
        // cout<<"finding start "<<(start+1)<<" "<<(A-temp_sum)<<endl;
        temp1 = myFunction((A-temp_sum), (start+1), B);
        temp1n = temp1.size();
        temp1_sum=0;
        for(int i=0; i<temp1n; i++){
            temp1_sum += temp1[i];
        }
        if(((temp_sum+temp1_sum)>max)&&((temp_sum+temp1_sum)<=A)){
            max = temp_sum + temp1_sum;
            // cout<<"* "<<start<<" * "<<max<<endl;
            ans = temp;
            ans.insert(ans.end(), temp1.begin(), temp1.end());
        }
        temp_sum += B[start];
        temp.push_back(start);
    }
    return ans;
}
vector<int> Solution::solve(int A, vector<int> &B) {
    vector<int> ans = myFunction(A, 0, B);
    return ans;
}
