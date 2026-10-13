class Solution {
public:
    void solve(int i, int j, vector<vector<int>>& image, int color, int src) {
        int n = image.size();
        int m = image[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || image[i][j] != src ||
            image[i][j] == color) {
            return;
        }

        image[i][j] = color;

        solve(i - 1, j, image, color, src);
        solve(i + 1, j, image, color, src);
        solve(i, j + 1, image, color, src);
        solve(i, j - 1, image, color, src);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int src = image[sr][sc];

        solve(sr, sc, image, color, src);

        return image;
    }
};