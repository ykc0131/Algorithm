
import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static int n;

    static int[][] arr;
    static void init() throws Exception {
        n = Integer.parseInt(bf.readLine());

        arr = new int[n][n];
        for(int i=0; i<n; i++){
            Arrays.fill(arr[i],0);
        }

        for(int i=0; i<n; i++){
            String s = bf.readLine();

            StringTokenizer stt = new StringTokenizer(s);
            for(int j=0; j<i+1; j++){
                arr[i][j] = Integer.parseInt(stt.nextToken());
            }
        }
    }

    static void solve(){
        for(int i=1; i<n; i++){
            for(int j=0; j<i+1; j++){
                int left = j-1;
                int right = j;

                int original = arr[i][j];
                if(left>=0)
                    arr[i][j] = Math.max(arr[i][j],arr[i-1][left]+original);

                if(right<i)
                    arr[i][j] = Math.max(arr[i][j],arr[i-1][right]+original);
            }
        }

        int result = 0;
        for(int i=0; i<n; i++){
            result = Math.max(result, arr[n-1][i]);
        }

        System.out.println(result);
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
