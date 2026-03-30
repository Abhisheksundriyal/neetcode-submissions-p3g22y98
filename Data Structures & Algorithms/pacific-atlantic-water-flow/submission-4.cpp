class Solution {
public:
    void recur(int i,int j,vector<vector<int>>& ocean,
                vector<vector<int>>& heights) {
        ocean[i][j]=1;
        if(i+1<heights.size() && ocean[i+1][j]==0 &&
            heights[i+1][j]>=heights[i][j])
            recur(i+1,j,ocean,heights);
        if(i-1>=0 && ocean[i-1][j]==0 &&
            heights[i-1][j]>=heights[i][j])
            recur(i-1,j,ocean,heights);
        if(j+1<heights[0].size() && ocean[i][j+1]==0 &&
            heights[i][j+1]>=heights[i][j])
            recur(i,j+1,ocean,heights);
        if(j-1>=0 && ocean[i][j-1]==0 &&
            heights[i][j-1]>=heights[i][j])
            recur(i,j-1,ocean,heights);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> pacific(n,vector<int>(m,0)),
            atlantic(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            recur(i,0,pacific,heights);
            recur(i,m-1,atlantic,heights);
        }
        for(int j=0;j<m;j++)
        {
            recur(0,j,pacific,heights);
            recur(n-1,j,atlantic,heights);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j]+atlantic[i][j]==2)
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
