class Solution {
public:
    bool check(vector<string>& V,int idx) {
        char ch='?';
        for(int i=0;i<(int)V.size();i++) {
            if(idx>=V[i].size()) return false;

            if(ch=='?') ch=V[i][idx];
            else {
                if(ch!=V[i][idx]) return false;
            }
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int idx=0;
        while(check(strs,idx)) idx++;

        string ans;
        for(int i=0;i<idx;i++) ans.push_back(strs[0][i]);
        return ans;
    }
};