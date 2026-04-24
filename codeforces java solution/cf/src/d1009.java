import java.io.*;
import java.util.*;

public class d1009 {

    // ===== CONSTANTS =====
    static final int inf = (int)1e9;
    static final long linf = (long)1e18;
    static final long mod = 1000000007;

    // ===== DIRECTIONS =====
    static int[] dx4 = {-1, 0, 1, 0};
    static int[] dy4 = {0, 1, 0, -1};

    static int[] dx8 = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int[] dy8 = {-1, 0, 1, -1, 1, -1, 0, 1};

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while (t-- > 0)
        {

            int n = sc.nextInt();
            int m = sc.nextInt();

            int[] x = new int[n];
            int[] r = new int[n];

            int i = 0;
            while (i < n) {
                x[i] = sc.nextInt();
                i++;
            }

            i = 0;
            while (i < n) {
                r[i] = sc.nextInt();
                i++;
            }

            HashMap<Integer, Integer> map = new HashMap<>();

            i = 0;
            while (i < n) {

                int left = x[i] - r[i];
                int right = x[i] + r[i];

                int curr = left;

                while (curr <= right) {

                    int dx = curr - x[i];
                    long val = 1L * r[i] * r[i] - 1L * dx * dx;

                    int y = (int)Math.sqrt(val);

                    while ((long)(y + 1) * (y + 1) <= val) {
                        y++;
                    }
                    while ((long)y * y > val) {
                        y--;
                    }

                    if (map.containsKey(curr)) {
                        int prev = map.get(curr);
                        if (y > prev) {
                            map.put(curr, y);
                        }
                    } else {
                        map.put(curr, y);
                    }

                    curr++;
                }

                i++;
            }

            long ans = 0;

            for (int key : map.keySet()) {
                int y = map.get(key);
                ans += (2L * y + 1);
            }

            System.out.println(ans);
        }
    }
}