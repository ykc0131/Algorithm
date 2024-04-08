
import java.io.*;
import java.util.*;

public class Main {
    static int M,N,K;
    static Integer[][] arr;
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

    static void init() throws Exception{
        String s = bf.readLine();

        StringTokenizer st = new StringTokenizer(s);
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        arr = new Integer[M+1][N+1];
        for(int i=0; i<M+1; i++){
            Arrays.fill(arr[i],0);
        }

        ArrayList<String[]> coordis = new ArrayList<>();
        for(int i=0; i<K; i++){
            s = bf.readLine();
            String arr[] = s.split(" ");
            coordis.add(arr);
        }

        for(int i=0; i<K; i++){
            String[] starr = coordis.get(i);
            rectangle(Integer.parseInt(starr[0]),Integer.parseInt(starr[1]),Integer.parseInt(starr[2]),Integer.parseInt(starr[3]));
        }
    }

    static void rectangle(int x1, int y1, int x2, int y2){
        for(int i=x1; i<x2; i++){
            for(int j=y1; j<y2; j++){
                arr[j][i] = 1;
            }
        }
    }

    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    static boolean[][] check;
    static int area = 0;
    static void dfs(int y, int x){
        if(check[y][x])
            return;
        area++;
        check[y][x] = true;

        for(int i=0; i<4; i++){
            int _y = y + dy[i];
            int _x = x + dx[i];

            if(_y<0 || _x<0 || _y>=M || _x>=N)
                continue;

            if(!check[_y][_x] && arr[_y][_x]!=1){
                dfs(_y,_x);
            }
        }
    }

    static void solve(){
        ArrayList<Integer> result = new ArrayList<>();
        check = new boolean[M+1][N+1];
        for(int i=0; i<M+1; i++){
            Arrays.fill(check[i],false);
        }

        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                if(!check[i][j] && arr[i][j] == 0){
                    dfs(i,j);
                    result.add(area);
                    area=0;
                }
            }
        }

        Collections.sort(result);

        System.out.println(result.size());
        for(int i=0; i<result.size(); i++){
            System.out.print(result.get(i) + " ");
        }
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
