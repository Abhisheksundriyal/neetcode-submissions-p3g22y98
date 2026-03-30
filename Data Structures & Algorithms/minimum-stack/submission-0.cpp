class MinStack {
public:

    stack<pair<int,int>> myStac;

    MinStack() {
        while(!myStac.empty())
            myStac.pop();
    }
    
    void push(int val) {
        pair<int,int> p={val,val};
        if(!myStac.empty())
            p.second=min(myStac.top().second,p.second);
        myStac.push(p);
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
