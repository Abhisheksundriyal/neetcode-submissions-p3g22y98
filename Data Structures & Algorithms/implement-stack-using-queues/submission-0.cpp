class MyStack {
public:
    queue<int> myQue;
    MyStack() {
        while(!myQue.empty()) myQue.pop();
    }
    
    void push(int x) {
        myQue.push(x);
    }
    
    int pop() {
        queue<int> temp;
        while(myQue.size()>1) {
            temp.push(myQue.front());
            myQue.pop();
        }
        int ans=myQue.front();
        myQue=temp;
        return ans;
    }
    
    int top() {
        queue<int> temp;
        while(myQue.size()>1) {
            temp.push(myQue.front());
            myQue.pop();
        }
        int ans=myQue.front();
        temp.push(myQue.front());
        myQue.pop();
        myQue=temp;
        return ans;
    }
    
    bool empty() {
        return myQue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */