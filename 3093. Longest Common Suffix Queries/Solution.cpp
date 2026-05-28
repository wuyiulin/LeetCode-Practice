const int MAX_NODES = 5 * 1e5;
int trie[MAX_NODES][26];
int best_idx[MAX_NODES];
int nodes_cnt;

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) 
    {
        nodes_cnt = 1;
        memset(trie[0], -1, sizeof(trie[0]));

        int n = wordsContainer.size(), m = wordsQuery.size();
        vector<int> len(n);
        int minIdx = 0;
        for(int i=0; i<n; i++)
        {
            len[i] = wordsContainer[i].size();
            if(len[i] < len[minIdx])
                minIdx = i;
        }
        best_idx[0] = minIdx;

        for(int i=0; i<n; i++)
        {
            int curr = 0;
            for(int j=len[i]-1; j>=0; j--)
            {
                int cIdx = wordsContainer[i][j] - 'a';
                if(trie[curr][cIdx] == -1)
                {
                    memset(trie[nodes_cnt], -1, sizeof(trie[nodes_cnt]));
                    best_idx[nodes_cnt] = i;
                    trie[curr][cIdx] = nodes_cnt++;
                }
                curr = trie[curr][cIdx];

                if(len[i]<len[best_idx[curr]] || (len[i] == len[best_idx[curr]] && i<best_idx[curr])) 
                    best_idx[curr] = i;
            }
        }

        vector<int> res(m, -1);
        for(int i=0; i<m; i++)
        {
            int curr = 0;
            for(int j=wordsQuery[i].size()-1; j>=0; j--)
            {
                int cIdx = wordsQuery[i][j] - 'a';
                if(trie[curr][cIdx] == -1)
                    break;
                curr = trie[curr][cIdx];
            }
            res[i] = best_idx[curr];
        }

        return res;
    }
};