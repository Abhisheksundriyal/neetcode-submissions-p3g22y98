class MyHashSet {
public:
    vector<int> mp;
    MyHashSet() {
        mp.resize(1e6+1,0);
    }
    
    void add(int key) {
        mp[key]=1;
    }
    
    void remove(int key) {
        mp[key]=0;
    }
    
    bool contains(int key) {
        return mp[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */