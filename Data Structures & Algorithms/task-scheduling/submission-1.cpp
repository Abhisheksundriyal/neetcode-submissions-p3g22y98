class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
{
    int N=tasks.size(),ans=0;
    if(n==0)
        return N;
    vector<int> cnt(30,0),nums;
    for(int i=0;i<N;i++)
        cnt[tasks[i]-'A']++;
    for(char ch='A';ch<='Z';ch++)
    {
        if(cnt[ch-'A']>0)
            nums.push_back(cnt[ch-'A']);
    }
    sort(nums.begin(),nums.end(),greater<int>());
    N=nums.size();
    // cout<<"nums: ";
    // for(int i=0;i<N;i++)
    //     cout<<nums[i]<<" ";
    // cout<<"\n";
    while(N>n)
    {
        if(nums[N-1]==0)
        {
            nums.pop_back();
            N--;
        }
        else
        {
            for(int i=0;i<=n;i++)
            {
                nums[i]--;
                ans++;
            }
            sort(nums.begin(),nums.end(),greater<int>());
        }
    }
    while(N>0)
    {
        if(nums[N-1]==0)
        {
            nums.pop_back();
            N--;
        }
        else
        {
            int count=0;
            for(int i=0;i<N;i++)
            {
                nums[i]--;
                if(nums[i]>0)
                    count++;
                ans++;
            }
            if(count>0)
                ans+=((n+1)-N);
        }
    }
    return ans;
}
};
