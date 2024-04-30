import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static int[][] arr;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    static int N,M;

    static void init() throws IOException {
        StringTokenizer stt = new StringTokenizer(bf.readLine());

        N = Integer.parseInt(stt.nextToken());
        M = Integer.parseInt(stt.nextToken());
        arr = new int[N][M];

        for(int i=0; i<N; i++){
            String[] input = bf.readLine().split("");

            for(int j=0; j<M; j++) {
                int value = 0;
                if (input[j].equals("L"))
                    value = 1;
                arr[i][j] = value;
            }
        }
    }

    static int maxN = 0;
    static void bfs(int y, int x){
        boolean[][] visit = new boolean[N][M];
        for(int i=0; i<N; i++){
            Arrays.fill(visit[i],false);
        }

        Queue<int[]> q = new LinkedList<>();

        q.add(new int[]{0, y, x});
        visit[y][x] = true;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int curCnt = cur[0];
            int curY = cur[1];
            int curX = cur[2];

            maxN = Math.max(maxN, curCnt);
            for (int i = 0; i < 4; i++) {
                int _y = curY + dy[i];
                int _x = curX + dx[i];

                if (_y < 0 || _x < 0 || _y >= N || _x >= M)
                    continue;

                if (!visit[_y][_x] && arr[_y][_x] == 1 ) {
                    visit[_y][_x] = true;
                    q.add(new int[]{curCnt + 1, _y, _x});
                }
            }
        }
    }

    static void solve(){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j] == 1){
                    bfs(i,j);
                }
            }
        }
        System.out.println(maxN);
    }

    public static void main(String[] args) throws IOException {
        init();
        solve();
    }
}
