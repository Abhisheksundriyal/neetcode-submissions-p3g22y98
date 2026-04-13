class MyCircularQueue {
public:
    queue<int> myQue;
    int n;
    MyCircularQueue(int k) {
        n=k;
        while(!myQue.empty()) myQue.pop();
    }
    
    bool enQueue(int value) {
        if(myQue.size()==n) return false;
        myQue.push(value);
        return true;
    }
    
    bool deQueue() {
        if(myQue.empty()) return false;
        myQue.pop();
        return true;
    }
    
    int Front() {
        if(myQue.empty()) return -1;
        return myQue.front();
    }
    
    int Rear() {
        if(myQue.empty()) return -1;
        return myQue.back();
    }
    
    bool isEmpty() {
        return myQue.empty();
    }
    
    bool isFull() {
        return (myQue.size()==n);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */