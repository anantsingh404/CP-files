import java.io.*;
import java.util.*;

public class f1080 {

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
    static class F {
        long a, b, c;
    }
    static boolean ok(F x, F y) {

        if (x.a == y.a) {
            if (x.b == y.b) {
                return true;
            } else {
                return false;
            }
        }

        long A = y.a - x.a;
        long B = y.b - x.b;
        long C = y.c - x.c;

        if (B * B < 4 * A * C) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();   // test cases
        while (t-- > 0)
        {

            // ===== YOUR LOGIC HERE ====
            int n = sc.nextInt();
            F[] f = new F[n];
            int i = 0;
            while (i < n) {
                f[i] = new F();
                f[i].a = sc.nextLong();
                f[i].b = sc.nextLong();
                f[i].c = sc.nextLong();
                i++;
            }
            Integer[] id = new Integer[n];
            i = 0;
            while (i < n) {
                id[i] = i;
                i++;
            }
            Arrays.sort(id, (i1, i2) -> {
                if (f[i1].a != f[i2].a) {
                    if (f[i1].a < f[i2].a) return -1;
                    else return 1;
                }
                if (f[i1].b != f[i2].b) {
                    if (f[i1].b < f[i2].b) return -1;
                    else return 1;
                }
                if (f[i1].c < f[i2].c) return -1;
                if (f[i1].c > f[i2].c) return 1;
                return 0;
            });

            long[] pre = new long[n];
            long[] suf = new long[n];

            i = 0;
            while (i < n) {
                int j = 0;
                while (j < i) {
                    if (pre[j] >= pre[i]) {
                        if (ok(f[id[j]], f[id[i]])) {
                            pre[i] = pre[j] + 1;
                        }
                    }
                    j++;
                }
                i++;
            }
            i = n - 1;
            while (i >= 0) {
                int j = n - 1;
                while (j > i) {
                    if (suf[j] >= suf[i]) {
                        if (ok(f[id[i]], f[id[j]])) {
                            suf[i] = suf[j] + 1;
                        }
                    }
                    j--;
                }
                i--;
            }
            long[] ans = new long[n];
            i = 0;
            while (i < n) {
                ans[id[i]] = pre[i] + suf[i] + 1;
                i++;
            }
            i = 0;
            while (i < n) {
                System.out.print(ans[i] + " ");
                i++;
            }
            System.out.println();
        }
    }
}