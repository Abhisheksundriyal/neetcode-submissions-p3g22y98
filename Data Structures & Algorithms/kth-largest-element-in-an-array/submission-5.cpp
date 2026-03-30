class Solution {
public:
    pair<int,int> partition(vector<int>& nums,int l,int r) {
        int p=nums[l+rand()%(r-l+1)],idx=l,x,y;
        for(int i=l;i<=r;i++)
        {
            if(nums[i]<p)
            {
                swap(nums[idx],nums[i]);
                idx++;
            }
        }
        x=idx;
        for(int i=x;i<=r;i++)
        {
            if(nums[i]==p)
            {
                swap(nums[idx],nums[i]);
                idx++;
            }
        }
        y=idx-1;
        return {x,y};
    }
    void quickSelect(vector<int>& nums,int l,int r,int idx,int& ans) {
        if(l>r || ans!=INT_MAX)
            return;
        pair<int,int> pivot=partition(nums,l,r);
        if(idx>=pivot.first && idx<=pivot.second)
        {
            ans=nums[pivot.first];
            return;
        }
        if(idx<pivot.first)
            quickSelect(nums,l,pivot.first-1,idx,ans);
        else
            quickSelect(nums,pivot.second+1,r,idx,ans);

    }
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        int ans=INT_MAX,n=nums.size();
        quickSelect(nums,0,n-1,n-k,ans);
        return ans;
    }
};
