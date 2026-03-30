class Solution {
public:
    void reverse(vector<int>& nums,int l,int r)
{
    while(l<r)
    {
        swap(nums[l],nums[r]);
        l++;
        r--;
    }
}

char intToChar(int num)
{
    char ans=num+'0';
    return ans;
}

int charToInt(char ch)
{
    int ans=ch-'0';
    return ans;
}

vector<int> addNums(vector<int>& num1,vector<int>& num2)
{
    int idx1=num1.size()-1,idx2=num2.size()-1,carry=0;
    vector<int> ans;
    while(idx1>=0 || idx2>=0)
    {
        int a=0,b=0,temp=0;
        if(idx1>=0)
            a=num1[idx1];
        if(idx2>=0)
            b=num2[idx2];
        temp=a+b+carry;
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
        if(idx1>=0)
            idx1--;
        if(idx2>=0)
            idx2--;
    }
    if(carry==1)
        ans.push_back(1);
    reverse(ans,0,ans.size()-1);
    return ans;
}

vector<int> multiplyArr(vector<int>& V,int num,int x)
{
    int carry=0;
    vector<int> ans;
    for(int i=0;i<x;i++)
        ans.push_back(0);
    for(int i=V.size()-1;i>=0;i--)
    {
        int temp=(V[i]*num)+carry;
        if(temp>9)
        {
            ans.push_back(temp%10);
            temp=temp/10;
            carry=temp;
        }
        else
        {
            ans.push_back(temp);
            carry=0;
        }
    }
    if(carry!=0)
        ans.push_back(carry);
    reverse(ans,0,ans.size()-1);
    return ans;
}

string multiply(string num1,string num2)
{
    int x=0,count=0;
    vector<int> N1,N2,ans;
    ans.push_back(0);
    string num;
    for(int i=0;i<num1.length();i++)
        N1.push_back(charToInt(num1[i]));
    for(int i=0;i<num2.length();i++)
        N2.push_back(charToInt(num2[i]));
    for(int i=N1.size()-1;i>=0;i--)
    {
        vector<int> temp=multiplyArr(N2,N1[i],x);
        x++;
        ans=addNums(ans,temp);
    }
    for(int i=0;i<ans.size();i++)
    {
        num.push_back(intToChar(ans[i]));
        if(ans[i]==0)
            count++;
    }
    if(count==ans.size())
        return "0";
    return num;
}
};
