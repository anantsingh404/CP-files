import java.io.*;
import java.util.*;

public class c1009 {

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

            int x=sc.nextInt();

                int z = 0;
                for(int i = 31; i >= 0; i--)
                {
                    if((x&(1<<i))>0)
                    {
                        z = (1<<i);
                        break;
                    }
                }

                for(int i = 0; i <= 31; i++){
                    if((x & ((int)1<<i)) == 0){
                        z += ((int)1<<i);
                        break;
                    }
                }
                int y = x ^ z;
                if(x + y <= z || x + z <= y || y + z <= x || y >= x)
                {
                    System.out.println(-1);
                }
                else
                {
                    System.out.println(y);
                }

        }
    }
}