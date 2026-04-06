class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int n=s.size();
        string ans;
        for(int i=0;i<n;i++) {
            if(s[i]!=']') st.push(s[i]);
            else {
                string sub;
                while(st.top()!='[') {
                    sub.push_back(st.top());
                    st.pop();
                }
                st.pop();
                reverse(sub.begin(),sub.end());
                string num;
                while(!st.empty() && st.top()>='0' && st.top()<='9') {
                    num.push_back(st.top());
                    st.pop();
                }
                reverse(num.begin(),num.end());
                // cout<<"num: "<<num<<"\n";
                // cout<<"sub: "<<sub<<"\n";
                int x=stoi(num);
                // int x=0;
                for(int j=0;j<x;j++) {
                    for(int k=0;k<sub.size();k++) st.push(sub[k]);
                }
            }
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};