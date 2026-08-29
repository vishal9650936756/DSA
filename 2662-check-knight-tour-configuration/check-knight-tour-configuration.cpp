class Solution {
public:
    bool isvalid(vector<vector<int>>& grid, int row,int col,int n,int expvalue){
        if(row<0 || col<0 || row>=n || col>= n || grid[row][col] != expvalue){
            return false;
        }
         // Reached the last number
        if(expvalue == n*n - 1) {
            return true;
        }
        return isvalid(grid,row-2,col+1,n,expvalue+1)||
        isvalid(grid,row-1,col+2,n,expvalue+1)||
        isvalid(grid,row+1,col+2,n,expvalue+1)||
        isvalid(grid,row+2,col+1,n,expvalue+1)||
        isvalid(grid,row+2,col-1,n,expvalue+1)||
        isvalid(grid,row+1,col-2,n,expvalue+1)||
        isvalid(grid,row-1,col-2,n,expvalue+1)||
        isvalid(grid,row-2,col-1,n,expvalue+1);

    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        return isvalid(grid,0,0,n,0);
    }
};