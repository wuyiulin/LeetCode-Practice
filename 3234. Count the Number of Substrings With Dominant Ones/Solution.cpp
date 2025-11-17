class Solution {
    public:
        int numberOfSubstrings(string s) 
        {
            int n = s.size(), res = 0;
            for(int zeros = 0; zeros + zeros * zeros <= n; zeros++)
            {
                int last = -1;
                int cnt[2];
                memset(cnt, 0, sizeof(cnt));
                for(int l=0, r=0; r<n; r++)
                {
                    cnt[s[r] - '0']++; 
                    while(l < r)
                    {
                        if(s[l] == '0' && cnt[0] > zeros)
                        {
                            cnt[0]--;
                            last = l;
                        }
                        else if(s[l] == '1' && cnt[1] > zeros * zeros)
                        {
                            cnt[1]--;
                        }
                        else
                        {
                            break;
                        }
                        l++;
                    }
                    if(cnt[0] == zeros && cnt[1] >= zeros * zeros)
                        res += l - last;
                }
            }
    
            return res;
        }
    };