class Solution {
public:    
    int get_next(int n){
        string s = to_string(n);
        int sum = 0;
        for (auto c: s)
            sum += (c - '0') * (c - '0');
        return sum;
    }
    bool isHappy(int n) {
        set<int> appeared;
        while(n != 1){
            appeared.insert(n);
            n = get_next(n);
            if (appeared.find(n) != appeared.end())
                return false;
        }
        return true;
    }
};