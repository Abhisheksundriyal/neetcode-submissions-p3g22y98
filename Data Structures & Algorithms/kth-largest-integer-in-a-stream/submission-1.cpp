class KthLargest {

    priority_queue<int,vector<int>,greater<int>> minHeap;
    int N;

public:
    KthLargest(int k, vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            minHeap.push(nums[i]);
            if(minHeap.size()>k)
                minHeap.pop();
        }
        N=k;
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>N)
            minHeap.pop();
        return minHeap.top();
    }
};
