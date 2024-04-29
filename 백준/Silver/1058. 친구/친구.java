import java.util.*;
import java.io.*;
import java.lang.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static int[][] result;
    static List<Integer>[] list;

    static void init() throws Exception {
        N = Integer.parseInt(bf.readLine());
        result = new int[N][N];
        list = new List[N];
        for(int i=0; i<N; i++){
            List<Integer> l = new ArrayList<>();
            String[] stt = bf.readLine().split("");
            for(int j=0; j<N; j++){
                if(stt[j].equals("Y"))
                    l.add(j);
                result[i][j] = stt[j].equals("Y") ? 1 : 0;
            }
            list[i] = l;
        }
    }

    static void solve(){
        for(int i=0; i<N; i++){
            for(int j=0; j<list[i].size(); j++){
                int friend = list[i].get(j);

                List<Integer> _fri = list[friend];
                for(Integer in : _fri){
                    if(in == i)
                        continue;
                    result[i][in] = 1;
                }
            }
        }

        int maxN = 0;
        for(int i=0; i<N; i++){
            int cnt = 0;
            for(int j=0; j<N; j++){
                if(result[i][j]==1)
                    cnt++;
                maxN = Math.max(maxN, cnt);
            }
        }

        System.out.println(maxN);
    }

    public static void main(String[] args) throws Exception{
        init();
        solve();
    }
}
