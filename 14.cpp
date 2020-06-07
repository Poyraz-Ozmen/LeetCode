#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    

    
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size()==0) {return "";}
        else if (strs.size()==1){return strs[0];}
        
        
        string longest_cp = strs[0];
        int j;
        int k;
        int t = 0;
        int size;
        
        for(int i = 0; i<strs.size(); i++)
        {   
            if(strs[i].size()==0){return "";}
            
            if(strs[i].size()==1){
                if(strs[i].at(0)==longest_cp[0])
                {
                    longest_cp = longest_cp[0];
                }
                else{
                    return "";
                }
            }
           
            
            if(strs[i].size() < longest_cp.size())
            { 
                size = strs[i].size();
                if(longest_cp.substr (0,size) == strs[i])
                {
                    longest_cp = strs[i];
                }
            }
            
            else{size = longest_cp.size();}
             
            
            for(j = 0; j<size; j++ )
            {
        
                if(longest_cp.size() == 0){return longest_cp;}
                
                else
                {    
                    if(longest_cp[j] != strs[i].at(j))
                    {
                        if(j==0){
                            return "";
                        }
                        
                        else if(j==1){
                            longest_cp = longest_cp[0];
                            j = size; // break inner loop
                        }                        
                        else{
                            cout<<"There is a bug  in here for test  ["apcb","apb"]";
                            cout<<longest_cp<<endl;
                            longest_cp.pop_back();
                            cout<<longest_cp<<endl;
                            cout<<endl<<endl;
                        }
                    }
                }
                
                
            }
            if(longest_cp.size()>strs[i].size()){
                longest_cp.pop_back();
            }
        }
        
        
        
        return longest_cp;
    }
};
// nice test case ["flower","flow","flight","f",""]

int main(){
    Solution s;
    vector<string> v;
    v.push_back("flower");
    v.push_back("flow");
    v.push_back("flight");
    v.push_back("f");

    cout<<s.longestCommonPrefix(v)<<endl;
    return 0;
}
