class Solution {
public:
    struct pt
    {
        int i;
        int j;
    };
    void rotate(vector<vector<int>>& m) {
        pt pos1, pos2, pos3, pos4;
        int n = m.size()-1;
        //diagonal length / 2
        int size = (n+1) / 2;
        int len = n;
        // record starting value for swapping
        for(int i = 0 ; i < size ; i++)
        {
            for(int j = 0 ; j < len ; j++)
            {
                pos1.i = i;
                pos1.j = i + j;
                pos2.i = i + j;
                pos2.j = n - i;
                pos3.i = n - i;
                pos3.j = n - j - i;
                pos4.i = n - j - i;
                pos4.j = i;
                swap(m[pos4.i][pos4.j], m[pos1.i][pos1.j]);
                swap(m[pos4.i][pos4.j], m[pos3.i][pos3.j]);
                swap(m[pos2.i][pos2.j], m[pos3.i][pos3.j]);
            }
            len -= 2;
        }
        return;
    }
};