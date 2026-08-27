class Solution {
public:
    bool issafe(vector<vector<char>>& board, int row , int col , char dig){
        //horizontal
        for(int p=0; p<9; p++){
            if(board[row][p] == dig){
                return false;
            }
        }
        //vertical
        for(int q=0; q<9; q++){
            if(board[q][col] == dig){
                return false;
            }
        }
        //grid
        int sr = (row/3)*3;
        int sc = (col/3)*3;

        for(int i= sr;i<= sr+2; i++){
            for(int j = sc; j<= sc+2; j++){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }
        return true;
    }

    bool helper(vector<vector<char>>& board, int row , int col){
        if(row == 9)
        return true;

        int nextrow = row, nextcol = col + 1;

        if(nextcol == 9){
            nextrow = row + 1;
            nextcol = 0;
        }

        if(board[row][col] != '.'){
            return helper(board,nextrow,nextcol);
        }

        for(char dig = '1';dig <= '9'; dig++){
            if(issafe(board,row,col,dig)){
                board[row][col] = dig;
            
            if(helper(board,nextrow,nextcol)){
                return true;
            }
            board[row][col] = '.';
        }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper (board, 0 , 0);
    }
};