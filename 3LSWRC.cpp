class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1)return s.size();

        unordered_map<char, int> mp;
        int mx = 0;
        int left = 0;
    
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];
            if (mp.find(ch) != mp.end() && mp[ch] >= left) 
            {
                left = mp[ch] + 1; 
            }

            mp[ch] = i;
            mx = max(mx, i - left + 1);
        }
        return mx;
    }
};
