class Solution {
public:
    bool isValid(string s) {
        vector<char> V;
        int n=s.size(),m=0;
        for(int i=0;i<n;i++)
        {
            if(m==0 || s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                V.push_back(s[i]);
                m++;
            }
            else
            {
                if(s[i]==')')
                {
                    if(V[m-1]=='(')
                    {
                        V.pop_back();
                        m--;
                    }
                    else
                        return false;
                }
                else if(s[i]=='}')
                {
                    if(V[m-1]=='{')
                    {
                        V.pop_back();
                        m--;
                    }
                    else
                        return false;
                }
                else
                {
                    if(V[m-1]=='[')
                    {
                        V.pop_back();
                        m--;
                    }
                    else
                        return false;
                }
            }
        }
        return (V.size()==0);
    }
};
