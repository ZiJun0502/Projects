class Solution {
public:
    int temp;
    int solve(int i)
    {
        if(i == temp) return 0;
        if(i > temp)
        {
            if(i % 2 == 0) return 1 + solve(i / 2);
            return 1 + solve(i + 1);
        }
        return temp - i;
            
        
    }
    int brokenCalc(int a, int target) 
    {
        temp = a;
        if(target % 2 == 0 && target > a) return 1 + solve(target / 2);
        else return solve(target);
    }
};