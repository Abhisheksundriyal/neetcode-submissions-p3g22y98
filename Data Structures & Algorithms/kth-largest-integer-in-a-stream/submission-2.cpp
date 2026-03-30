class KthLargest {
public:
    priority_queue<int,vector<int>,greater<>> minHeap;
    int N;
    KthLargest(int k, vector<int>& nums) {
        N=k;
        for(int i=0;i<nums.size();i++)
        {
            if(minHeap.size()<k)
            {
                minHeap.push(nums[i]);
                continue;
            }
            if(minHeap.top()>=nums[i])
                continue;
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }
    
    int add(int val) {
        if(minHeap.size()<N)
            minHeap.push(val);
        else
        {
            if(minHeap.top()<val)
            {
                minHeap.pop();
                minHeap.push(val);
            }
        }
        return minHeap.top();
    }
};
