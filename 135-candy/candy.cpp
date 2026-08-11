class Solution {
public:
    int candy(vector<int>& ratings) {

        vector<int> candy(ratings.size());
        int result = 0;

        for(int i=0;i<ratings.size();i++){
            candy[i] += 1;
        }
        for(int i=1;i<ratings.size();i++){
            if(ratings[i] > ratings[i-1]){
                candy[i] = candy[i-1] + 1;
            }
        }
        for(int i=ratings.size()-2;i >= 0;i--){
            if(ratings[i] > ratings[i+1]){
                candy[i] = max(candy[i], candy[i+1] + 1);
            }
        }

        for(int i=0;i< ratings.size();i++){
            result += candy[i];
        }

        return result;
        
    }
};