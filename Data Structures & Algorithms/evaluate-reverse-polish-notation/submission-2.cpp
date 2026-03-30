class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> V;
    int n=tokens.size(),m=0;
    for(int i=0;i<n;i++)
    {
        if((tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"))
        {
            // cout<<"pushing: "<<stoi(tokens[i])<<"\n";
            V.push_back(stoi(tokens[i]));
            m++;
        }
        else
        {
            int num2=V[m-1],num1=V[m-2];
            // cout<<"num1: "<<num1<<" num2: "<<num2<<"\n";
            V.pop_back();
            V.pop_back();
            if(tokens[i]=="+")
                V.push_back(num1+num2);
            else if(tokens[i]=="-")
                V.push_back(num1-num2);
            else if(tokens[i]=="*")
                V.push_back(num1*num2);
            else
                V.push_back(num1/num2);
            m--;
        }
        // cout<<"V: ";
        // for(int j=0;j<V.size();j++)
        //     cout<<V[j]<<" ";
        // cout<<"\n";
    }
    return V[m-1];
    }
};
