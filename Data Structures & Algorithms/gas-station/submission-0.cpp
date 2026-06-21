class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        for(int i=0;i<gas.size();i++){
            if(cost[i] > gas[i])
                continue;

            int j = (i + 1) % n;

            int curr = gas[i] - cost[i] + gas[j];

            while(j != i){
                if(curr < cost[j])
                    break;

                curr -= cost[j];

                j = (j + 1)%n;

                curr += gas[j];
            }

            if(j == i)
                return i;
        }

        return -1;        
    }
};

