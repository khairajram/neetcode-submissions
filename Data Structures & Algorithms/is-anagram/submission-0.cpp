class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mp1(26,0);
        vector<int> mp2(26,0);

        for(auto i : s)
            mp1[i - 'a']++;
        
        for(auto i : t)
            mp2[i - 'a']++;

        for(int i=0;i<26;i++)
            if(mp1[i] != mp2[i])
                return false;

        return true;
    }
};
