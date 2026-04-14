class LFUCache {
public:
    int N;
    unordered_map<int,int> myMap;
    unordered_map<int,int> occ;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minHeap;
    LFUCache(int capacity) {
        N=capacity;
        myMap.clear();
        occ.clear();
        while(!minHeap.empty()) minHeap.pop();
    }
    int get(int key) {
        if(myMap.find(key)==myMap.end()) return -1;
        occ[key]++;
        minHeap.push({occ[key],key});
        return myMap[key];
    }
    void put(int key, int value) {
        if(myMap.find(key)!=myMap.end()) {
            myMap[key]=value;
            occ[key]++;
            minHeap.push({occ[key],key});
            return;
        }
        if(myMap.size()<N) {
            myMap[key]=value;
            occ[key]++;
            minHeap.push({occ[key],key});
            return;
        }
        while(!minHeap.empty()) {
            pair<int,int> p=minHeap.top();
            minHeap.pop();
            if(occ[p.second]==p.first) {
                myMap.erase(p.second);
                occ.erase(p.second);
                break;
            }
        }
        myMap[key]=value;
        occ[key]++;
        minHeap.push({occ[key],key});
    }
};