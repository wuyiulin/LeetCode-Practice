class Solution {
public:
    string predictPartyVictory(string senate) 
    {
        queue<char> q;
        int R = 0, D = 0, cnt = 0;
        for(const auto& c : senate)
        {
            q.push(c);
            if(c == 'R') R++;
            else D++;
        } 
        while(R && D)
        {
            char curr = q.front(); q.pop();
            if(!cnt)
            {
                q.push(curr);
                if(curr == 'R') cnt++;
                else cnt--;
                continue;
            } 
            if(cnt > 0 && curr == 'R' || cnt < 0 && curr == 'D')
            {
                if(curr == 'R') cnt++;
                else cnt--;
                q.push(curr);
            }
            else if(cnt < 0 && curr == 'R' || cnt > 0 && curr == 'D')
            {
                if(curr == 'R')
                {
                    cnt++;
                    R--;
                } 
                else
                {
                    cnt--;
                    D--;
                }
            }
        }
        return q.front()=='D' ? "Dire" : "Radiant";
    }
};

