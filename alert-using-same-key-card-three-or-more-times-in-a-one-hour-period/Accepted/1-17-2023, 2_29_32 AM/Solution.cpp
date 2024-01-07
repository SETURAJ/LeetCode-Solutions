// https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period

class Solution {
public:

    int time(string s)
    {
        int h=stoi(s.substr(0,2));
        int m=stoi(s.substr(3));
        return 60*h + m;
    }

    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        vector<string>res;
        unordered_map<string,vector<int>>logs;
        int n=keyName.size();
        for(int i=0;i<n;i++)
            logs[keyName[i]].push_back(time(keyTime[i]));
        for(auto [worker,time] : logs)
        {
            sort(time.begin(),time.end());
            int sz=time.size();
            if(sz>=3)
            {
                for(int i=2;i<sz;i++)
                {
                    if(time[i]-time[i-2]<=60)
                    {
                        res.push_back(worker);
                        break;
                    }
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};