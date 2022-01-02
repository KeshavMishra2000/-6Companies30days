class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        if(strs.size()==0){
            return  result;
        }
        int n   =   strs.size();
        unordered_map<string,vector<string>>map;
        for(string s    :   strs){
            string  key =   s;
            sort(key.begin(),key.end());
            map[key].push_back(s);
        }
        
        for(auto  p  :   map){
            result.push_back(p.second);
        }
            return  result;
        
    }
};
Method 2
 class Solution {
public:
    
    
    
      string helper(string s)
    {
        int arr[26] = {0};
        for(int i = 0 ; i<s.length() ; i++)
        {
            arr[s[i]-'a']++;
        }
        s = "";
        for(int i = 0 ; i<26 ; i++)
        {
            int count = arr[i];
            while(count-- != 0)
            {
                string temp = "";
                temp = 'a' + i;
                s += temp;
            }
        }
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
           vector<vector<string>> res;
        if(strs.size()==0)
            return res ;
        
        
        unordered_map<string,vector<string>>dict;
        for(string s : strs){
            dict[helper(s)].push_back(s);
        }
        auto O=dict.begin();
        while(O!=dict.end()){
            res.push_back(O->second);
            O++;
        }
        return  res;
        
        
        
    }
};