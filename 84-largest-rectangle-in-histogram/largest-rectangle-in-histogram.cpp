class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> s;
        vector<int> right(heights.size());
        for(int i=heights.size()-1;i>=0;i--){
        while(!s.empty() && heights[s.top()]>=heights[i]){
            s.pop();
        }
        if(s.empty()){
            right[i] = heights.size();
        }
        else{
            right[i] = s.top();
        }
        s.push(i);
        }

        stack<int> u;

        vector<int> left(heights.size());
        for(int i=0;i<heights.size();i++){
        while(!u.empty() && heights[u.top()]>=heights[i]){
            u.pop();
        }
        if(u.empty()){
            left[i] = -1;
        }
        else{
            left[i] = u.top();
        }
        u.push(i);
        }
        
        
        int ans = 0;
        for(int i=0;i<=heights.size()-1;i++){
            int currarea = heights[i]*(right[i]-left[i]-1);
            ans = max(ans,currarea);
        }
        return ans;
    }
};