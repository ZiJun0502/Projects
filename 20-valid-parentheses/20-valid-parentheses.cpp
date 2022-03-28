class Solution {
public:
    char pair(char c)
    {
        switch(c)
        {
            case'(':
            return ')';
            case'[':
            return ']';
            case'{':
            return '}';
        }
        return ' ';
    }
    bool isValid(string s) {
        int len = s.size();
        char stack[len+1]; int slen = 0;
        for(int i = 0 ; i < len ; i++)
        {
            if(slen != 0 && pair(stack[slen-1]) == s[i])
            {
                slen--;
            }
            else stack[slen++] = s[i];
        }
        if(slen == 0) return true;
        return false;
    }
};