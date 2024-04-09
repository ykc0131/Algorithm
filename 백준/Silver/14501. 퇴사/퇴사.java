
import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static int T;

    static ArrayList<int[]> arrs;

    static void init() throws IOException {
        T = Integer.parseInt(bf.readLine());

        arrs = new ArrayList<>();
        for(int i=0; i<T; i++){
            String s= bf.readLine();
            StringTokenizer stt = new StringTokenizer(s);

            int[] arr = {i+1, i+Integer.parseInt(stt.nextToken()),
                    Integer.parseInt(stt.nextToken())};
            arrs.add(arr);
        }
    }

    static int result = 0;
    static void backtracking(int idx, int value, int end){
        result = Math.max(result, value);
        if(idx>=T)
            return;

        for(int i=idx; i<T; i++){
            int[] arr = arrs.get(i);

            if(arr[0] <= end)
                continue;

            if(arr[1] > T)
                continue;
            backtracking(idx+1, value+arr[2], arr[1]);
        }
    }

    static void solve(){
        backtracking(0,0,0);
        System.out.println(result);
    }

    public static void main(String[] args) throws IOException {
        init();
        solve();
    }
}