import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int[][] nPad = new int[5][5];
    static void init() throws IOException {
        for(int i=0; i<5; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());

            for(int j=0; j<5; j++){
                nPad[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    static Set<String> result = new HashSet<>();
    static int[] dy = {0,1,0,-1};
    static int[] dx = {1,0,-1,0};

    static StringBuilder sb;
    static void backtracking(int y, int x, int cnt){
        if(cnt==6){
            result.add(sb.toString());
            return;
        }

        for(int i=0; i<4; i++){
            int _y = y + dy[i];
            int _x = x + dx[i];

            if(_y < 0 || _x < 0 || _y >= 5 || _x >= 5)
                continue;

            sb.append(nPad[_y][_x]);
            backtracking(_y, _x, cnt+1);
            sb.deleteCharAt(cnt);
        }
    }

    static void solve() {
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                sb = new StringBuilder();
                backtracking(i, j, 0);
            }
        }
        System.out.println(result.size());
    }

    public static void main(String[] args) throws IOException {
        init();
        solve();
    }
}