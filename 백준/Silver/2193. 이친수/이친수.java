import java.util.*;
import java.io.*;
import java.lang.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static long arr[] = new long[101];

    static void init() throws Exception {
        N = Integer.parseInt(br.readLine());
        Arrays.fill(arr,0);

    }

    static void solve(){
        arr[0] = 1;
        arr[1] = 1;
        for(int i=2; i<N; i++){
            arr[i] = arr[i-1] + arr[i-2];
        }

        System.out.println(arr[N-1]);
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
