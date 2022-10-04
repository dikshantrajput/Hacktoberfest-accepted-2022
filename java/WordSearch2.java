public class Solution {
	public static int wordSearch(String grid[], int n, int m, String word) {
        int ans = 0;
        int len = word.length();
        
        int[] dx = {0, 1, 1, 1, 0, -1, -1, -1};
        int[] dy = {1, 1, 0, -1, -1, -1, 0, 1};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i].charAt(j) == word.charAt(0)) {
                    for (int k = 0; k < 8; k++) {
                        int x = i, y = j, c = 0;
                        while (x >= 0 && x < n &&
                               y >= 0 && y < m &&
                               c < len &&
                               word.charAt(c) == grid[x].charAt(y)) {
                            c++;
                            x += dx[k];
                            y += dy[k];
                        }
                        ans += (c == len) ? 1 : 0;
                    }
                }
            }
        }
        
        return ans;
	}
}
