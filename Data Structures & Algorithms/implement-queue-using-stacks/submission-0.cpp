class MyQueue {
public:
    stack<int> myStac;
    MyQueue() {
        while(!myStac.empty()) myStac.pop();
    }
    
    void push(int x) {
        myStac.push(x);
    }
    
    int pop() {
        stack<int> temp;
        while(myStac.size()>1) {
            temp.push(myStac.top());
            myStac.pop();
        }
        int ans=myStac.top();
        myStac.pop();
        while(!temp.empty()) {
            myStac.push(temp.top());
            temp.pop();
        }
        return ans;
    }
    
    int peek() {
        stack<int> temp;
        while(myStac.size()>1) {
            temp.push(myStac.top());
            myStac.pop();
        }
        int ans=myStac.top();
        temp.push(myStac.top());
        myStac.pop();
        while(!temp.empty()) {
            myStac.push(temp.top());
            temp.pop();
        }
        return ans;
    }
    
    bool empty() {
        return myStac.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */