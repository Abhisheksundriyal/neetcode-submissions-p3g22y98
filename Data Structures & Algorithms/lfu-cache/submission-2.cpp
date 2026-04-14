class LFUCache {
public:
    int N,x;
    unordered_map<int,int> myMap;
    unordered_map<int,int> occ;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> minHeap;
    LFUCache(int capacity) {
        N=capacity;
        x=0;
        myMap.clear();
        occ.clear();
        while(!minHeap.empty()) minHeap.pop();
    }
    int get(int key) {
        if(myMap.find(key)==myMap.end()) return -1;
        occ[key]++;
        x++;
        minHeap.push({occ[key],{x,key}});
        return myMap[key];
    }
    void put(int key, int value) {
        if(myMap.find(key)!=myMap.end()) {
            myMap[key]=value;
            occ[key]++;
            x++;
            minHeap.push({occ[key],{x,key}});
            return;
        }
        if(myMap.size()<N) {
            myMap[key]=value;
            occ[key]++;
            x++;
            minHeap.push({occ[key],{x,key}});
            return;
        }
        while(!minHeap.empty()) {
            pair<int,pair<int,int>> p=minHeap.top();
            minHeap.pop();
            if(occ[p.second.second]==p.first) {
                myMap.erase(p.second.second);
                occ.erase(p.second.second);
                break;
            }
        }
        myMap[key]=value;
        occ[key]++;
        x++;
        minHeap.push({occ[key],{x,key}});
    }
};