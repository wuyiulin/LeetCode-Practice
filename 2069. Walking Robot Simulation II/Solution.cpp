class Robot {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<string> DS = {"North", "East", "South", "West"};
    int r = 0, c = 0, h = 0, w = 0, p = 0, dIdx = 1;
    Robot(int width, int height) 
    {
        h = height, w = width;
        p = 2 * (h + w - 2); 
    }
    
    void step(int num) 
    {
        num %= p;
        if(!num)
            num = p;
        while(num)
        {
            int newR = r + dirs[dIdx][1], newC = c + dirs[dIdx][0];
            if(newR >= h || newR < 0 || newC >= w || newC < 0)
            {
                dIdx = ((dIdx - 1) + 4) % 4;
                continue;
            }
            r = newR, c = newC;
            num--;
        }

        return;
    }
    
    vector<int> getPos()
    {
        return {c, r};
    }
    
    string getDir() 
    {
        return DS[dIdx];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */