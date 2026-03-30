class Solution {
public:
    void merge(vector<int>& nums,int l,int mid,int r) {
        vector<int> a;
        vector<int> b;
        for(int i=l;i<=mid;i++) a.push_back(nums[i]);
        for(int i=mid+1;i<=r;i++) b.push_back(nums[i]);
        int idx1=0,idx2=0,idx=l;
        while(idx1<(int)a.size() || idx2<(int)b.size()) {
            if(idx1<(int)a.size() && idx2<(int)b.size()) {
                if(a[idx1]<=b[idx2]) nums[idx++]=a[idx1++];
                else nums[idx++]=b[idx2++];
            }
            else if(idx1<(int)a.size())
                nums[idx++]=a[idx1++];
            else
                nums[idx++]=b[idx2++];
        }
    }
    void mergeSort(vector<int>& nums,int l,int r) {
        if(l>=r) return;
        int mid=(l+r)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        merge(nums,l,mid,r);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};