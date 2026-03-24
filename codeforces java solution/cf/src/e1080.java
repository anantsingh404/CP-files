import java.io.*;
import java.util.*;

public class e1080 {

    // ===== CONSTANTS =====
    static final int inf = (int)1e9;
    static final long linf = (long)1e18;
    static final long mod = 1000000007;

    // ===== DIRECTIONS =====
    // 4-direction (up, right, down, left)
    static int[] dx4 = {-1, 0, 1, 0};
    static int[] dy4 = {0, 1, 0, -1};

    // 8-direction (including diagonals)
    static int[] dx8 = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int[] dy8 = {-1, 0, 1, -1, 1, -1, 0, 1};

    static void dfs1(int u, int[][] child, long[] move) {
        if (u == 0) return;

        if (child[u][0] != 0) {
            dfs1(child[u][0], child, move);
        }

        if (child[u][1] != 0) {
            dfs1(child[u][1], child, move);
        }

        long left = 0;
        if (child[u][0] != 0) {
            left = move[child[u][0]] + 2;
        }

        long right = 0;
        if (child[u][1] != 0) {
            right = move[child[u][1]] + 2;
        }

        move[u] = (left + right) % mod;
    }

    static void dfs2(int u, long val, int[][] child, long[] move, long[] ans) {
        if (u == 0) return;

        ans[u] = (val + move[u]) % mod;

        if (child[u][0] != 0) {
            dfs2(child[u][0], ans[u] + 1, child, move, ans);
        }

        if (child[u][1] != 0) {
            dfs2(child[u][1], ans[u] + 1, child, move, ans);
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();   // test cases

        while (t-- > 0)
        {

            // ===== YOUR LOGIC HERE =====
            int n = sc.nextInt();

            int[][] child = new int[n + 1][2];

            for (int i = 1; i <= n; i++) {
                child[i][0] = sc.nextInt();
                child[i][1] = sc.nextInt();
            }

            long[] move = new long[n + 1];
            long[] ans = new long[n + 1];

            dfs1(1, child, move);
            dfs2(1, 1, child, move, ans);

            for (int i = 1; i <= n; i++) {
                System.out.print(ans[i] + " ");
            }
            System.out.println();


        }
    }
}