import java.util.*;
import java.io.*;
import java.lang.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static int n;
    static int[] arr;
    static int INF = 10007;

    static void init() throws Exception {
        n = Integer.parseInt(bf.readLine());
        arr = new int[1001];
        Arrays.fill(arr,0);
    }

    static void solve(){
        arr[1] = 1;
        arr[2] = 3;

        for(int i=3; i<n+1; i++){
            arr[i] = (arr[i-2]*2)%INF + (arr[i-1]%INF);
            arr[i] %= INF;
        }

        System.out.println(arr[n]%INF);
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
