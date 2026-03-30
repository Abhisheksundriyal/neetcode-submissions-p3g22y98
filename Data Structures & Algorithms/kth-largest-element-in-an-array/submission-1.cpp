class Solution {
    priority_queue<int,vector<int>,greater<>> minHeap;
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++)
        {
            minHeap.push(nums[i]);
            if(minHeap.size()>k)
                minHeap.pop();
        }
        return minHeap.top();
    }
};
