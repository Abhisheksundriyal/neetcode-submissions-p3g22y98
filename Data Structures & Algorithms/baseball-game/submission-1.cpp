class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> temp;
        int sum=0,n=operations.size();
        for(int i=0;i<n;i++) {
            if(operations[i]=="+")
            {
                // cout<<"temp.size(): "<<temp.size()<<"\n";
                // cout<<"temp[temp.size()]: "<<temp[temp.size()]<<"\n";
                // cout<<"temp[temp.size()-1]: "<<temp[temp.size()-1]<<"\n";
                int x=(temp[temp.size()-1]+temp[temp.size()-2]);
                // cout<<"adding: "<<x<<"\n";
                temp.push_back(x);
                sum+=x;
            }
            else if(operations[i]=="C") {
                int x=temp.back();
                // cout<<"subtracting "<<x<<"\n";
                sum-=x;
                temp.pop_back();
            }
            else if(operations[i]=="D") {
                int x=temp.back()*2;
                sum+=x;
                // cout<<"adding: "<<x<<"\n";
                temp.push_back(x);
            }
            else {
                int x=stoi(operations[i]);
                // cout<<"adding: "<<x<<"\n";
                sum+=x;
                temp.push_back(x);
            }
        }
        return sum;
    }
};