class TimeMap {
public:

    unordered_map<string,vector<pair<int,string>>> myMap;

    TimeMap() {
        myMap.clear();
    }
    
    void set(string key, string value, int timestamp) {
        myMap[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int l=0,r=myMap[key].size()-1;
        string ans;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(myMap[key][mid].first<=timestamp)
            {
                ans=myMap[key][mid].second;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return ans;
    }
};
