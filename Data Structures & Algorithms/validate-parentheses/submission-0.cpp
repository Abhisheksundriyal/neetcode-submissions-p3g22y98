class Solution {
public:


    bool isValid(string s) {
        stack<char> myStac;
        for(int i=0;i<s.length();i++)
        {
            if(myStac.empty() || s[i]=='(' || s[i]=='{' || s[i]=='[')
                myStac.push(s[i]);
            else
            {
                if(s[i]==')')
                {
                    if(myStac.top()=='(')
                        myStac.pop();
                    else
                        return false;
                }
                else if(s[i]=='}')
                {
                    if(myStac.top()=='{')
                        myStac.pop();
                    else
                        return false;
                }
                else
                {
                    if(myStac.top()=='[')
                        myStac.pop();
                    else
                        return false;
                }
            }
        }
        return (myStac.empty());
    }
};
