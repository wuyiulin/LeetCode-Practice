class Solution {
private:
    bool DFS(int& n, int& k, int& step, string& curr)
    {
        if(curr.size() == n)
        {
            step++;
            if(step == k)
                return true;
            return false;
        }
            
        for(int i=0; i<3; i++)
        {
            char c = 'a' + i;
            if(!curr.empty() && curr.back() == c)
                continue;
            curr += c;
            if(DFS(n, k, step, curr))
                return true;
            curr.pop_back();
        }

        return false;
    }
public:
    string getHappyString(int n, int k) 
    {
        string curr = "";
        int step = 0;
        DFS(n, k, step, curr);

        return curr;
    }
}; 