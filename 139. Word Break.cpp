#include "stdio.h"
#include <iostream>
#include <stdbool.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) 
{
    bool sol;
    int size = s.size();
    unordered_set<string> HM(wordDict.begin(), wordDict.end());
    vector<bool> dp(size + 1, false);
    dp[0] = true;

    for (int i = 1; i <= size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(dp[j] && HM.find(s.substr(j, i - j)) != HM.end())
            {
                dp[i] = true;
                break;
            }
            
        }
    }
    sol = dp[size];
    return sol;
}

int main()
{
    string s = "leetcode";
    vector<string> wordDict = { "leet", "code" };
    // cout << prices.size();
    cout<< wordBreak(s,wordDict);
    system("pause");
    getchar();    
    return 0;
}