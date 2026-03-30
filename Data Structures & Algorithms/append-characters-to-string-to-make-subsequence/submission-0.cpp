class Solution {
public:
    int recur(string& s,string& t,int idx1,int idx2) {
        if(idx2>=t.size()) return 0;

        if(idx1>=s.size()) return (t.size()-idx2);

        if(s[idx1]==t[idx2]) return recur(s,t,idx1+1,idx2+1);

        return recur(s,t,idx1+1,idx2);
    }
    int appendCharacters(string s, string t) {
        return recur(s,t,0,0);
    }
};