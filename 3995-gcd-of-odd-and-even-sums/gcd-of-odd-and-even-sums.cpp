class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long oddSum = (long long)n * n;       
        long long evenSum = (long long)n * (n + 1);  

        while (oddSum != 0) {
            long long temp = oddSum;
            oddSum = evenSum % oddSum;
            evenSum = temp;
        }
        return (int)evenSum;
    }
};