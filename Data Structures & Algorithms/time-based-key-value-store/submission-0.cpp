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
        vector<pair<int,string>>& V=myMap[key];
        int l=0,r=V.size()-1;
        string ans="";
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(V[mid].first<=timestamp)
            {
                ans=V[mid].second;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return ans;
    }
};
