import java.io.*;
import java.util.*;

public class a1009 {

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

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();   // test cases

        while (t-- > 0)
        {

            // ===== YOUR LOGIC HERE =====
            int l=sc.nextInt();
            int r=sc.nextInt();
            int d=sc.nextInt();
            int u=sc.nextInt();
            if(l==r && r==d && d==u)
            {
                System.out.println("Yes");
            }
            else
            {
                System.out.println("No");
            }

        }
    }
}