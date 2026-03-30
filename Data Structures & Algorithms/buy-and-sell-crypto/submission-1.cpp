class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),ans=0,large=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            int temp=large-prices[i];
            large=max(large,prices[i]);
            ans=max(ans,temp);
        }
        return ans;
    }
};
