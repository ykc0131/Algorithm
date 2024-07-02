import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N,M;
    static int[] input;
    static int[][] section;
    static int[] sumArr;

    static void init() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        input = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++){
            input[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());

        section = new int[M][2];
        for(int i=0; i<M; i++){
            st = new StringTokenizer(br.readLine());

            section[i][0] = Integer.parseInt(st.nextToken());
            section[i][1] = Integer.parseInt(st.nextToken());
        }

        sumArr = new int[N];
    }

    static void solve(){
        sumArr[0] = input[0];
        for(int i=1; i<N; i++){
            sumArr[i] = input[i] + sumArr[i-1];
        }

        StringBuilder sb = new StringBuilder();
        for(int[] s : section){
            sb.append(sumArr[s[1]-1] - sumArr[s[0]-1] + input[s[0]-1]);
            sb.append("\n");
        }
        System.out.println(sb.toString());
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
