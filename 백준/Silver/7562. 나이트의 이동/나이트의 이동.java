import java.util.*;
import java.lang.*;
import java.io.*;
public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static int l;

    static int[][] grid;
    static boolean[][] visited;
    static int[] start;
    static int[] end;
    static Integer INF = 90001;

    static int[] dy = {2, 1, -1, -2, -2, -1, 1, 2};
    static int[] dx = {1, 2, 2, 1, -1, -2, -2, -1};
    static void init() throws Exception {
        l = Integer.parseInt(bf.readLine());

        grid = new int[l][l];
        visited = new boolean[l][l];
        start = new int[2];
        end = new int[2];

        StringTokenizer st = new StringTokenizer(bf.readLine());
        start[0] = Integer.parseInt(st.nextToken());
        start[1] = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(bf.readLine());
        end[0] = Integer.parseInt(st.nextToken());
        end[1] = Integer.parseInt(st.nextToken());

        for(int i=0; i<l; i++){
            Arrays.fill(grid[i],INF);
            Arrays.fill(visited[i], false);
        }
    }

    static void solve(){
        PriorityQueue<int[]> q = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                if(a[0] == b[0])
                    return (Math.abs(a[1]-start[1]) + Math.abs(a[0] - start[0])) - (Math.abs(b[1]-start[1]) + Math.abs(b[0]-start[0]));
                return a[0] - b[0];
            }
        });

        q.add(new int[]{0,end[0], end[1]});
        grid[end[0]][end[1]] = 0;

        while(!q.isEmpty()){
            int[] cur = q.poll();
            int cost = cur[0], curY = cur[1], curX = cur[2];

            if(curY==start[0] && curX == start[1]){
                System.out.println(cost);
                break;
            }

            for(int i=0; i<8; i++){
                int _y = curY + dy[i];
                int _x = curX + dx[i];

                if(_y < 0 || _x < 0 || _y >= l || _x >=l )
                    continue;

                if(!visited[_y][_x] && grid[_y][_x] > cost+1 ){
                    visited[_y][_x] = true;
                    grid[_y][_x] = cost+1;
                    q.add(new int[]{grid[_y][_x], _y, _x});
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        int T = Integer.parseInt(bf.readLine());

        while(T-->0){
            init();
            solve();
        }
    }
}
