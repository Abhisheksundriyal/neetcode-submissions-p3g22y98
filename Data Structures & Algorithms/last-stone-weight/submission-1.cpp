class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> maxHeap;
        for(int i=0;i<stones.size();i++)
            maxHeap.push(stones[i]);
        while(maxHeap.size()>1)
        {
            int x=maxHeap.top(),y;
            maxHeap.pop();
            y=maxHeap.top();
            maxHeap.pop();
            if(x!=y)
                maxHeap.push(x-y);
        }
        if(maxHeap.empty())
            return 0;
        return maxHeap.top();
    }
};
