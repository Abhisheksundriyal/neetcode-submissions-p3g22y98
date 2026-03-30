class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n=matrix.size(),m=matrix[0].size(),count=0,i=0,j=0,move=1;
    vector<int> ans;
    while(count<(n*m)) {
        // cout<<"i: "<<i<<" j: "<<j<<"\n";
        ans.push_back(matrix[i][j]);
        matrix[i][j]=INT_MAX;
        count++;
        if(move==1)
        {
            if(j+1<m && matrix[i][j+1]!=INT_MAX)
            {
                j++;
                continue;
            }
            move=2;
        }
        if(move==2)
        {
            if(i+1<n && matrix[i+1][j]!=INT_MAX)
            {
                i++;
                continue;
            }
            move=3;
        }
        if(move==3)
        {
            if(j-1>=0 && matrix[i][j-1]!=INT_MAX)
            {
                j--;
                continue;
            }
            move=4;
        }
        if(move==4)
        {
            if(i-1>=0 && matrix[i-1][j]!=INT_MAX)
            {
                i--;
                continue;
            }
            move=1;
            j++;
        }
    }
    return ans;
}
};
