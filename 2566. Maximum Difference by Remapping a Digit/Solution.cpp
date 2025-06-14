class Solution {
public:
    int minMaxDifference(int num) 
    {
        string str = to_string(num);
        string maxStr = "", minStr = "";
        int idx = 0, ss = str.size();
        char tar = 'c';
        while(idx < ss)
        {
            if(str[idx] != '9')
            {
                tar = str[idx];
                break;
            }
            idx++;
        }
        if(tar == 'c')
            return num;

        for(const auto& c : str)
        {
            char tmp_max = c, tmp_min = c;
            if(c == tar)
                tmp_max = '9';
            if(c == str[0])
                tmp_min = '0';
            maxStr += tmp_max;
            minStr += tmp_min;
        }

        int maxVal = stoi(maxStr), minVal = stoi(minStr);

        return maxVal - minVal;
    }
};