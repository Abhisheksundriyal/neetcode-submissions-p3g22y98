class Solution {
public:
    int recur(vector<int>& nums,int n,int l,int r,int count) {
    if(r==n-1)
        return count;

    int large=INT_MIN;
    for(int i=l;i<=r;i++)
    {
        int nextIdx=i+nums[i];
        if(nextIdx>large)
            large=nextIdx;
    }
    if(large>(n-1))
        large=(n-1);

    return recur(nums,n,r+1,large,count+1);
}

int jump(vector<int>& nums) {
    int n=nums.size();
    return recur(nums,n,0,0,0);
}
};
