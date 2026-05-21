class TrieNode
{
    public:
        TrieNode* table[10];
        TrieNode()
        {
            fill(begin(table), end(table), nullptr);
        }
};
class Trie
{
    public:
        TrieNode* root;
        Trie()
        {
            root = new TrieNode();
        }
        void insert(const string& num)
        {
            TrieNode* node = root;
            for(char ch : num)
            {
                int idx = ch - '0';
                if(!node->table[idx])
                {
                    node->table[idx] = new TrieNode();
                }
                node = node->table[idx];
            }
        }

        int search(const string& num)
        {
            TrieNode* node = root;
            int count = 0;
            for(char ch : num)
            {
                int idx = ch - '0';
                if(!node->table[idx])
                    break;
                node = node->table[idx];
                count++;
            }

            return count;
        }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) 
    {
        Trie trie;
        for(const auto& a : arr1)
        {
            string sa = to_string(a);
            trie.insert(sa);
        }
        int res = 0;
        for(const auto& a : arr2)
        {
            string sa = to_string(a);
            res = max(res, trie.search(sa));
        }

        return res;
    }
};