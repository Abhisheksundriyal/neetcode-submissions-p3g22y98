class MedianFinder {
    priority_queue<int,vector<int>> maxHeap;
    priority_queue<int,vector<int>,greater<>> minHeap;
    int N;
public:
    MedianFinder() {
        N=0;
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        N++;
        int need=(N/2)+1;
        while(maxHeap.size()>need)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        while(!minHeap.empty() && !maxHeap.empty() && minHeap.top()<maxHeap.top())
        {
            int num1=minHeap.top(),num2=maxHeap.top();
            minHeap.pop();
            maxHeap.pop();
            minHeap.push(num2);
            maxHeap.push(num1);
        }
    }
    
    double findMedian() {
        if(N%2==1)
            return (double)maxHeap.top();
        double num1=maxHeap.top(),num2,ans;
        maxHeap.pop();
        num2=maxHeap.top();
        maxHeap.push(num1);
        ans=(num1+num2)/2;
        return ans;
    }
};
