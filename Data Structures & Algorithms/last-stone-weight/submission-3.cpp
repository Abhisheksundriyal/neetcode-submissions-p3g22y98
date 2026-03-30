class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> maxHeap;
        for(int i=0;i<stones.size();i++)
            maxHeap.push(stones[i]);
        while(maxHeap.size()>1)
        {
            int a=maxHeap.top(),b;
            maxHeap.pop();
            b=maxHeap.top();
            maxHeap.pop();
            if(a!=b)
                maxHeap.push(abs(a-b));
        }
        if(maxHeap.empty())
            return 0;
        return maxHeap.top();
    }
};
