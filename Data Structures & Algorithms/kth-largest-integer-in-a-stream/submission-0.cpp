class KthLargest {
public:
    int K;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i=0;i<nums.size();i++)
            minHeap.push(nums[i]);
    }
    
    int add(int val) {
        minHeap.push(val);
        while(minHeap.size()>K)
            minHeap.pop();
        return minHeap.top();
    }
};
