class Solution {
public:
    int nthUglyNumber(int n) {
        int arr[n];
        arr[0] = 1;
        int two,twos;
        int three,threes;
        int five,fives;
        int temp;
        two = three = five = 0;
        for(int i  = 1 ; i < n ; i++)
        {
            twos = arr[two]*2;
            threes = arr[three] * 3;
            fives = arr[five] * 5;
            temp = min(twos, min(threes,fives));
            if(temp == twos) two++;
            if(temp == threes) three++;
            if(temp == fives) five++;
            arr[i] = temp;
        }
        return arr[n-1];
    }
};