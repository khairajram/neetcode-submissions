class Solution {
    void daily(vector<int>& temp,int i,stack<pair<int,int>> &st,vector<int> &ans){
        if(i < 0)
            return;

        while(!st.empty() && st.top().first < temp[i])
            st.pop();

        if(st.empty())
            ans[i] = 0;
        else
            ans[i] = st.top().second - i;

        st.push({temp[i],i});

        daily(temp,i-1,st,ans);
    }
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> st;

        daily(temperatures,n-1,st,ans);

        return ans;
    }
};
