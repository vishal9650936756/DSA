class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        bool rowf = false;
        bool colf = false;

        //check if first row contains zero
        for(int j=0;j<n;j++){
            if(matrix[0][j] == 0){
                rowf = true;
            }
        }

        //check if first column contains zero
        for(int j=0;j<m;j++){
            if(matrix[j][0] == 0){
                colf = true;
            }
        }

        // marker
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // zero marked row and column 
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // zeroing row
        if(rowf == true){
            for(int i=0;i<n;i++){
                matrix[0][i] = 0;
            }
        }
        
        // zeroing col
        if(colf == true){
            for(int i=0;i<m;i++){
                matrix[i][0] = 0;
            }
        }
    }
};