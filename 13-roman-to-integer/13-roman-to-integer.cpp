class Solution {
public:
    int romanToInt(string s) {
        int ans = 0, i = 0;
        while(i < s.size())
        {
            switch(s[i])
            {
                    case'M':
                    ans += 1000;
                    i++;
                    break;
                    case'D':
                    ans += 500;
                    i++;
                    break;
                    case'C':
                    switch(s[i + 1])
                    {
                            case'D':
                            ans += 400;
                            i+=2;
                            continue;
                            case'M':
                            ans += 900;
                            i+=2;
                            continue;
                    }
                    ans += 100;
                    i++;
                    break;
                    case'L':
                    ans += 50;
                    i++;
                    break;
                    case'X':
                    switch(s[i + 1])
                    {
                            case'L':
                            ans += 40;
                            i+=2;
                            continue;
                            case'C':
                            ans += 90;
                            i+=2;
                            continue;
                    }
                    ans += 10;
                    i++;
                    break;
                    case'V':
                    ans += 5;
                    i++;
                    break;
                    case'I':
                    switch(s[i + 1])
                    {
                            case'V':
                            ans+=4;
                            i+=2;
                            continue;
                            case'X':
                            ans += 9;
                            i+=2;
                            continue;
                    }
                    ans += 1;
                    i++;
                    break;
            }
        }
        return ans;
    }
};