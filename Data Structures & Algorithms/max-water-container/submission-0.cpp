class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        int j = n - 1;

        int ans = INT_MIN;

        while(i < j){
            ans = max(ans,min(heights[i],heights[j]) * (j - i));

            if(heights[i] >= heights[j])
                j--;
            else
                i++;
        }

        return ans;
    }
};
