class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    vector<int> cnt(26,0);
    int large=0,count=0,ans=0,sum=0;
    for(int i=0;i<tasks.size();i++)
    {
        cnt[tasks[i]-'A']++;
        large=max(large,cnt[tasks[i]-'A']);
    }
    for(int i=0;i<26;i++)
    {
        if(cnt[i]==large)
            count++;
        // cout<<cnt[i]<<"\n";
        sum+=cnt[i];
    }
    // cout<<"large: "<<large<<" count: "<<count<<" sum: "<<sum<<"\n";
    ans=((large-1)*(n+1))+count;
    return max(sum,ans);
}
};
