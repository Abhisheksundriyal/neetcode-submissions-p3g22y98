class CountSquares {
public:

    map<pair<int,int>,int> myMap;

    CountSquares() {
        myMap.clear();
    }
    
    void add(vector<int> point) {
        pair<int,int> p={point[0],point[1]};
        myMap[p]++;
    }
    
    int count(vector<int> point) {
        int ans=0;
        for(auto itr=myMap.begin();itr!=myMap.end();++itr)
        {
            pair<pair<int,int>,int> p=(*itr);
            if(p.first.first!=point[0] && p.first.second!=point[1])
            {
                pair<int,int> a,b;
                a.first=point[0];
                a.second=p.first.second;
                b.first=p.first.first;
                b.second=point[1];
                ans+=(myMap[a]*myMap[b]*myMap[p.first]);
            }
        }
        return ans;
    }
};
