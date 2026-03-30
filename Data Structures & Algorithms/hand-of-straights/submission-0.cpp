class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset<int> mySet;
    int n=hand.size(),k=groupSize;
    for(int i=0;i<n;i++)
        mySet.insert(hand[i]);
    while(!mySet.empty())
    {
        auto itr=mySet.begin();
        int num=(*itr),count=1;
        mySet.erase(itr);
        while(count<k)
        {
            num++;
            itr=mySet.find(num);
            if(itr==mySet.end())
                return false;
            else
            {
                mySet.erase(itr);
                count++;
            }
        }
    }
    return true;
    }
};
