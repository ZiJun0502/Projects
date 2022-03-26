class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        if(num1[0] == '0' || num2[0] =='0') return "0";
        int anss[len1+len2+1];
        for(int i = 0 ; i < len1+len2 ; i++) anss[i] = 0;
        int temp = 0;
        for(int i = len1-1 ; i >= 0 ; i--)
        {
            for(int j = len2-1 ; j >= 0 ; j--)
            {
                temp = ((int)(num1[i]-'0') * (int)(num2[j]-'0'));
                anss[len1-1+len2-1 - i - j]+= temp%10;
                anss[len1-1+len2-1 - i - j + 1]+=temp/10;
            }
        }
        string ans;
        for(int i = 0 ; i < len1+len2 ; i++)
        {
            anss[i+1] += anss[i]/10;
            ans.push_back(anss[i]%10+'0');
        }
        if(ans[len1+len2-1] == '0') ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};