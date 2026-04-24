import java.io.*;
import java.util.*;

public class e1009 {

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

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        Random rand = new Random();

        int t = Integer.parseInt(br.readLine());

        while (t-- > 0)
        {
            int n = Integer.parseInt(br.readLine());

            int a = 1;
            int b = 2;
            int c = 3;

            while (true)
            {
                out.println("? " + a + " " + b + " " + c);
                out.flush();

                int res = Integer.parseInt(br.readLine());

                if (res == -1)
                {
                    return;
                }

                if (res == 0)
                {
                    out.println("! " + a + " " + b + " " + c);
                    out.flush();
                    break;
                }

                int idx = rand.nextInt(3);

                if (idx == 0)
                {
                    a = res;
                }
                else if (idx == 1)
                {
                    b = res;
                }
                else
                {
                    c = res;
                }
            }
        }
    }
}