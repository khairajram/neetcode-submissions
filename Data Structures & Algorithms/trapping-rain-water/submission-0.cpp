class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = 0;
        int rmax = 0;
        int i = 0;
        int j = n - 1;

        int ans = 0;

        while(i < j){

            if(height[i] <= height[j]){
                lmax = max(lmax,height[i]);
                int vol = lmax - height[i];
                ans += vol;
                i++;
            }else if(height[i] > height[j]){
                rmax = max(rmax,height[j]);
                int vol = rmax - height[j];
                ans += vol;
                j--;
            }
        }

        return ans;
    }
};
