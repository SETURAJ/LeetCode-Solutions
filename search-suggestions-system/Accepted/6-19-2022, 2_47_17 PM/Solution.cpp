// https://leetcode.com/problems/search-suggestions-system

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        auto it=products.begin();
        vector<vector<string>>res;
        string curr="";
        for(auto c:searchWord)
        {
            curr+=c;
            vector<string>suggested;
            it=lower_bound(it,products.end(),curr);
            for(int i=0;i<3 && it+i!=products.end();i++)
            {
                string &s=*(it+i);
                if(s.find(curr))
                    break;
                suggested.push_back(s);
            }
            res.push_back(suggested);   
        }
        return res;
    }
};