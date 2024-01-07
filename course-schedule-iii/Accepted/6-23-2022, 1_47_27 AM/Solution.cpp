// https://leetcode.com/problems/course-schedule-iii

class Solution {
public:
    
    static bool compare(const vector<int>&a,const vector<int>&b)
    {
        return a[1]<b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),compare);
        priority_queue<int>pq;
        int total=0;
        for(auto &c:courses)
        {
            int dur=c[0],end=c[1];
            if(dur+total <=end)
            {
                total+=dur;
                pq.push(dur);
            }
            else if(pq.size() && dur<pq.top())
            {
                total+=dur-pq.top();
                pq.pop();
                pq.push(dur);
            }
        }
        return pq.size();
    }
};