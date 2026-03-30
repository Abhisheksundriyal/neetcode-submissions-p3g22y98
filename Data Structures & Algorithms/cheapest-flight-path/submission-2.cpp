class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n,INT_MAX);
        prices[src]=0;
        for(int i=0;i<=k;i++)
        {
            vector<int> tempPrices=prices;
            for(int j=0;j<flights.size();j++) {
                int s=flights[j][0],d=flights[j][1],p=flights[j][2];

                if(prices[s]==INT_MAX)
                    continue;

                if(prices[s]+p<tempPrices[d])
                    tempPrices[d]=prices[s]+p;
            }
            prices=tempPrices;
        }
        if(prices[dst]==INT_MAX)
            return -1;
        return prices[dst];
    }
};
