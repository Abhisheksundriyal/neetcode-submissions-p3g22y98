class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx1=0,idx2=0;
        swap(s,t);
        while(idx2<(int)t.size()) {
            while(idx1<(int)s.size() && s[idx1]!=t[idx2]) idx1++;

            if(idx2<(int)t.size() && idx1>=(int)s.size()) return false;

            idx1++;
            idx2++;
        }
        return true;
    }
};