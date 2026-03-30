class Solution {
public:
    int modify(int n)
{
    int ans=0;
    while(n>0)
    {
        ans+=((n%10)*(n%10));
        n=n/10;
    }
    return ans;
}

bool recur(int n,set<int>& mySet)
{
    if(n==1 || n==0)
        return true;
    if(mySet.find(n)!=mySet.end())
        return false;
    mySet.insert(n);
    n=modify(n);
    return recur(n,mySet);
}

bool isHappy(int n)
{
    set<int> mySet;
    return recur(n,mySet);
}
};
