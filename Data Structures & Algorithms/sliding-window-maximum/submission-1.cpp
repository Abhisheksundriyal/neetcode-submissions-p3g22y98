class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> myQue;
    vector<int> ans;
    int idx=0;
    for(int i=0;i<nums.size();i++)
    {
        while(!myQue.empty() && nums[myQue.back()]<=nums[i])
            myQue.pop_back();
        myQue.push_back(i);
        while((i-idx+1)>k)
        {
            idx++;
            while(myQue.front()<idx)
                myQue.pop_front();
        }
        if((i-idx+1)==k)
            ans.push_back(nums[myQue.front()]);
    }
    return ans;
    }
};
