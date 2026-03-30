class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> mp;
        int n=hand.size();
        priority_queue<int,vector<int>,greater<>> minHeap;
        for(int i=0;i<n;i++)
        {
            mp[hand[i]]++;
            minHeap.push(hand[i]);
        }
        while(!minHeap.empty())
        {
            int num=minHeap.top();
            minHeap.pop();
            if(mp[num]!=0)
            {
                for(int i=num;i<num+groupSize;i++)
                {
                    if(mp[i]==0)
                        return false;
                    mp[i]--;
                }
            }
        }
        return true;
    }
};
