class Solution {
    double R, X, Y;
public:
    Solution(double radius, double x_center, double y_center) : R(radius), X(x_center), Y(y_center) {
    }
    double random(){
        return rand() /(double) RAND_MAX;
    }
    vector<double> randPoint() {
        vector<double> ans(2);
        double len = sqrt(random()) * R, deg = 2 * M_PI * random();
        ans[0] = X + len * cos(deg);
        ans[1] = Y + len * sin(deg);
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */