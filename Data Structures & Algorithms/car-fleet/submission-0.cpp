class Solution {
public:

    bool compare(int N1,int D1,int N2,int D2)
    {
        int a=N1*D2,b=N2*D1;
        return (a>b);
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size(),ans=0,N=-1,D=-1;
        vector<pair<int,int>> left,right;
        for(int i=0;i<n;i++)
        {
            pair<int,int> p={abs(position[i]-target),abs(speed[i])};
            if(position[i]<=target)
                left.push_back(p);
            else
                right.push_back(p);
        }
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        for(int i=0;i<left.size();i++)
        {
            if(N==-1)
            {
                ans++;
                N=left[i].first;
                D=left[i].second;
            }
            else
            {
                if(compare(left[i].first,left[i].second,N,D))
                {
                    N=left[i].first;
                    D=left[i].second;
                    ans++;
                }
            }
        }
        N=-1;
        D=-1;
        for(int i=0;i<right.size();i++)
        {
            if(N==-1)
            {
                ans++;
                N=right[i].first;
                D=right[i].second;
            }
            else
            {
                if(compare(right[i].first,right[i].second,N,D))
                {
                    N=right[i].first;
                    D=right[i].second;
                    ans++;
                }
            }
        }
        return ans;
    }
};