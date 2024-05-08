import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

    static int N,M;
    static int[][] arr;
    static void init() throws Exception{
        StringTokenizer st = new StringTokenizer(bf.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[N][M];
        for(int i=0; i<N; i++){
            String[] s = bf.readLine().split("");
            for(int j=0; j<M; j++){
                if(s[j].equals("W"))
                    arr[i][j] = 0;
                else
                    arr[i][j] = 1;
            }
        }
    }

    static int[] order = {0,1,0,1,0,1,0,1};
    static int result = 2501;
    static void cal(int y, int x, int idx){
        int cnt = 0;
        for(int i=y; i<y+8; i++){
            int n = order[idx];
            for(int j=x; j<x+8; j++){
                if(arr[i][j] != n)
                    cnt++;
                n = (n+1)%2;
            }
            idx = (idx+1)%8;
        }

        result = Math.min(result, cnt);
    }

    static void solve(){
        for(int i=0; i<N-7; i++){
            for(int j=0; j<M-7; j++){
                cal(i,j,0);
                cal(i,j,1);
            }
        }

        System.out.println(result);
    }

    public static void main(String[] args) throws Exception{
        init();
        solve();
    }
}
