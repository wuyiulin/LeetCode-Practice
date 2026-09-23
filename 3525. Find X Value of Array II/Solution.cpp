class Solution {
    int k, n;
    struct Node {
        int prod;
        int cnt[5];
    };
    vector<Node> tr;

    Node makeLeaf(int v) {
        Node nd{};
        nd.prod = v % k;
        nd.cnt[nd.prod] = 1;
        return nd;
    }
    
    Node merge(const Node& L, const Node& R) {
        Node res{};
        res.prod = L.prod * R.prod % k;
        for (int t = 0; t < k; ++t) 
        {
            res.cnt[t] += L.cnt[t];
            res.cnt[L.prod * t % k] += R.cnt[t];
        }
        return res;
    }

    void build(int id, int l, int r, vector<int>& nums) {
        if (l == r)
        { 
            tr[id] = makeLeaf(nums[l]); 
            return; 
        }
        int m = (l + r) / 2;
        build(id*2, l, m, nums);
        build(id*2+1, m+1, r, nums);
        tr[id] = merge(tr[id*2], tr[id*2+1]);
    }

    void update(int id, int l, int r, int pos, int v) 
    {
        if (l == r) 
        {
            tr[id] = makeLeaf(v); 
            return; 
        }
        int m = (l + r) / 2;
        if (pos <= m) 
            update(id*2, l, m, pos, v);
        else 
            update(id*2+1, m+1, r, pos, v);
        tr[id] = merge(tr[id*2], tr[id*2+1]);
    }

    Node query(int id, int l, int r, int ql, int qr) 
    {
        if (ql <= l && r <= qr) 
            return tr[id];
        int m = (l + r) / 2;
        if (qr <= m) 
            return query(id*2, l, m, ql, qr);
        if (ql > m)  
            return query(id*2+1, m+1, r, ql, qr);
        return merge(query(id*2, l, m, ql, qr), query(id*2+1, m+1, r, ql, qr));
    }
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;
        n = nums.size();
        tr.assign(4 * n, Node{});
        build(1, 0, n - 1, nums);
        vector<int> res;
        res.reserve(queries.size());
        for (auto& q : queries) 
        {
            int idx = q[0], val = q[1], st = q[2], x = q[3];
            update(1, 0, n - 1, idx, val);
            res.push_back(query(1, 0, n - 1, st, n - 1).cnt[x]);
        }
        return res;
    }
};