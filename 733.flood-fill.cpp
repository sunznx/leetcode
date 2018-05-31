class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int raw = image.size();
        int col = image[0].size();
        vector<vector<bool>> v(raw, vector<bool>(col, false));

        dfs(image, v, sr, sc, image[sr][sc], newColor);

        return image;
    }

    void dfs(vector<vector<int>>& image, vector<vector<bool>>& v, int x, int y, int oldColor, int newColor) {
        int raw = image.size();
        int col = image[0].size();

        if (x < 0 || y < 0 || x >= raw || y >= col || v[x][y] == true || image[x][y] != oldColor) {
            return;
        }

        v[x][y] = true;

        image[x][y] = newColor;
        dfs(image, v, x, y+1, oldColor, newColor);
        dfs(image, v, x, y-1, oldColor, newColor);
        dfs(image, v, x+1, y, oldColor, newColor);
        dfs(image, v, x-1, y, oldColor, newColor);
    }
};
