class Solution {
public:
    int n;
    vector<vector<char>>* arr;
    bool valid(int i, int j, int k)
    {
        for(int ii = 0 ; ii < n ; ii++)
            if((*arr)[ii][j]-'0' == k) return false;
        for(int jj = 0 ; jj < n ; jj++)
            if((*arr)[i][jj]-'0' == k) return false;
        int istart = i - i%3;
        int jstart = j - j%3;
        for(int ii = istart ; ii < istart+3 ; ii++)
            for(int jj = jstart ; jj < jstart + 3 ; jj++)
                if((*arr)[ii][jj]-'0' == k) return false;
        return true;
    }
    bool help(int i, int j)
    {
        if(j == 9) return help(i+1, 0);
        if(i == 9) return true;
        if((*arr)[i][j] =='.')
        {
            //cout << i << ' ' << j << '\n';
            for(int k = 1 ; k < 10 ; k++)
            {
                if(valid(i, j, k))
                {
                    (*arr)[i][j] = k + '0';
                    if(help(i, j+1) == true) return true;
                    (*arr)[i][j] = '.';
                }
            }
        }
        else return help(i, j+1);
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        n = board.size();
        arr = &board;
        help(0,0);
    }
};