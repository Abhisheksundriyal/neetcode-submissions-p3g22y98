class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n=triplets.size();
        vector<int> V={0,0,0};
        for(int i=0;i<n;i++)
        {
            if(triplets[i][0]==target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2])
                V[0]=1;
            if(triplets[i][1]==target[1] && triplets[i][0]<=target[0] && triplets[i][2]<=target[2])
                V[1]=1;
            if(triplets[i][2]==target[2] && triplets[i][0]<=target[0] && triplets[i][1]<=target[1])
                V[2]=1;
        }
        if(V[0]+V[1]+V[2]!=3)
            return false;

        

        return true;

    }
};
