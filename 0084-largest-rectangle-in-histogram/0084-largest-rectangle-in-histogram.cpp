class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        int l = ht.size();
        vector<int> right(l, 0), left(l, 0);
        stack<int> s;
        int ans = 0;

        for (int i = l - 1; i >= 0; i--) {
            while (s.size() > 0 && ht[s.top()] >= ht[i]) {
                s.pop();
            }
            if (s.empty())
                right[i] = l;
            else
                right[i] = s.top();

            s.push(i);
        }

        while (!s.empty()) {
            s.pop();
        }

        for (int i = 0; i < l; i++) {
            while (s.size() > 0 && ht[s.top()] >= ht[i]) {
                s.pop();
            }
            if (s.empty())
                left[i] = -1;
            else
                left[i] = s.top();

            s.push(i);
        }

        for (int i = 0; i < ht.size(); i++) {
            int cr = ht[i] * (right[i] - left[i] - 1);
            ans = max(ans, cr);
        }

        return ans;
    }
};