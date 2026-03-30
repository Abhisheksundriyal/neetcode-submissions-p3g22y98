class MinStack {
public:
    stack<pair<int,int>> myStac;
    MinStack() {
        while(!myStac.empty())
            myStac.pop();
    }
    
    void push(int val) {
        if(myStac.empty())
        {
            myStac.push({val,val});
            return;
        }
        myStac.push({val,min(val,myStac.top().second)});
    }
    
    void pop() {
        myStac.pop();
    }
    
    int top() {
        return myStac.top().first;
    }
    
    int getMin() {
        return myStac.top().second;
    }
};
