// https://leetcode.com/problems/coin-change/
// Coin Change

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

// Example 1:
// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

// Example 2:
// Input: coins = [2], amount = 3
// Output: -1

// Constraints:
// 1 <= coins.length <= 12
// 1 <= coins[i] <= 231 - 1
// 0 <= amount <= 104

// Solution 1: Top-Down DP
// Time complexity: O(n*amount)
// Space complexity: O(amount)
// Explanation: We can use a top-down DP approach to solve this problem. 
// We can use a dp array to store the minimum number of coins required to make up the amount i. We can initialize the dp array with amount + 1, which is the maximum possible value. 
// We can then iterate over the dp array and for each index i, we can iterate over the coins array and for each coin, we can check if the coin is less than or equal to the amount i. 
// If it is, we can update the dp array at index i by taking the minimum of the current value at index i and the value at index i - coin + 1. We can then return the value at index amount if it is less than or equal to amount, else we can return -1.

Class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
}

// Solution 2: Bottom-Up DP
// Time complexity: O(n*amount)
// Space complexity: O(amount)
// Explanation: We can use a bottom-up DP approach to solve this problem. We can use a dp array to store the minimum number of coins required to make up the amount i. 
// We can initialize the dp array with amount + 1, which is the maximum possible value. We can then iterate over the dp array and for each index i, we can iterate over the coins array and for each coin, 
// we can check if the coin is less than or equal to the amount i. If it is, we can update the dp array at index i by taking the minimum of the current value at index i and the value at index i - coin + 1. 
// We can then return the value at index amount if it is less than or equal to amount, else we can return -1.

Class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, amount + 1);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++) {
            for (int coin : coins) {
                if (i + coin <= amount) {
                    dp[i + coin] = Math.min(dp[i + coin], dp[i] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
}
