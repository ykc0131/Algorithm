import java.io.*;
import java.lang.*;
import java.util.*;
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int N;
    static int[][] arr;
    static int INF = 1000000000;

    static void init() throws Exception {
        N = Integer.parseInt(br.readLine());

        arr = new int[N][10];
        for(int i=0; i<N; i++){
            if(i==0){
                Arrays.fill(arr[i],1);
                arr[0][0] = 0;
            }
            else
                Arrays.fill(arr[i],0);
        }
    }

    static void solve(){
        for(int i=1; i<N; i++){
            for(int j=0; j<10; j++){
                if(j==0)
                    arr[i][j] = arr[i-1][j+1];
                else if(j==9)
                    arr[i][j] = arr[i-1][j-1];
                else
                    arr[i][j] = (arr[i-1][j-1]%INF + arr[i-1][j+1]%INF)%INF;
            }
        }

        int result = 0;
        for(int i=0; i<10; i++){
            result += arr[N-1][i];
            result %= INF;
        }

        System.out.println(result);
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
