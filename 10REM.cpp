class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();

        vector<vector<bool>> dp(s_len + 1, vector<bool>(p_len + 1, false));

        dp[0][0] = true;

        for (int j = 1; j <= p_len; ++j) 
        {
            if (p[j - 1] == '*') 
            {
                if (j > 1) {
                    dp[0][j] = dp[0][j - 2];
                }
            }
        }
        for (int i = 1; i <= s_len; ++i) 
        {
            for (int j = 1; j <= p_len; ++j) 
            {
                char s_char = s[i - 1];
                char p_char = p[j - 1];
                if (p_char == '.' || p_char == s_char) 
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p_char == '*') 
                {
                    if (j > 1) 
                    {
                        char prev_p_char = p[j - 2];
                        bool zero_matches = dp[i][j - 2];
                        bool one_or_more_matches = false;
                        if (prev_p_char == '.' || prev_p_char == s_char) 
                        {
                            one_or_more_matches = dp[i - 1][j];
                        }
                        dp[i][j] = zero_matches || one_or_more_matches;
                    }
                }
                else 
                {
                    dp[i][j] = false;
                }
            }
        }
        return dp[s_len][p_len];
    }
};
