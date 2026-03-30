class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int L=0,R=matrix.size()-1,n=matrix[0].size();
        while(L<=R)
        {
            int MID=(L+R)/2;
            if(target<matrix[MID][0])
                R=MID-1;
            else if(target>matrix[MID][n-1])
                L=MID+1;
            else
            {
                int l=0,r=n-1;
                while(l<=r)
                {
                    int mid=(l+r)/2;
                    if(matrix[MID][mid]<target)
                        l=mid+1;
                    else if(matrix[MID][mid]>target)
                        r=mid-1;
                    else
                        return true;
                }
                return false;
            }
        }
        return false;

    }
};
