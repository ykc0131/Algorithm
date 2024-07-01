import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static int INF = 1000;
    static int[][] inputs;
    static int[][] arr;

    static void init() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        inputs = new int[N][N];
        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());

            for(int j=0; j<N; j++){
                inputs[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        arr = new int[N][N];
        for(int i=0; i<N; i++){
            Arrays.fill(arr[i], INF);

            if(i==0 || i==N-1)
                continue;
            for(int j=1; j<N-1; j++){
                arr[i][j] = inputs[i][j] + inputs[i][j+1] + inputs[i+1][j] + inputs[i][j-1]+ inputs[i-1][j];
            }
        }
    }

    static int minResult = INF*200;
    static ArrayList<int[]> flowerCordi = new ArrayList<>();
    static List<int[]> list = new ArrayList<>();
    static boolean checkFlower(int y, int x){
        for(int[] cordi : flowerCordi){
            int _y = Math.abs(cordi[0] - y);
            int _x = Math.abs(cordi[1] - x);

            if(_y+_x <=2 )
                return false;
        }
        return true;
    }

    static int sumFlower(){
        int result = 0;
        for(int[] cordi : flowerCordi){
            result += arr[cordi[0]][cordi[1]];
        }
        return result;
    }

    static void backtracking(int idx, int cnt){
        if(cnt==3){
            int sum = sumFlower();
            minResult = Math.min(sum, minResult);
            return;
        }

        if(idx>=list.size())
            return;

        for(int i=idx; i<list.size(); i++){
            int[] l = list.get(i);
            if(checkFlower(l[1], l[2])){
                flowerCordi.add(new int[]{l[1], l[2]}); // attach
                backtracking(i+1, cnt+1);
                flowerCordi.remove(flowerCordi.size()-1); // detach
            }
        }
    }
    static void solve(){
        for(int i=1; i<N-1; i++){
            for(int j=1; j<N-1; j++){
                list.add(new int[]{arr[i][j], i, j});
            }
        }

        Collections.sort(list,(a,b)-> a[0] - b[0]); // 평 수 가격에 대해 오름차순
        backtracking(0,0);

        System.out.println(minResult);
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}