class Solution {
public:
    bool squareIsWhite(string s) {
        if((s[1]-'0')%2)
        {
            if((s[0]-'a')%2)
                return 1;
            else return 0;
        }
        else
            {
            if((s[0]-'a')%2)
                return 0;
            else return 1;
        }
        return 1;
    }
};