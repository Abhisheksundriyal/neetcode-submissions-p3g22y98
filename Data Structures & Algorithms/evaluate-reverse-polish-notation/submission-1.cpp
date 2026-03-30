class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans=0;
        stack<string> myStac;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                int num2=stoi(myStac.top()),num1,temp;
                myStac.pop();
                num1=stoi(myStac.top());
                myStac.pop();
                if(tokens[i]=="+")
                    temp=num1+num2;
                else if(tokens[i]=="-")
                    temp=num1-num2;
                else if(tokens[i]=="*")
                    temp=num1*num2;
                else if(tokens[i]=="/")
                    temp=num1/num2;
                myStac.push(to_string(temp));
            }
            else
                myStac.push(tokens[i]);
        }
        return stoi(myStac.top());
    }
};
