class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        long temp = 0;
        int to = 1;
        int count = 0;
        while(s[i] == ' ') i++;
        if(s[i] =='-') {to = -1; i++;}
            else if(s[i] =='+'){i++;}
        for(;;)
        {
            if(!(s[i]>='0' && s[i]<='9')) break;
            temp = temp * 10 + s[i++] - '0';
            if(temp > INT_MAX || temp < INT_MIN)
            {
                temp*=to;
                return temp > 0 ? INT_MAX : INT_MIN;
            }

        }
        temp*=to;
        return temp;
    }
};