class MovieRentingSystem
{
    inline long long key(int shop, int movie) const
    {
        return (static_cast<long long>(shop) << 32) | static_cast<unsigned int>(movie);
    }

    struct cmp
    {
        bool operator()(const vector<int>& a, const vector<int>& b) const
        {
            if(a[0] != b[0]) return a[0] < b[0]; // price
            if(a[1] != b[1]) return a[1] < b[1]; // shop
            return a[2] < b[2];                  // movie
        }
    };

    using mSet = multiset<vector<int>, cmp>;
    using It   = mSet::iterator;

    unordered_map<int, mSet> spsm; // shop -> {[price, shop, movie]}
    unordered_map<int, mSet> mpsm; // movie -> {[price, shop, movie]}
    mSet unrent;                   // {[price, shop, movie]}
    mSet rented;                   // {[price, shop, movie]}

    // (shop,movie) -> {itspsm, itmpsm, itunrent, itrented}
    unordered_map<long long, array<It,4>> sr;

    // (shop,movie) -> price
    unordered_map<long long, int> pr;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries)
    {
        for(const auto& e : entries) // e: [shop, movie, price]
        {
            int shop = e[0], movie = e[1], price = e[2];
            pr[key(shop, movie)] = price;

            auto its = spsm[shop].insert({price, shop, movie});
            auto itm = mpsm[movie].insert({price, shop, movie});
            auto itu = unrent.insert({price, shop, movie});
            sr[key(shop, movie)] = {its, itm, itu, rented.end()};
        }
    }

    vector<int> search(int movie)
    {
        vector<int> res = {};
        auto it = mpsm.find(movie);
        if(it == mpsm.end())
            return res;

        for(const auto& rec : it->second)
        {
            // rec: [price, shop, movie]
            res.push_back(rec[1]);
            if(res.size() == 5)
                break;
        }
        return res;
    }

    void rent(int shop, int movie)
    {
        auto k = key(shop, movie);
        auto &arr = sr[k]; // {itspsm, itmpsm, itunrent, itrented}

        spsm[shop].erase(arr[0]);
        mpsm[movie].erase(arr[1]);
        unrent.erase(arr[2]);

        int price = pr[k];
        auto itr = rented.insert({price, shop, movie});

        arr[0] = spsm[shop].end();
        arr[1] = mpsm[movie].end();
        arr[2] = unrent.end();
        arr[3] = itr;
    }

    void drop(int shop, int movie)
    {
        auto k = key(shop, movie);
        auto &arr = sr[k];

        if(arr[3] != rented.end())
            rented.erase(arr[3]);

        int price = pr[k];

        auto its = spsm[shop].insert({price, shop, movie});
        auto itm = mpsm[movie].insert({price, shop, movie});
        auto itu = unrent.insert({price, shop, movie});

        arr[0] = its;
        arr[1] = itm;
        arr[2] = itu;
        arr[3] = rented.end();
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> res;

        for(const auto& rec : rented)
        {
            // rec: [price, shop, movie]
            res.push_back({rec[1], rec[2]});
            if(res.size() == 5)
                break;
        }
        return res;
    }
};
