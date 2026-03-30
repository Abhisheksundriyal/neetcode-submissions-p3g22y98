class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        reverse(digits.begin(),digits.end());
        for(int i=0;i<digits.size();i++)
        {
            int num=digits[i]+carry;
            if(num<=9)
                carry=0;
            else
                carry=1;
            digits[i]=num%10;
        }
        if(carry!=0)
            digits.push_back(carry);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};
