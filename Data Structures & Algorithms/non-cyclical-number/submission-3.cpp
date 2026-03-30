class Solution {
public:
    int solve(int n) {
        int ans=0;
        while(n>0)
        {
            int num=n%10;
            n=n/10;
            ans+=(num*num);
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int> mySet;
        while(n!=1)
        {
            n=solve(n);
            if(mySet.find(n)==mySet.end())
                mySet.insert(n);
            else
                return false;
        }
        return true;
    }
};
