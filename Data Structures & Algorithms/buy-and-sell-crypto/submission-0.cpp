class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),large=prices[n-1],ans=0;
        for(int i=n-2;i>=0;i--)
        {
            int temp=large-prices[i];
            ans=max(ans,temp);
            large=max(large,prices[i]);
        }
        return ans;
    }
};
