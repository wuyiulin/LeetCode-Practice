class Solution {
using LL = long long;
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) 
    {
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        unordered_set<LL> s;
        for(const auto& o : obstacles)
        {
            LL key = ((long long)o[0] << 32) | (unsigned int)o[1];
            s.insert(key);
        }

        LL x = 0, y = 0, dIdx = 0, res = 0;
        for(const auto& com : commands)
        {
            if(com >= 0 && com <= 9)
            {
                int i = com;
                while(i)
                {
                    int newX = x + dir[dIdx][0];
                    int newY = y + dir[dIdx][1];
                    LL key = ((long long)newX << 32) | (unsigned int)newY;
                    if(s.count(key))
                        break;
                    else
                        x = newX;
                        y = newY;
                    res = max(res, x * x + y * y);
                    i--;
                }
            }
            else if(com == -2 || com == -1)
            {
                if(com == -2)
                    dIdx = (((dIdx - 1) + 4) % 4);
                else
                    dIdx = (((dIdx + 1) + 4) % 4);
            }
        }
    
        return res;
    }
};