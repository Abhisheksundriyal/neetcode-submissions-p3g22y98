class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int L=0,R=matrix.size()-1,m=matrix[0].size();
        while(L<=R)
        {
            int mid=(L+R)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][m-1])
            {
                int l=0,r=m-1;
                while(l<=r)
                {
                    int MID=(l+r)/2;
                    if(matrix[mid][MID]==target)
                        return true;
                    else if(matrix[mid][MID]>target)
                        r=MID-1;
                    else
                        l=MID+1;
                }
                return false;
            }
            else if(target<matrix[mid][0])
                R=mid-1;
            else
                L=mid+1;
        }
        return false;
    }
};
