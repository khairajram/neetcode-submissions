class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for(auto i : strs){
            string st = i;
            sort(st.begin(),st.end());

            mp[st].push_back(i);
        }

        vector<vector<string>> ans;

        for(auto v : mp)
            ans.push_back(v.second);

        return ans;
    }
};
