class Solution {
public:
    int numSquares(int n) {
        // let arr[i] denote the least number of perfect square numbers that sums to i;
        // for arr[i], it may be arr[i-1] + 1 or arr[i-4] + 1 or arr[i-9] + 1
        //e.g. 17 = arr[16] + 1
        //        = arr[13] + 4
        //        = arr[8] + 9
        //        = arr[1] + 16
        int arr[n+1];
        for(int i = 2 ; i <= n ; i ++)
            arr[i] = 21474836;
        arr[0] = 0;
        arr[1] = 1;
        for(int i = 2 ; i < n + 1 ; i++)
            for(int j = 1 ; j*j <= i ; j++)
            {
                arr[i] = min(arr[i], 1 + arr[i-j*j]);
            }
        

        return arr[n];
    }
};