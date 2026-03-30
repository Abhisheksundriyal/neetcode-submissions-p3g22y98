class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        vector<pair<int,vector<int>>> V;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            int x=points[i][0],y=points[i][1],d=(x*x)+(y*y);
            V.push_back({d,points[i]});
        }
        sort(V.begin(),V.end());
        for(int i=0;i<k;i++)
            ans.push_back(V[i].second);
        return ans;
    }
};
