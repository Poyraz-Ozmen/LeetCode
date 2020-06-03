// #include<bits/stdc++.h> 
//function to convert string into lowercase

class Solution {
public:
   
    struct cell{
        char c;
        int index;
    };
   
    int char_to_index(char c){
        // 'a' is 97, whole string will be converted into lowercase str.
        return int(c) - 97;
    }
    
    
    string toLower(string str){
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
    
    
    vector<string> RecursiveSub ( string s, vector<cell> & hashTable, vector<string> & string_vec)
    {   
        
        for(int i = 0; i  <  s.size(); i++)
        {
            int index = char_to_index(s[i]);
            string temp = "";
            if(hashTable[index]==NULL)
            {
                temp = temp + s[i];
                hashTable[index] = s[i];
            }
            
            else{
                
                // there is a collision
                //  assume string is "123454........N"
                // push_back 12345 to string_vector
                // go on with 54........N,   (cut the string)
                
                
                string sub_str = s.substr(i, s.size()- i);
                
                string_vec.push_back(  s.substr(0,i-1)  );  //  123454........N
                
                // now clear 12345 from hashTable    
                for(int k = 0; k<i;  k++){
                    index = char_to_index(s[k]);
                    hashTable[index] = NULL;
                }
                
                
                return RecursiveSub(sub_str,hashTable,string_vec);
            }
        }
        
        // if there left a string without collision we should add it to string_vec
        if(temp.size>0) {   string_vec.push_back(temp);     }
        
        return string_vec;
        
    }
    
   
    int lengthOfLongestSubstring(string s)
    {
        vector<string> string_vec;
        vector<char> hashTable(30);
        
        s = toLower(s); // converted to lowercase string
      
        string_vec =  RecursiveSub(s,hashTable,string_vec);
    
        
        
        return 0;
    }
};
