// https://leetcode.com/problems/number-of-laser-beams-in-a-bank

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0;
        vector<int>tmp;
        for(auto s:bank)
        {
            int cnt=0;
            if(s.find("1") != string::npos)
            {
                //cout<<s<<endl;
                for(int i=0;i<s.length();i++)
                {
                    if(s[i]=='1')
                        cnt++;
                }
                //cout<<cnt<<endl;
                tmp.push_back(cnt);
            }
            
        }
        if(tmp.size()<=1)
            return 0;

        for(int i=1;i<tmp.size();i++)
            res+= (tmp[i]*tmp[i-1]);
        return res;
    }
};