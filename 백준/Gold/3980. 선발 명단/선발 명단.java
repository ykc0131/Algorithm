import java.util.*;
import java.lang.*;
import java.io.*;

// 시간초과를 예상합니다ㅠㅠ
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[][] arr;
    static boolean[] visited;
    static int result;
    static void init() throws Exception {
        result = 0;
        arr = new int[11][11];
        for(int i=0; i<11; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=0; j<11; j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        visited = new boolean[11];
        Arrays.fill(visited, false);
    }


    static void backtracking(int cnt, int sum ){
        if(cnt==11){
            result = Math.max(result, sum);
            return;
        }
        for(int i=0; i<11; i++) { // i : 선수
            int val = arr[i][cnt];
            if(!visited[i] && val != 0) {
                visited[i] = true;
                backtracking(cnt+1, sum+val);
                visited[i] = false;
            }
        }
    }
    static void solve(){
        backtracking(0, 0); // cnt : 자리 번호
        System.out.println(result);
    }

    public static void main(String[] args) throws Exception {
        int T = Integer.parseInt(br.readLine());
        while(T--!=0){
            init();
            solve();
        }
    }
}
