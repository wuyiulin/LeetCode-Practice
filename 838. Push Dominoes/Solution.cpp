class Solution {
public:
    string pushDominoes(string dominoes) {
        
    }
};class Solution 
{
public:
    string pushDominoes(string domi) 
    {
        int n = domi.size();
        int pre = -1, next = -1;

        for(int i = 0; i < n; i++) 
        {
            if(domi[i] != '.') 
            {
                pre = next;        
                next = i;         

                if(pre == -1)      
                {
                    if(domi[next] == 'L') 
                    {
                        for(int j = 0; j < next; j++) 
                            domi[j] = 'L';
                    }
                }
                else 
                {
                    if(domi[pre] == 'R' && domi[next] == 'L') 
                    {
                        int l = pre + 1, r = next - 1;
                        while(l < r) 
                        {
                            domi[l++] = 'R';
                            domi[r--] = 'L';
                        }
                    } 
                    else if(domi[pre] == domi[next]) 
                    {
                        for(int j = pre + 1; j < next; j++) 
                            domi[j] = domi[pre];
                    }
                }
            }
        }

        if(next != -1 && domi[next] == 'R') 
        {
            for(int j = next + 1; j < n; j++) 
                domi[j] = 'R';
        }

        return domi;
    }
};