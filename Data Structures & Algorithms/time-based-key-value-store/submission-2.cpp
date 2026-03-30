class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {

        int n=mp[key].size(),l=0,r=n-1;
        string ans;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(mp[key][mid].first<=timestamp)
            {
                ans=mp[key][mid].second;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return ans;
    }
};
