import java.util.*;
import java.io.*;
import java.lang.*;
public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static int N,M,K;
    static List<Integer> hori;
    static List<Integer> verti;
    static void init() throws Exception{
        StringTokenizer st = new StringTokenizer(bf.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(bf.readLine());
        K = Integer.parseInt(st.nextToken());

        hori = new ArrayList<>();
        verti = new ArrayList<>();
        hori.add(0);
        verti.add(0);
        for(int i=0; i<K; i++){
            st = new StringTokenizer(bf.readLine());
            switch(Integer.parseInt(st.nextToken())){
                case 0 :
                        hori.add(Integer.parseInt(st.nextToken()));
                        break;
                case 1 :
                        verti.add(Integer.parseInt(st.nextToken()));
                        break;
            }
        }
        hori.add(M);
        verti.add(N);

        Collections.sort(hori);
        Collections.sort(verti);
    }

    static void solve(){
        int result = 0;
        for(int i=1; i<hori.size(); i++){
            for(int j=1; j<verti.size(); j++){
                int width = hori.get(i) - hori.get(i-1);
                int height = verti.get(j) - verti.get(j-1);
                result = Math.max(result, width * height);
            }
        }
        System.out.println(result);
    }

    public static void main(String[] args) throws Exception{
        init();
        solve();
    }
}
