#include <iostream>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int length = 0;
            string subString = "";
    
            for(char c : s){
                if(subString.find(c)==std::string::npos){ subString += c; }
                else{ subString = subString.substr(subString.find(c)+1) + c; }
    
                length = max(length, (int)subString.length());
            }
    
            return length;
        }
    };