class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
         int t_ik0 = 0, t_ik1 = INT_MIN;
            for (int price : prices)
            {
                int t_ik0_old = t_ik0;
                t_ik0 = max(t_ik0, t_ik1 + price);
                t_ik1 = max(t_ik1, t_ik0_old - price-fee);
            }

            return t_ik0;
    }
};