class Solution {
public:
    int bestClosingTime(string customers) 
    {
        int Ycnt = 0, Ncnt = 0, res = 0, n = customers.size(), curr = INT_MAX;
        for(const auto& c : customers)
        {
            if(c == 'Y')
                Ycnt++;
        }
        
        for(int i=0; i<n+1; i++)
        {
            int p = Ncnt + Ycnt;
            if(p < curr)
            {
                res = i;
                curr = p;
            }
            if(i == n)
                break;
                
            if(customers[i] == 'N')
            {
                Ncnt++;
            }
            else
            {
                Ycnt--;
            }                
        }

        return res;
    }
};