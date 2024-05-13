import java.util.*;
import java.io.*;
import java.lang.*;
public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static int N,score,P;
    static Map<Integer, Integer> m = new HashMap<>();

    static void init() throws Exception{
        StringTokenizer st = new StringTokenizer(bf.readLine());

        N = Integer.parseInt(st.nextToken());
        score = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());

        if(m.containsKey(score))
            m.put(score, m.get(score)+1);
        else
            m.put(score,1);

        if(N==0)
            return;
        st = new StringTokenizer(bf.readLine());
        for(int i=0; i<N; i++){
            int key = Integer.parseInt(st.nextToken());
            if(m.containsKey(key))
                m.put(key, m.get(key)+1);
            else
                m.put(key,1);
        }
    }

    static void solve(){
        List<Integer> keySet = new ArrayList<>(m.keySet());
        Collections.sort(keySet);
        Collections.reverse(keySet);
        int cnt = 0, result = -1;
        for(Integer key : keySet){
            int value = m.get(key);
            if(key==score){
                if(cnt+value<=P)
                    result = cnt+1;
                break;
            }

            if(cnt+value>P)
                break;
            cnt+=value;
        }
        System.out.println(result);
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
