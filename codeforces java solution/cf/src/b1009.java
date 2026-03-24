import java.io.*;
import java.util.*;

public class b1009 {

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
            int n=sc.nextInt();
            int [] arr=new int[n];
             for(int i=0;i<n;i++)
             {
                 arr[i]=sc.nextInt();
             }
             Arrays.sort(arr);
             PriorityQueue< Integer>pq=new PriorityQueue<>();
             for(int i=0;i<n;i++)
             {
                 pq.add(arr[i]);
             }
             while(pq.size()>1)
             {
                 int x=pq.peek();
                 pq.poll();
                 int y=pq.peek();
                 pq.poll();
                 pq.add(x+y-1);
             }
             System.out.println(pq.peek());


        }
    }
}