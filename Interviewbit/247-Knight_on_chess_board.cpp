/*
Knight movement on a chess board

Given any source point and destination point on a chess board, we need to find whether Knight can move to the destination or not.

Knight's movements on a chess board

The above figure details the movements for a knight ( 8 possibilities ). Note that a knight cannot go out of the board.

If yes, then what would be the minimum number of steps for the knight to move to the said point.
If knight can not move from the source point to the destination point, then return -1

Input:

N, M, x1, y1, x2, y2
where N and M are size of chess board
x1, y1  coordinates of source point
x2, y2  coordinates of destination point
Output:

return Minimum moves or -1
Example

Input : 8 8 1 1 8 8
Output :  6

*/

void fill(vector<vector<int> > &board, int x1, int y1, int moves, int &M, int &N){
    if((board[x1][y1]==-1)||(board[x1][y1]>moves)){
        // cout<<"["<<x1<<"]["<<y1<<"] = "<<board[x1][y1]<<" "<<moves<<endl;
        board[x1][y1] = moves;
        int x, y;
        x = x1-2;
        y = y1+1;
        if((x>=0)&&(x<N)&&(y>=0)&&(y<M)){
            fill(board, x, y, (moves+1), M, N);
        }
        x = x1-1;
        y = y1+2;
        if((x>=0)&&(x<N)&&(y>=0)&&(y<M)){
            fill(board, x, y, (moves+1), M, N);
        }
        x = x1+1;
        y = y1+2;
        if((x>=0)&&(x<N)&&(y>=0)&&(y<M)){
            fill(board, x, y, (moves+1), M, N);
        }
        x = x1+2;
        y = y1+1;
        if((x>=0)&&(x<N)&&(y>=0)&&(y<M)){
            fill(board, x, y, (moves+1), M, N);
        }
        x = x1-2;
        y = y1-1;
        if((x>=0)&&(x<N)&&(y>=0)&&(y<M)){
            fill(board, x, y, (moves+1), M, N);
        }
        x = x1-1;
        y = y1-2;
        if((x>=0)&&(x<N)&&(y>=0)&&(y<M)){
            fill(board, x, y, (moves+1), M, N);
        }
        x = x1+1;
        y = y1-2;
        if((x>=0)&&(x<N)&&(y>=0)&&(y<M)){
            fill(board, x, y, (moves+1), M, N);
        }
        x = x1+2;
        y = y1-1;
        if((x>=0)&&(x<N)&&(y>=0)&&(y<M)){
            fill(board, x, y, (moves+1), M, N);
        }
        return;
    }
    else{
        return;
    }
}
int Solution::knight(int N, int M, int x1, int y1, int x2, int y2) {
    vector<int> temp(M,-1);
    vector<vector<int> > board(N, temp);
    // board[x1][y1] = 0;
    if((x1<=0)||(x1>N)||(y1<=0)||(y1>M)||(x2<=0)||(x2>N)||(y2<=0)||(y2>M)){
        return -1;
    }
    fill(board, (x1-1), (y1-1), 0, M, N);
    return board[x2-1][y2-1];
    // Do not write main() function.
    //Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
