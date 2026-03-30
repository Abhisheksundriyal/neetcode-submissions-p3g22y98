class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),idx=n-1,sum=0;
        for(int i=0;i<=idx;i++)
        {
            sum=sum-cost[i]+gas[i];
            while(i<idx && sum<0)
            {
                sum=sum-cost[idx]+gas[idx];
                idx--;
            }
            if(sum<0)
                return -1;
        }
        if(idx==n-1)
            return 0;
        return idx+1;
    }
};