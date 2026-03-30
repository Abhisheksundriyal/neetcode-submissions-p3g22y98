class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> que;
    vector<int> ans;
    int n=nums.size(),idx=0;
    for(int i=0;i<n;i++)
    {
        while(!que.empty() && nums[que.back()]<=nums[i])
            que.pop_back();
        que.push_back(i);
        while((i-idx+1)>k)
        {
            idx++;
            while(que.front()<idx)
                que.pop_front();
        }
        if((i-idx+1)==k)
        {
            ans.push_back(nums[que.front()]);
        }
    }
    return ans;
}
};
