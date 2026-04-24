import java.io.*;
import java.util.*;

public class f1009 {

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
    static long func(long l1, long r1, long l2, long r2, long x)
    {
        if (l1 == r1 || l2 == r2)
        {
            return 0;
        }

        long ll1, rr1, ll2, rr2;

        if (l1 % x == 0)
        {
            ll1 = l1;
        }
        else
        {
            ll1 = (l1 / x) * x + x;
        }

        if (l2 % x == 0)
        {
            ll2 = l2;
        }
        else
        {
            ll2 = (l2 / x) * x + x;
        }

        rr1 = (r1 / x) * x;
        rr2 = (r2 / x) * x;

        if (rr1 <= ll1 || rr2 <= ll2)
        {
            return func(l1, r1, l2, r2, x / 2);
        }

        long ans = 0;

        ans += ((rr1 - ll1) / x) * ((rr2 - ll2) / x);

        ans += func(l1, ll1, l2, ll2, x / 2);
        ans += func(ll1, rr1, l2, ll2, x / 2);
        ans += func(rr1, r1, l2, ll2, x / 2);
        ans += func(rr1, r1, ll2, rr2, x / 2);
        ans += func(rr1, r1, rr2, r2, x / 2);
        ans += func(ll1, rr1, rr2, r2, x / 2);
        ans += func(l1, ll1, rr2, r2, x / 2);
        ans += func(l1, ll1, ll2, rr2, x / 2);

        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();   // test cases

        while (t-- > 0)
        {

            // ===== YOUR LOGIC HERE =====
            long l1 = sc.nextLong();
            long r1 = sc.nextLong();
            long l2 = sc.nextLong();
            long r2 = sc.nextLong();

            long res = func(l1, r1, l2, r2, 1L << 20);

            System.out.println(res);


        }
    }
}