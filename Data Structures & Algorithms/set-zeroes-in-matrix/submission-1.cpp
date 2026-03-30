class Solution {
public:

    void recur(vector<vector<int>>& matrix,vector<vector<int>>& VIS,int I,int J,int n,int m) {
        VIS[I][J]=1;
        for(int i=I;i<n;i++)
        {
            if(matrix[i][J]==0 && VIS[i][J]==0)
                recur(matrix,VIS,i,J,n,m);
            else
            {
                matrix[i][J]=0;
                VIS[i][J]=1;
            }
        }
        for(int i=I;i>=0;i--)
        {
            if(matrix[i][J]==0 && VIS[i][J]==0)
                recur(matrix,VIS,i,J,n,m);
            else
            {
                matrix[i][J]=0;
                VIS[i][J]=1;
            }
        }
        for(int j=J;j<m;j++)
        {
            if(matrix[I][j]==0 && VIS[I][j]==0)
                recur(matrix,VIS,I,j,n,m);
            else
            {
                matrix[I][j]=0;
                VIS[I][j]=1;
            }
        }
        for(int j=J;j>=0;j--)
        {
            if(matrix[I][j]==0 && VIS[I][j]==0)
                recur(matrix,VIS,I,j,n,m);
            else
            {
                matrix[I][j]=0;
                VIS[I][j]=1;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> VIS(n);
        for(int i=0;i<n;i++)
        {
            vector<int> temp(m,0);
            VIS[i]=temp;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0 && VIS[i][j]==0)
                    recur(matrix,VIS,i,j,n,m);
            }
        }
    }
};
