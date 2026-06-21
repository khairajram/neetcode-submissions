class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0;
        int curr = 0;
        int res = -1;
        
        for(int i=0;i<gas.size();i++){
            total += gas[i] - cost[i];

            if(cost[i] > gas[i]){
                res = i+1;
                curr = 0;
            }else{
                curr += gas[i] - cost[i];
            }


        }

        return total < 0 ? -1 : res;        
    }
};

