class Solution {
public:
    void recur(vector<int>& coins,vector<vector<int>>& VIS,int n,int idx,int amount) {
    if(amount==0)
    {
        VIS[idx][amount]=0;
        return;
    }
    if(amount<0 || idx>=n)
    {
        VIS[idx][amount]=INT_MAX;
        return;
    }
    int ans=INT_MAX;
    if((amount-coins[idx])>=0)
    {
        if(VIS[idx][amount-coins[idx]]==-1)
            recur(coins,VIS,n,idx,amount-coins[idx]);
        if(VIS[idx][amount-coins[idx]]!=INT_MAX)
            ans=1+VIS[idx][amount-coins[idx]];


        if(VIS[idx+1][amount-coins[idx]]==-1)
            recur(coins,VIS,n,idx+1,amount-coins[idx]);
        if(VIS[idx+1][amount-coins[idx]]!=INT_MAX)
            ans=min(ans,1+VIS[idx+1][amount-coins[idx]]);
    }
    if(VIS[idx+1][amount]==-1)
        recur(coins,VIS,n,idx+1,amount);
    ans=min(ans,VIS[idx+1][amount]);
    VIS[idx][amount]=ans;
}

int coinChange(vector<int>& coins, int amount) {
    int n=coins.size(),ans=INT_MAX;
    vector<vector<int>> VIS(n+5);
    for(int i=0;i<=n;i++)
    {
        vector<int> temp(amount+5,-1);
        VIS[i]=temp;
    }
    recur(coins,VIS,n,0,amount);
    if(VIS[0][amount]==INT_MAX)
        return -1;
    return VIS[0][amount];
}
};
