// https://leetcode.com/problems/robot-return-to-origin

class Solution {
public:
    bool judgeCircle(string moves) {
        int lr=0;
        int ud=0;
        for(int i=0;i<moves.length();i++)
        {
            if(moves[i]=='U')
                ud++;
            if(moves[i]=='D')
                ud--;
            if(moves[i]=='R')
                lr++;
            if(moves[i]=='L')
                lr--;
        }
        if(ud==0 && lr==0)
            return true;
        return false;
    }
};