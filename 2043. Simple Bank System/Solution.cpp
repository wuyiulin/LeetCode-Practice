class Bank {
using LL = long long;
public:
vector<LL> ba;
    Bank(vector<long long>& balance) 
    {
        ba = balance;
    }
    
    bool transfer(int account1, int account2, long long money) 
    {
        if(account1 <= ba.size() && account2 <= ba.size() && ba[account1 - 1] >= money)
        {
            ba[account1 - 1] -= money;
            ba[account2 - 1] += money;
            
            return true;
        }

        return false;
    }
    
    bool deposit(int account, long long money) 
    {
        if(account <= ba.size())
        {
            ba[account - 1] += money;
            
            return true;
        }

        return false;
    }
    
    bool withdraw(int account, long long money) 
    {
        if(account <= ba.size() && ba[account - 1] >= money)
        {
            ba[account - 1] -= money;
            
            return true;
        }

        return false;
    }
};