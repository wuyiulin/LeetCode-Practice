class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) 
    {
        int n = startTime.size(), res = 0;
        vector<int> gap(n + 1, 0);
        for(int i=0; i<n; i++)
        {
            if(!i)
            {
                gap[i] = startTime[i];
                continue;
            }
            gap[i] = startTime[i] - endTime[i - 1];
            if(i == n - 1)
                gap[n] = eventTime - endTime[i];
        }
        priority_queue<int, vector<int>> gapQ;
        for(const auto& g : gap)
            gapQ.push(g);

        for(int i=0; i<n; i++)
        {
            int status[2];
            memset(status, 0, sizeof(status));
            vector<int> gapList = {gap[i], gap[i + 1]};
            sort(gapList.begin(), gapList.end(), greater<int>());
            for(const auto& gl : gapList)
            {
                if(gl == gapQ.top())
                {
                    gapQ.pop();
                    if(gl == gap[i])
                        status[0] = 1;
                    else
                        status[1] = 1; 
                }
            }
            int e = endTime[i] - startTime[i];
            if(e <= gapQ.top())
                res = max(res, gap[i] + gap[i + 1] + e);
            else
                res = max(res, gap[i] + gap[i + 1]);
            for(int k=0; k<2; k++)
            {
                if(status[k])
                    gapQ.push(gap[i+k]);
            }
        }

        return res;
    }
};