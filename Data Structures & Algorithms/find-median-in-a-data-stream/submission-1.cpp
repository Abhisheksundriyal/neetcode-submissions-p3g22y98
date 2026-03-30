class MedianFinder {
public:

    priority_queue<int,vector<int>,greater<int>> minHeap;
    priority_queue<int,vector<int>> maxHeap;
    int N;

    MedianFinder() {
        while(!minHeap.empty())
            minHeap.pop();
        while(!maxHeap.empty())
            maxHeap.pop();
        N=0;
    }
    
    void addNum(int num) {
        N++;
        int need=N/2;
        need++;
        maxHeap.push(num);
        while(maxHeap.size()>need)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        while(!minHeap.empty() && !maxHeap.empty() && maxHeap.top()>minHeap.top())
        {
            int a=minHeap.top(),b=maxHeap.top();
            minHeap.pop();
            maxHeap.pop();
            minHeap.push(b);
            maxHeap.push(a);
        }
    }
    
    double findMedian() {
        if(N%2==1)
            return maxHeap.top();
        double a=maxHeap.top(),b=0,ans=0;
        maxHeap.pop();
        b=maxHeap.top();
        maxHeap.push(a);
        ans=(a+b)/2;
        return ans;
    }
};
