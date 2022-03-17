class Solution {
public:
    string intToRoman(int num) {
        string s;
        if(num / 1000 > 0)
        {
            for(int i = 0; i < num / 1000;i++)
                s+="M";
            num%=1000;
        }
        if(num >= 900)
        {
            s+="CM";
            num-=900;
        }
        if(num / 500 > 0)
        {
            for(int i = 0; i < num / 500;i++)
                s+="D";
            num%=500;
        }
        if(num >= 400)
        {
            s+="CD";
            num-=400;
        }
        if(num / 100 > 0)
        {
            for(int i = 0; i < num /100;i++)
                s+="C";
            num%=100;
        }
        if(num >= 90)
        {
            s+="XC";
            num-=90;
        }
        if(num / 50 > 0)
        {
            for(int i = 0; i < num / 50;i++)
                s+="L";
            num%=50;
        }
        if(num >= 40)
        {
            s+="XL";
            num-=40;
        }
        if(num / 10 > 0)
        {
            for(int i = 0; i < num / 10;i++)
                s+="X";
            num%=10;
        }
        if(num >=9)
        {
            s+="IX";
            num-=9;
        }
        if(num / 5 > 0)
        {
            for(int i = 0; i < num / 5;i++)
                s+="V";
            num%=5;
        }
        if(num >= 4)
        {
            s+="IV";
            num-=4;
        }
        if(num > 0)
        {
            for(int i = 0; i < num ;i++)
                s+="I";
        }
        return s;
    }
};