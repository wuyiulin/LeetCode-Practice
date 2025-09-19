class Spreadsheet {
vector<vector<int>> sheet;
private:
    int to_int(string s)
    {
        if(s[0] >= 'A' && s[0] <= 'Z')
        {
            int col = s[0] - 'A';
            int row = stoi(s.substr(1));
            
            return sheet[col][row-1];
        }

        return stoi(s);
    }
public:
    Spreadsheet(int rows) 
    {
        sheet.resize(26, vector<int>(rows, 0));
    }
    
    void setCell(string cell, int value) 
    {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        sheet[col][row-1] = value;
    }
    
    void resetCell(string cell) 
    {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        sheet[col][row-1] = 0;
    }
    
    int getValue(string formula) 
    {
        int p = 0;
        formula = formula.substr(1);
        while(p<formula.size())
        {
            if(formula[p] == '+')
                break;
            p++;
        }
        string f = formula.substr(0, p);
        string r = formula.substr(p + 1);

        return to_int(f) + to_int(r);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */