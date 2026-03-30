class CountSquares {
public:
    unordered_map<int,unordered_map<int,int>> mp;
    CountSquares() {
        mp.clear();
    }
    
    void add(vector<int> point) {
        mp[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int ans=0,x=point[0],y=point[1];
        for(auto itr=mp.begin();itr!=mp.end();++itr) {
            int x1=(*itr).first;
            for(auto itr1=mp[x1].begin();itr1!=mp[x1].end();++itr1) {
                int y1=(*itr1).first;
                if((x==x1 || y==y1) || (abs(x1-x)!=abs(y1-y)))
                    continue;
                if(mp[x][y1]!=0 && mp[x1][y]!=0)
                    ans+=(mp[x1][y1]*mp[x][y1]*mp[x1][y]);
            }
        }
        return ans;
    }
};
