class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int n = d.size();
        for(int i = n -1; i >= 0 ; i--)
        {
            if(d[i] == 9)
            {
                d[i] = 0;
            }
            else
            {
                d[i]++;
                break;
            }
        }
        if(d[0] == 0)
        {
            d.insert(d.begin(),1);
        }
        return d;
    }
};