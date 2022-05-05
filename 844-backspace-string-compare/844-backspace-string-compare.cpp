class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ss, tt;
        char c;
        int a = s.size();
        for(int i = 0 ; i < a ; i++)
        {
            c = s[i];
            if(c =='#')
            {
                if(ss.size() > 0)
                ss.pop_back();  
            }
            else
            {
                ss.push_back(c);
            }
        }
        a = t.size();
        for(int i = 0 ; i < a ; i++)
        {
            c = t[i];
            if(c =='#')
            {
                if(tt.size() > 0)
                tt.pop_back();  
            }
            else
            {
                tt.push_back(c);
            }
        }
        return tt.compare(ss) == 0;
    }
};