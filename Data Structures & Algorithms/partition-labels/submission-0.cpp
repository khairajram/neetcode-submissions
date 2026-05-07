class Solution {
public:
    vector<int> partitionLabels(string s) {
        if(s.size() == 1)
            return {1};
        
        vector<int> ans;

        unordered_map<char,int> mp;

        for(int i=0;i<s.size();i++)
            mp[s[i]] = i;

        int len = 0;
        int maxi = 0;

        int i = 0;

        while(i<s.size()){

            maxi = max(maxi,mp[s[i]]);
            len++;

            if(maxi == i){
                ans.push_back(len);
                len = 0;
                maxi = 0;
            }
            
            i++;
        }

        return ans;
    }
};
