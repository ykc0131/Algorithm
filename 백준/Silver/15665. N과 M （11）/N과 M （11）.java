import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

    static int N,M;
    static Map<Integer,Integer> m = new HashMap<>();
    static List<Integer> list;

    static void init() throws Exception {
        StringTokenizer st = new StringTokenizer(bf.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(bf.readLine());
        for(int i=0; i<N; i++)
            m.put(Integer.parseInt(st.nextToken()),1);

        list = new ArrayList<>(m.keySet());
        m.clear();
        bf.close();
    }

    static int size = 0;
    static List<String> result = new ArrayList<>();
    static void backtracking(int idx, String s, int cnt){
        if(cnt==M){
            result.add(s);
            return;
        }

        if(idx >= size )
            return;

        for(int i=0; i< size; i++){
            backtracking(i, s+ String.valueOf(list.get(i)) + " ", cnt+1);
        }
    }

    static void solve(){
        size = list.size();
        backtracking(0,"",0);

        for(String s : result){
            System.out.println(s);
        }
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
