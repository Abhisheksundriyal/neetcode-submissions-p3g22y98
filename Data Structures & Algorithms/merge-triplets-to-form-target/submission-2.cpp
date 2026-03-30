class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a=0,b=0,c=0;
        for(int i=0;i<triplets.size();i++)
        {
            if(triplets[i][0]==target[0] && triplets[i][1]<=target[1] &&
                triplets[i][2]<=target[2])
                a++;
            if(triplets[i][0]<=target[0] && triplets[i][1]==target[1] &&
                triplets[i][2]<=target[2])
                b++;
            if(triplets[i][0]<=target[0] && triplets[i][1]<=target[1] &&
                triplets[i][2]==target[2])
                c++;
        }
        return (a && b && c);
    }
};
