class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long int rev = 0, n = x;
        while(n)
        {
            rev = rev*10+n%10;
            n /= 10;
        }
        return rev == x;
    }
};