class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry=1;
        for(int i=digits.size()-1;i>=0;i--)
        {
            int temp=digits[i]+carry;
            // cout<<"temp: "<<temp<<"\n";
            if(temp>9)
            {
                ans.push_back(temp%10);
                carry=1;
            }
            else
            {
                ans.push_back(temp);
                carry=0;
            }
        }
        if(carry!=0)
            ans.push_back(carry);
        // for(int i=0;i<ans.size();i++)
        //     cout<<ans[i]<<" ";
        // cout<<"\n";
        int l=0,r=ans.size()-1;
        while(l<r)
        {
            swap(ans[l],ans[r]);
            l++;
            r--;
        }
        return ans;
    }
};
