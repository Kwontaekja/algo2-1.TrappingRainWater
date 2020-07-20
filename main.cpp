#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct elem
{
    int L, R, H;
};

class Solution
{
public:
    int trap(vector<int> &arr)
    {
        stack<elem> s;
        int sum = 0;
        for (int i = 0; i < arr.size();)
        {
            elem tmp = {i, i + 1, arr[i]};

            if (s.empty() || s.top().H > tmp.H)
            {
                s.push(tmp);
                i++;
            }
            else if (s.top().H == tmp.H)
            {
                s.top().R = tmp.R;
                i++;
            }
            else
            {
                // s.top().H < tmp.H
                elem hole = s.top();
                s.pop();
                // stack의 top을 pop했을 때 empty가 되는 것은 빗물을 담을 수 있는 left 막대가 없는 것을 의미하므로 pass한다
                // -> hole보다 높은 좌측의 막대가 연달아 존재하지 않음
                if (s.empty())
                    continue;
                sum += (tmp.L - s.top().R) * (min(tmp.H, s.top().H) - hole.H);
            }
        }
        return sum;
    }
};

int main()
{
    vector<int> ex = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution sol;
    int ans = sol.trap(ex);

    cout << ans << "\n";
    return ans;
}