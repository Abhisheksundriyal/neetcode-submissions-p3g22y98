class Solution {
public:
    pair<int,int> partition(vector<int>& nums,int l,int r) {
    
    int idx=l,pivot=nums[l+rand()%(r-l+1)];
    pair<int,int> res;
    for(int i=l;i<=r;i++)
    {
        if(nums[i]<pivot)
        {
            swap(nums[i],nums[idx]);
            idx++;
        }
    }
    res.first=idx;
    for(int i=idx;i<=r;i++)
    {
        if(nums[i]==pivot)
        {
            swap(nums[i],nums[idx]);
            idx++;
        }
    }
    res.second=idx-1;
    return res;
}

void quickSelect(vector<int>& nums,int l,int r,int k,int& ans) {
    if(l<=r && ans==INT_MIN) {
        pair<int,int> p=partition(nums,l,r);
        if(k>=p.first && k<=p.second)
            ans=nums[k];
        
        quickSelect(nums,l,p.first-1,k,ans);
        quickSelect(nums,p.second+1,r,k,ans);
    }
}

int findKthLargest(vector<int>& nums, int k) {
    srand(time(NULL));
    int n=nums.size(),K=n-k,ans=INT_MIN;
    quickSelect(nums,0,n-1,K,ans);
    return ans;
}
};
