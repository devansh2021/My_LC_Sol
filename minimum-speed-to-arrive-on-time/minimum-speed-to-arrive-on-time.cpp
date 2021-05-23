
class Solution
{
public:
    bool check(vector<int> &v, int sp, double time)
    {
        double h = 0;
        int n = v.size();
        for (int i = 0; i < v.size() - 1; i++)
        {
            double cur = (v[i] * 1.0) / sp;
            if (cur == (int)cur)
                h += cur;
            else
                h += (int)cur + 1;
        }
        h += (v[n - 1] * 1.0 / sp);
        if (h <= time)
            return 1;

        return 0;
    }
    int minSpeedOnTime(vector<int> &v, double h)
    {
        int n = v.size();
        int hi;
        if (h == (int)h * 1.0)
            hi = h;
        else
            hi = h + 1;
        if (hi < n)
            return -1;
        else if (hi == n)
        {
            if (h == (int)h * 1.0)
                return *max_element(begin(v), end(v));
            else
            {

                double time = h - (int)h * 1.0;
                double speed = v[n - 1] / time;
                if (v[n - 1] == 1e5)
                    return speed;
                if ((long)ceil(speed) != (long)floor(speed))
                {
                    speed = (int)speed + 1;
                }
                return max((int)speed, *max_element(begin(v), end(v)));
            }
        }
        else
        {
            int l = 1, r = *max_element(begin(v), end(v)), ans;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;

                if (check(v, mid, h))
                {
                    r = mid - 1;
                    ans = mid;
                }
                else
                    l = mid + 1;
            }
            return ans;
        }
    }
};