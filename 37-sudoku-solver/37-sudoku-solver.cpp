class Solution {
public:
    #define vi vector<int>
    #define vvi vector<vi>
    #define For(i, n) for(int i = 0 ; i < n ; i++)
    #define FOR(i, n , m) for(int i = n ; i < m ; i++)
    int lg(int n){
        switch (n){
            case 1:return 1;
            case 2:return 2;
            case 4:return 3;
            case 8:return 4;
            case 16:return 5;
            case 32:return 6;
            case 64:return 7;
            case 128:return 8;
            case 256:return 9;
            case 512:return 0;
        }
        return -1;
    }
    int col[9];
    int row[9];
    int s_grid[3][3];
    const int mask = 511;
    int lowbit(int n){
        return (n & -n);
    }
    bool find(int i, int j, vector<vector<char>>& board){
        if(i == 9){
            return 1;
        }
        if(isdigit(board[i][j])){
            if(find(j==8?i+1:i, j==8?0:j+1, board)){
                return 1;
            }
        }else{
            int nums = (mask & ~(col[j] | row[i] | s_grid[i/3][j/3]));
            for(int num = 0 ; nums != 0 ;){
                num = lowbit(nums);
                nums ^= num;
                col[j] ^= num;
                row[i] ^= num;
                s_grid[i/3][j/3] ^= num;
                board[i][j] = lg(num) + '0';
                if(find(j==8?i+1:i, j==8?0:j+1, board)){
                    return 1;
                }
                col[j] ^= num;
                row[i] ^= num;
                board[i][j] = '.';
                s_grid[i/3][j/3] ^= num;
            }
        }
        return 0;
    }
    void solve(vector<vector<char>>& board){
        For(i, 9){
            For(j,  9){
                if(isdigit(board[i][j])){
                    int temp = 1 << (board[i][j] - '1');
                    col[j]^= temp;
                    row[i]^= temp;
                    s_grid[i/3][j/3] ^= temp;
                }
            }
        }
        find(0, 0, board);
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};