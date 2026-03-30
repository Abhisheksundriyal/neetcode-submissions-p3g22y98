class LRUCache {
    unordered_map<int,int> val;
    queue<int> que;
    unordered_map<int,int> cnt;
    int N;
public:
    LRUCache(int capacity) {
        N=capacity;
    }
    
    int get(int key) {
        if(val.find(key)==val.end())
            return -1;
        que.push(key);
        cnt[key]++;
        return val[key];
    }
    
    void put(int key, int value) {
        if(val.size()==N && val.find(key)==val.end())
        {
            while(cnt[que.front()]>1)
            {
                cnt[que.front()]--;
                que.pop();
            }
            val.erase(que.front());
            cnt[que.front()]=0;
            que.pop();
        }
        val[key]=value;
        que.push(key);
        cnt[key]++;
    }
};
