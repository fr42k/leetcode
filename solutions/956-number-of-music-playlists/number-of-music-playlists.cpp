// Your music player contains N different songs and she wants to listen to L (not necessarily different) songs during your trip.  You create a playlist so that:
//
//
// 	Every song is played at least once
// 	A song can only be played again only if K other songs have been played
//
//
// Return the number of possible playlists.  As the answer can be very large, return it modulo 10^9 + 7.
//
//  
//
//
//
//
// Example 1:
//
//
// Input: N = 3, L = 3, K = 1
// Output: 6
// Explanation: There are 6 possible playlists. [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].
//
//
//
// Example 2:
//
//
// Input: N = 2, L = 3, K = 0
// Output: 6
// Explanation: There are 6 possible playlists. [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], [1, 2, 2]
//
//
//
// Example 3:
//
//
// Input: N = 2, L = 3, K = 1
// Output: 2
// Explanation: There are 2 possible playlists. [1, 2, 1], [2, 1, 2]
//
//
//
//
//  
//
// Note:
//
//
// 	0 <= K < N <= L <= 100
//
//
//
//


class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        vector<vector<long>> dp(L + 1, vector<long>(N + 1, 0));
        dp[0][0] = 1;
        static int mod = 1e9 + 7;
        for (int l = 1; l <= L; l++) {
            for (int n = 1; n <= N; n++) {
                dp[l][n] += (dp[l - 1][n - 1] * (N - (n - 1))) % mod;
                if (n > K) {
                    dp[l][n] += (dp[l - 1][n] * (n - K)) % mod;
                }
                dp[l][n] %= mod;
            }
        }
        return dp[L][N];
    }
};
