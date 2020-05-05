class Solution {
public:
    
    int char_to_ascii(char c){
        
        int ascii = c;
        //cout<<"ascii char c="<<c<<",int ascii= "<<ascii<<endl;
        return ascii;
        
    }

    
/*
decimal - char
50          2

97          a

100         d
*/  
    struct tripples{
        int a;
        char c1 = 97 + ((a-50)*3); //ascii decimal of 2 is 50
        char c2 = 98 + ((a-50)*3);
        char c3 = 99 + ((a-50)*3);
        
        tripples(int a) :
        a(a)
        
        {}
    };
    
    // vector<string> genereateStrings(vector<string> s, string str, tripples t, int index){
        
    //     vector<string> v;

    //     string temp = s;
    //     temp[index] = t.c1; 
    //     string s1 = temp;
        
    //     temp[index] = t.c2;
    //     string s2 = temp;

    //     temp[index] = t.c3; 
    //     string s3 = temp;



    //     v.push_back(s1);
    //     v.push_back(s2);
    //     v.push_back(s3);


    //     return v; 
    // }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> vec;
        vector<tripples> trippleVec;
        
        for(int i=0; i<digits.size(); i++){
            
            struct tripples s(char_to_ascii(digits[i]));
            trippleVec.push_back(s);
        }
        
        //string s="";
        for (int k =0;k<trippleVec.size();k++){
            // could not find any solution
        }
        
        
        return vec;
    }
};