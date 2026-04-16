class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(auto i : nums)
            if(mp.find(i) != mp.end())
                return true;
            else 
                mp[i] = 1;
        
        return false;
    }
};