#include <iostream>
#include <map>
using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            map<int, string> zigzagMap;
            string result = "";
    
            if(numRows == 1) return s;
    
            for(int i = 1; i <= numRows; ++i){
                cout << "i: " << i << endl;
                if(s == "") break;
                else{
                    zigzagMap[i] = zigzagMap[i] + s[0];
                    s = s.substr(1);
                    cout << "substr: " << s << endl;
    
                    if(i == numRows){
                        --i;
    
                        for(i; i >= 1; --i){
                            cout << "i: " << i << endl;
                            if(s == "") break;
                            zigzagMap[i] = zigzagMap[i] + s[0];
                            s = s.substr(1); 
                        }
    
                        ++i;
                    }
                }
            }
    
            for(auto result_sub: zigzagMap){
                result += result_sub.second;
            }
    
            return result;
        }
    };