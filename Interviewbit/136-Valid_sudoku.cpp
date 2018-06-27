/*

Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.



The input corresponding to the above configuration :

["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
A partially filled sudoku which is valid.

 Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem


*/

int Solution::isValidSudoku(const vector<string> &A) {
    for(int i=0; i<9; i++){
        unordered_map<char, bool> M;
        for(int j=0; j<9; j++){
            char c = A[i][j];
            if(c == '.'){
                continue;
            }
            if(M.find(c) == M.end()){
                M[c] = true;
            }
            else{
                return 0;
            }
        }
    }
    for(int i=0; i<9; i++){
        unordered_map<char, bool> M;
        for(int j=0; j<9; j++){
            char c = A[j][i];
            if(c == '.'){
                continue;
            }
            if(M.find(c) == M.end()){
                M[c] = true;
            }
            else{
                return 0;
            }
        }
    }
    for(int i=0; i<9; i++){
        unordered_map<char, bool> M;
        for(int j=0; j<9; j++){
            int i1 = (i/3)*3 + (j/3);
            int j1 = (i%3)*3 + (j%3);
            char c = A[i1][j1];
            if(c == '.'){
                continue;
            }
            if(M.find(c) == M.end()){
                M[c] = true;
            }
            else{
                return 0;
            }
        }
    }
    return 1;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
