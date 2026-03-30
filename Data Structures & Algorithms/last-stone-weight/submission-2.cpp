class Solution {
    priority_queue<int,vector<int>> maxHeap;
public:
    int lastStoneWeight(vector<int>& stones) {
        for(int i=0;i<stones.size();i++)
            maxHeap.push(stones[i]);
        while(maxHeap.size()>1)
        {
            int num1=maxHeap.top(),num2;
            maxHeap.pop();
            num2=maxHeap.top();
            maxHeap.pop();
            maxHeap.push(abs(num1-num2));
        }
        if(maxHeap.empty())
            return 0;
        return maxHeap.top();
    }
};
