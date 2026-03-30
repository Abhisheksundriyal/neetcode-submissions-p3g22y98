class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int idx=gas.size(),idx2=0,sum=0,total=0;
        for(int i=0;i<idx;i++)
        {
            int temp=gas[i]-cost[i];
            sum+=temp;
            while(sum<0)
            {
                idx--;
                if(idx<=i)
                    break;
                else
                    sum=sum+gas[idx]-cost[idx];
            }
        }
        if(sum<0)
            return -1;
        if(idx==gas.size())
            return 0;
        return idx;
    }
};
