#include<bits/stdc++.h> //function to convert string into lowercase                           
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
   
    
    
    string toLower(string str){
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
    
    
    
   
    int lengthOfLongestSubstring(string s)
    {
        if(s.length()<=1){return s.length();}
        
        
	    // a char can hold up to 256 values, we map each char value to a "seen" flag
		// the state of a substring is represented by seenChars and count
        vector<bool> hashArray(256);
        int count = 0, maxCount = 0, start = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(hashArray[s[i]]) {
			
			   // advance start to the left duplicate character
                int j = start;
                for(; s[j] != s[i]; j++) {
				    // remove intermediate characters from state
                    hashArray[s[j]] = false;
                    count--;
                }
				
				// j points to the duplicate character, so advance once
                start = j + 1;
            } else {
                count++;
                if(count > maxCount) {
                    maxCount = count;
                }
            }
            
            hashArray[s[i]] = true;
        }
        
        return maxCount;
    }
		
        
    
};



int main()
{
        
	Solution s;
	
	string temp = "abcabcbb";
	temp = s.toLower(temp);
	return s.lengthOfLongestSubstring(temp);
		
		
		
    
}
