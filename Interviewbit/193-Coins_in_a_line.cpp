/*
There are N coins (Assume N is even) in a line. Two players take turns to take a coin from one of the ends of the line until there are no more coins left. The player with the larger amount of money wins. Assume that you go first.

Write a program which computes the maximum amount of money you can win.

Example:

suppose that there are 4 coins which have value
1 2 3 4
now you are first so you pick 4
then in next term
next person picks 3 then
you pick 2 and
then next person picks 1
so total of your money is 4 + 2 = 6
next/opposite person will get 1 + 3 = 4
so maximum amount of value you can get is 6

*/

pair<bool ,int> myFunc(vector<int>&A, int l, int r, vector<vector<pair<bool, int> > > &mymap){
    if(l==r){
        return make_pair(true, A[r]);
    }
    if(r<l){
        return make_pair(true, -1);
    }
    if((r-l)==1){
        if(A[l]>A[r]){
            return make_pair(true, A[l]);
        }
        else{
            return make_pair(false, A[r]);
        }
    }
    if(mymap[l][r].second!=-1){
        return mymap[l][r];
    }
    pair<bool, int> ans1= make_pair(true, 0);
    pair<bool, int> ans2= make_pair(true, 0);
    // right
    if(myFunc(A, l, (r-1), mymap).first == true){
        ans1 = make_pair(false,(A[r] + myFunc(A, (l+1), (r-1), mymap).second));
    }
    else{
        ans1 = make_pair(false, (A[r] + myFunc(A, (l), (r-2), mymap).second));
    }
    // left
    if(myFunc(A, (l+1), (r), mymap).first == true){
        ans2 = make_pair(true,(A[l] + myFunc(A, (l+2), (r), mymap).second));
    }
    else{
        ans2 = make_pair(true,(A[l] + myFunc(A, (l+1), (r-1), mymap).second));
    }
    if(ans1.second>ans2.second){
        mymap[l][r] = ans1;
        // cout<<"* "<<l<<" "<<r<<" = "<<ans1<<endl;
        return ans1;
    }
    else{
        mymap[l][r] = ans2;
        // cout<<"* "<<l<<" "<<r<<" = "<<ans2<<endl;
        return ans2;
    }
}
int Solution::maxcoin(vector<int> &A) {
    int n = A.size();
    int ans=0;
    if(n==0){
        return 0;
    }
    int l= 0;
    int r= n-1;
    vector<pair<bool, int> > temp(n, make_pair(true, -1));
    vector<vector<pair<bool, int> > > mymap(n, temp);
    ans = myFunc(A, l, r, mymap).second;
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
