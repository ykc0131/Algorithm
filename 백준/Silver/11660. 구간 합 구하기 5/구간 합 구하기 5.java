import java.util.*;
import java.io.*;
import java.lang.*;
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int N,M;
    static int[][] input;
    static long[][] sum;
    static int[][] coordi;
    static void init() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        input = new int[N][N];
        sum = new long[N][N];

        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());

            for(int j=0; j<N; j++){
                input[i][j] = Integer.parseInt(st.nextToken());
                sum[i][j] = input[i][j];
                if(j!=0)
                    sum[i][j] += sum[i][j-1];
            }

            if(i!=0){
                for(int j=0; j<N; j++){
                    sum[i][j] += sum[i-1][j];
                }
            }
        }

        coordi = new int[M][4];
        for(int i=0; i<M; i++){
            st = new StringTokenizer(br.readLine());

            for(int j=0; j<4; j++){
                coordi[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    static void solve() throws Exception {
        StringBuilder sb = new StringBuilder();

        for(int i=0; i<M; i++){
            int[] c1 = new int[]{coordi[i][1]-1, coordi[i][0]-1};
            int[] c2 = new int[]{coordi[i][3]-1, coordi[i][2]-1};

            long result = sum[c2[1]][c2[0]]; // sum[y2][x2];
            if(c1[0]!=0)
                result -= sum[c2[1]][c1[0]-1]; // sum[y2][x1-1];
            if(c1[1]!=0)
                result -= sum[c1[1]-1][c2[0]]; // sum[y1-1][x2];

            if(c1[0]!=0 && c1[1]!=0)
                result += sum[c1[1]-1][c1[0]-1]; // sum[y1-1][x1-1];

            sb.append(result + "\n");
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
