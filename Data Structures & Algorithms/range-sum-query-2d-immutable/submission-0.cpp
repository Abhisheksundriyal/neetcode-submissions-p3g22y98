class NumMatrix {
public:
    vector<vector<int>> grid;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        grid=matrix;
        for(int i=0;i<n;i++) {
            for(int j=1;j<m;j++) grid[i][j]+=grid[i][j-1];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1;i<=row2;i++) {
            int temp=grid[i][col2];
            if(col1>0)
                temp-=grid[i][col1-1];
            sum+=temp;
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */