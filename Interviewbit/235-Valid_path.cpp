/*
There is a rectangle with left bottom as  (0, 0) and right up as (x, y). There are N circles such that their centers are inside the rectangle. Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.
Note : We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle at any point of time.

Constraints
 0 <= x , y , R <= 100  
 1 <= N <= 1000 
Center of each circle would lie within the grid

Input
Input contains x, y , N , R  and two array of size N containing centers of circles.
The ith index of first array contains x co-ordinate of the ith circle and ith index of second array contains the y co-ordinate of the ith circle.

Output 
YES or NO depending on weather it is possible to reach cell  (x,y) or not starting from (0,0).

  Sample Input 
  2 3 1 1 
  2
  3
  Sample Output
  NO


*/

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<int> temp(B, 0);
    vector<vector<int> > M(A, temp);
    for(int i=0; i<C; i++){
        int l = E[i] - D;
        if(l<0){
            l=0;
        }
        int r = E[i] + D - 1;
        if(r>=A){
            r = A-1;
        }
        int t = F[i] - D;
        if(t<0){
            t=0;
        }
        int b = F[i] + D -1;
        if(b>=B){
            b = B-1;
        }
        for(int x=l; x<=r; x++){
            for(int y=t; y<=b; y++){
                if(((x-E[i])*(x-E[i])+(y-F[i])*(y-F[i]))<=(D*D)){
                    M[x][y] = 1;
                }
            }
        }
    }
    for(int x=(A-1); x>=0; x--){
        for(int y=(B-1); y>=0; y--){
            
        }
    }
}
