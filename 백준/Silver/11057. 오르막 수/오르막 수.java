import java.util.*;
import java.io.*;
import java.lang.*;
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static int INF = 10007;
    static int[][] arr = new int[1001][11];

    static void init() throws Exception {
        N = Integer.parseInt(br.readLine());
    }

    static void solve(){
        Arrays.fill(arr[0],1);

        if(N==1){
            System.out.println(10);
            return;
        }
        for(int i=1; i<N-1; i++){
            Arrays.fill(arr[i],0);
            arr[i][0] = 1;
            for(int j=1; j<10; j++){
                arr[i][j] = arr[i][j-1]%INF + arr[i-1][j]%INF;
                arr[i][j] %=INF;
            }
        }

        int result = 0;
        for(int i=0; i<10; i++){
            result += (arr[N-2][i] * (10-i))%INF;
            result %= INF;
        }

        System.out.println(result);
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}