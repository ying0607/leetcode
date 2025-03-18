#include <iostream>
using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            if (s.length() <= 1) return s;
    
            int start = 0;
            int end = 0;
    
            for (int i = 0; i < s.length(); ++i){
                int odd_size = expand(s, i, i);
                int even_size = expand(s, i, i+1);
                int max_len = max(odd_size, even_size);
                
                if (max_len > end - start + 1){
                    start = i - (max_len - 1) / 2;
                    end = i + max_len / 2;
                }
            }
    
            return s.substr(start, end - start + 1);
        }
    
    private:
        int expand(string s, int l, int r){
            while (l >= 0 && r <= s.length() && s[l] == s[r]){
                --l;
                ++r;
            }
    
            return r - l - 1;
        }
    };