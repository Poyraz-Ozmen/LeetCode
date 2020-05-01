#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution() {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string longest_cp = "";
        int shortest_str;
        
        if(strs[0].size()<=strs[1].size()){
            shortest_str = strs[0].size(); 
        }
        else{shortest_str =strs[1].size();}
        
        for(int i = 0; i<shortest_str; i++ ){
            
            if(strs[0].at(i)==strs[1].at(i)){
                longest_cp += strs[0].at(i);
            }
            else{break;}
        }
        
        if(strs.size()>=2){
            for(int k=2; k<strs.size();k++){
                for(int j=0; j<longest_cp.size() and j<strs[k].size(); j++){

                    if(strs[k].at(j) != longest_cp.at(j)){
                        longest_cp =  longest_cp.substr(0,j);
                        break;
                    }
                }
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