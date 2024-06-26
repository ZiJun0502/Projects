class Solution {
public:
    int countOperations(int num1, int num2, int count = 0) {
        if(num1 == 0 || num2 == 0) return count;
        if(num1 > num2)
        {
            return countOperations(num1 - num2, num2, count + 1);
        }
        else if(num1 < num2) return countOperations(num1, num2 - num1, count + 1);
        else return count + 1;
        return 0;
    }
};