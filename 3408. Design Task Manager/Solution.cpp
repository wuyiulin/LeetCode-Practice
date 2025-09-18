class TaskManager {
struct cmp
{
    bool operator()(const vector<int>& a, const vector<int>& b) const
    {
        if(a[0] != b[0]) return a[0] > b[0];
        if(a[1] != b[1]) return a[1] > b[1];
        return a[2] > b[2];
    }
};
using It = multiset<vector<int>, cmp>::iterator;
unordered_map<int, It> tit;
multiset<vector<int>, cmp> table;
public:
    TaskManager(vector<vector<int>>& tasks) 
    {
        for(const auto& task : tasks)
        {
            It it = table.insert({task[2], task[1], task[0]}); 
            tit[task[1]] = it;
        }
    }
    
    void add(int userId, int taskId, int priority) 
    {
        It it = table.insert({priority, taskId, userId});
        tit[taskId] = it;
    }
    
    void edit(int taskId, int newPriority) 
    {
        It it = tit[taskId];
        int userId = (*it)[2];
        table.erase(it);
        tit[taskId] = table.insert({newPriority, taskId, userId});
    }
    
    void rmv(int taskId) 
    {
        It it = tit[taskId];
        table.erase(it);
        tit.erase(taskId);
    }
    
    int execTop() 
    {
        if(table.empty())
            return -1;
        auto it = table.begin();
        int taskId = (*it)[1];
        int userId = (*it)[2];
        table.erase(it);
        tit.erase(taskId);
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */