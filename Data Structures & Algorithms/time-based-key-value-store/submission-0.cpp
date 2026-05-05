class TimeMap {
    unordered_map<string,vector<pair<int,string>>> mp;

    string binSch(vector<pair<int,string>> &arr,int time){
        int st = 0;
        int n = arr.size();
        int end = n - 1;
        string ans = "";

        while(st <= end){
            int mid = st + (end - st)/2;

            if(arr[mid].first <= time){
                ans = arr[mid].second;
                st = mid + 1;
            }
            else
                end = mid - 1;
        }

        return ans;
    }
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end())
            return "";
        
        return binSch(mp[key],timestamp);
    }
};
