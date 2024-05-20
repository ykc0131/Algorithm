import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int n;
    static int[] arr;

    static void init() throws Exception {
        n = Integer.parseInt(br.readLine());

        arr = new int[n+1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
    }

    static void solve(){
        long value=arr[0], result = arr[0];
        for(int i=1; i<n; i++){
            long cur = arr[i];
            if(cur < value+cur)
                value += cur;
            else
                value = cur;
            result = Math.max(value, result);
        }

        System.out.println(result);
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
