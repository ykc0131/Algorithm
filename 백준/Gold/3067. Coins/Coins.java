import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);
    static Integer[] coins;
    static Integer[][] cal;
    static Integer[] result;

    static int N,M;

    static void init(){
        N = M = 0;

        N = sc.nextInt();
        coins = new Integer[N];

        for(int i=0; i<N; i++){
            coins[i] = sc.nextInt();
        }

        M = sc.nextInt();

        cal = new Integer[N][M+1];
        result = new Integer[M+1];

        for(int i=0; i<N; i++){
            Arrays.fill(cal[i],0);
        }
        Arrays.fill(result,0);
    }

    static void solve(){
        for(int i=0; i<N; i++){ // coin
            int coin = coins[i];
            for(int j=1; j<M+1; j++){ //금액
                if(coin==j) {
                    cal[i][j] += 1;
                    result[j] += 1;
                }

                if(j-coin>=1){
                    cal[i][j] += result[j-coin];
                    result[j] += cal[i][j];
                }
            }
        }
        System.out.println(result[M]);
    }

    public static void main(String[] args) {
        int T;
        T = sc.nextInt();

        while(T-- > 0){
            init();
            solve();
        }
    }
}
