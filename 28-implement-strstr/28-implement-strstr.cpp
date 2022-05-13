class Solution {
public:
    int strStr(string h, string s) {
        int n1 = h.size();
        int n2 = s.size();
        int len = n1 - n2;
        int iter,j = 0;
        int ans = -1;
        for(int i = 0 ; i <= len ; i++)
        {
            iter = i;
            j = 0;
            while(h[iter] == s[j])
            {
                iter++,j++;
                if(j == n2)
                {
                    ans = iter - j;
                    goto end;
                }
            }
        }
        end:
        return ans;
    }
};