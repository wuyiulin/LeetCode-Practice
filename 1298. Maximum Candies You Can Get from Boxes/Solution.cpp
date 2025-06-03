class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) 
    {
        unordered_set<int> keySet;
        queue<int> boxes;
        for(int i=0; i<initialBoxes.size(); i++)
            boxes.push(initialBoxes[i]);

        int res = -1, cnt = 0;
        while(res != cnt)
        {
            res = cnt;
            queue<int> next;
            while(!boxes.empty())
            {
                int boxIdx = boxes.front(); boxes.pop();
                if(status[boxIdx])
                {
                    for(const auto& key : keys[boxIdx])
                        status[key] = 1;
                    for(const auto& cBox : containedBoxes[boxIdx])
                        next.push(cBox);
                        cnt += candies[boxIdx];
                }
                else
                    next.push(boxIdx);
            }
            boxes = next;
        }

        
        return res == -1 ? 0 : res;
    }
};