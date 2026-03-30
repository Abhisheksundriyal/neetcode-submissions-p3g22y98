class Solution {
public:
    bool isValid(int i,int j,int n,int m)
{
    if(i>=0 && i<n && j>=0 && j<m)
        return true;
    return false;
}

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    int i=0,j=0,count=0,n=matrix.size(),m=matrix[0].size(),x=1;
    vector<int> ans;
    vector<vector<int>> VIS(n);
    for(int i=0;i<n;i++)
    {
        vector<int> temp(m,0);
        VIS[i]=temp;
    }
    while(count<(n*m))
    {
        // cout<<"i: "<<i<<" j: "<<j<<"\n";
        ans.push_back(matrix[i][j]);
        VIS[i][j]=1;
        if(x==1)
        {
            if(!isValid(i,j+1,n,m) || VIS[i][j+1]==1)
            {
                x=2;
                i++;
            }
            else
                j++;
        }
        else if(x==2)
        {
            if(!isValid(i+1,j,n,m) || VIS[i+1][j]==1)
            {
                x=3;
                j--;
            }
            else
                i++;
        }
        else if(x==3)
        {
            if(!isValid(i,j-1,n,m) || VIS[i][j-1]==1)
            {
                x=4;
                i--;
            }
            else
                j--;
        }
        else
        {
            if(!isValid(i-1,j,n,m) || VIS[i-1][j]==1)
            {
                x=1;
                j++;
            }
            else
                i--;
        }
        
        count++;
    }
    return ans;
}
};
