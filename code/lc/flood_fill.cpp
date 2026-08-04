class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial = image[sr][sc];

        if (initial != color) dfs(sr, sc, image, initial, color);
        return image;
    }

    void dfs(int sr, int sc, vector<vector<int>>& image, int original, int color) {
        int n = image.size();
        int m = image[0].size();
        if (sr < 0 || sr >= n || sc < 0 || sc >= m || image[sr][sc] != original) return;
        
        image[sr][sc] = color; 
        
        dfs(sr+1, sc, image, original, color);
        dfs(sr-1, sc, image, original, color);
        dfs(sr, sc+1, image, original, color);
        dfs(sr, sc-1, image, original, color);
    }
};