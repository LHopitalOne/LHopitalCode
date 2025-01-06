int climbStairs(int n)
{
    std::vector<int> dp(n, 0);
    dp[0] = 1;
    
    if (n >= 2)
    {
        dp[1] = 2;
        for (int i = 2; i < n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n - 1];
}
