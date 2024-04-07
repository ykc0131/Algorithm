import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static final int INF = 10000001;
    static int N;
    static int[][] dist;
    static void init(){
        N = sc.nextInt();

        dist = new int[N][N];

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                int n = sc.nextInt();
                if(n==0)
                    n = INF;
                dist[i][j] = n;
            }
        }
    }

    static void solve(){
        for(int k = 0; k < N; k++)
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++)
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if (dist[i][j] == INF)
                    System.out.print(0 + " ");
                else
                    System.out.print(Math.min(1,dist[i][j]) + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        init();
        solve();
    }
}

