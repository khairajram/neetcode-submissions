class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(auto i : nums)
            mp[i]++;

        auto cmp = [](pair<int,int> a,pair<int,int> b){
            return a.first > b.first;
        };

        for(auto i : mp)
            cout<<i.first<<i.second<<endl;

        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);

        for(auto i : mp){
            if(k){
                pq.push({i.second,i.first});
                k--;
            }else{
                if(pq.top().first < i.second){
                    pq.pop();
                    pq.push({i.second,i.first});
                }
            }
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
