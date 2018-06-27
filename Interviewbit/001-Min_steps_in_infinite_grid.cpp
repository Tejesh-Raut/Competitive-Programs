/*
You are in an infinite 2D grid where you can move in any of the 8 directions :

 (x,y) to 
    (x+1, y), 
    (x - 1, y), 
    (x, y+1), 
    (x, y-1), 
    (x-1, y-1), 
    (x+1,y+1), 
    (x-1,y+1), 
    (x+1,y-1) 
You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You start from the first point.

Example :

Input : [(0, 0), (1, 1), (1, 2)]
Output : 2
It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).

*/

int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int num_steps = 0;
    int x_diff, y_diff;
    int num_points = X.size();
    for(int i=0; i<(num_points-1); i++){
        x_diff = abs(X[i]-X[i+1]);
        y_diff = abs(Y[i]-Y[i+1]);
        if(x_diff> y_diff){
            num_steps += x_diff;
        }
        else{
            num_steps += y_diff;
        }
    }
    return num_steps;
}
