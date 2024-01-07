// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color

class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice=0;
        int bob=0;
        int l= colors.length();
        if(l<=2)
            return false;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<l;i++)
        {
            while(colors[i]=='A')
            {
                cnt1++;
                //cout<<i<<endl;
                i++;
            }
            //cout<<cnt1<<endl;
            if(cnt1>2)
            {
                alice+= (cnt1-2);
                cnt1=0;
            
            }
            else
            {
                cnt1=0;
            }
            while(colors[i]=='B')
            {
                cnt2++;
                i++;
            }
            if(cnt2>2)
            {
                bob+= (cnt2-2);
                cnt2=0;
                
            }
            else
            {
                cnt2=0;
            }
            i--;
        }
        //cout<<alice<<endl;
        //cout<<bob<<endl;
        return alice>bob;
    }
};