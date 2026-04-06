class FreqStack {
public:
    int idx;
    priority_queue<pair<int,pair<int,int>>> maxHeap;
    unordered_map<int,int> mp;
    FreqStack() {
        idx=0;
        while(!maxHeap.empty()) maxHeap.pop();
        mp.clear();
    }
    
    void push(int val) {
        idx++;
        mp[val]++;
        maxHeap.push({mp[val],{idx,val}});
    }
    
    int pop() {
        int ans;
        while(!maxHeap.empty()) {
            pair<int,pair<int,int>> p=maxHeap.top();
            maxHeap.pop();
            int occ=p.first,val=p.second.second;
            if(mp[val]!=occ) continue;
            else {
                ans=val;
                mp[val]--;
                break;
            }
        }
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */