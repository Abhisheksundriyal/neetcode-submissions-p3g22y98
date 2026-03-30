class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> minHeap;
    priority_queue<int,vector<int>> maxHeap;
    int N;
    MedianFinder() {
        N=0;
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        N++;
        int need=(N/2);
        need++;
        // cout<<"need: "<<need<<"\n";
        while(maxHeap.size()>need)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        while(maxHeap.size()<need)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        while(!minHeap.empty() && !maxHeap.empty() && maxHeap.top()>minHeap.top())
        {
            int a=maxHeap.top(),b=minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(b);
            minHeap.push(a);
        }
    }
    
    double findMedian() {
        
        // cout<<"N: "<<N<<"\n";
        if(N%2==1)
            return maxHeap.top();
        double a=maxHeap.top();
        maxHeap.pop();
        double b=maxHeap.top(),ans=(a+b)/2;
        maxHeap.push(a);
        return ans;
    }
};
