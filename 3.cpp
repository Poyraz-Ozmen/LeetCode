int char_to_ascii(char c) {
   int i = c;
   return i;
   //cout<<"The ASCII value of "<<c<<" is "<<i<<endl;
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    queue <char> q; 
    //string s = "bcdkak112345azxvnmpoiu98765ga";
    string subStr = "";
    vector<string> subStr_list;
    transform(s.begin(), s.end(), s.begin(), ::tolower); 
    vector<char> charTable;
    
    for(int i=0; i<300; i++){
        charTable.push_back('A'); // since  string has converted to lowercase letters, we can fill up initial char table with char 'A'
    }
    
    
    for (int i = 0; i < s.size(); i++)
    {
        if(charTable[char_to_ascii(s[i])]==s[i])
        { // duplicate char
            q.push(s[i]);
            int counter=0;
            int sizeCounter =0;
            int queueSize = q.size();
            queue <char> temp; 

            while (counter != 2 and sizeCounter<queueSize) 
            {   
                if(q.front()==s[i]) {counter++;}

                if(counter>=1 )  
                {   
                    if(counter!=2){subStr.push_back(q.front());}
                    
                    if(q.front()!=s[i] or counter==2){
                        temp.push(q.front());
                    }
                    q.pop();
                }
                
                //if(q.front()==s[i] and counter==1) {q.pop();}
                
                if(counter<1){
                    subStr.push_back(q.front());
                    charTable[char_to_ascii(q.front())] = 'A';
                    q.pop();

                    } // assume string is "12345abcdef5" then 12345 should be removed for the next round. counter increases when it sees duplicate char which is '5'
                sizeCounter++;
            }
            //counter = 0;
            subStr_list.push_back(subStr);
            subStr="";           
            q = temp;
        }
        else{
            q.push(s[i]);
            charTable[char_to_ascii(s[i])] = s[i];
        }
    }

    //subStr_list.push_back(subStr);
    int max = subStr_list[0].size();
    for(int j=0; j<subStr_list.size();j++){
        if(subStr_list[j].size()>max){max = subStr_list[j].size();}
    }
    
    return max;
}     
    
};
