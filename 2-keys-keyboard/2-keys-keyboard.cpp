class Solution {
    int maxDivis(int X) {
        int val = X / 2;
        while(val > 1) {
            if(X % val == 0) return val;
            val--;
        }
        return 1;
    }
public:
   int minSteps(int n) {
        if(n == 1) return 0;
        int steps = 0;
        int length = 1;
         vector<int> dp;
        dp.emplace_back(n);
        while(true) {
            int div = maxDivis(n);
            if(div <= 1) break;
            dp.emplace_back(div);
            n = div;
        }
        
        for(int i = dp.size()-1; i >= 0; i--) {
            int next = dp[i];
            steps += next / length;
            length = next;
        }
        return steps;
    }
};

    
    