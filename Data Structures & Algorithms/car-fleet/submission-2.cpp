class Solution {
public:
    bool isGreater(int N1,int D1,int N2,int D2)
    {
        return((N2*D1)>(N1*D2));
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> V;
        int n=position.size(),ans=0,N=-1,D=-1;
        for(int i=0;i<n;i++)
            V.push_back({abs(position[i]-target),speed[i]});
        sort(V.begin(),V.end());
        for(int i=0;i<n;i++)
        {
            if(N==-1)
            {
                ans++;
                N=V[i].first;
                D=V[i].second;
            }
            else
            {
                if(isGreater(N,D,V[i].first,V[i].second))
                {
                    ans++;
                    N=V[i].first;
                    D=V[i].second;
                }
            }
        }
        return ans;
    }
};
