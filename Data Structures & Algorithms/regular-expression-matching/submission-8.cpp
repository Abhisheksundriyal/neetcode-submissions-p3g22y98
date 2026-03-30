class Solution {
public:
    bool recur(int i,int j,int n,int m,string& s,
                vector<pair<char,int>>& V,
                vector<vector<int>>& dp) {
        
        if(i>=n || j>=m)
        {
            if(i>=n && j>=m)
                return dp[i][j] = 1;
            if(i>=n)
            {
                if(V[j].second==1 && recur(i,j+1,n,m,s,V,dp))
                    return dp[i][j] = 1;
            }
            return dp[i][j] = 0;
        }

        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(V[j].second==0)
        {
            if(s[i]==V[j].first || V[j].first=='.')
                return dp[i][j]=recur(i+1,j+1,n,m,s,V,dp);
        }
        else
        {
            if(s[i]==V[j].first || V[j].first=='.')
            {
                if(recur(i+1,j+1,n,m,s,V,dp) || recur(i+1,j,n,m,s,V,dp) || recur(i,j+1,n,m,s,V,dp))
                    return dp[i][j] = 1;
            }
            else
                return dp[i][j] = recur(i,j+1,n,m,s,V,dp);
        }
        return dp[i][j] = 0;
    }
    bool isMatch(string s, string p) {
        vector<pair<char,int>> V;
        for(int i=0;i<p.size();i++) {
            if(p[i]!='*')
                V.push_back({p[i],0});
            else
                V[V.size()-1].second=1;
        }
        int n=s.size(),m=V.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return recur(0,0,n,m,s,V,dp);
    }
};