import java.util.*;
import java.lang.*;
import java.io.*;
public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int N;
    static List<Integer>[] list;
    static int[] parents;

    static void init() throws Exception {
        N = Integer.parseInt(bf.readLine());
        
        list = new List[N+1];
        for(int i=1; i<N+1; i++){
            list[i] = new ArrayList<>();
        }

        StringTokenizer st = null;
        for(int i=0; i<N-1; i++){
            st = new StringTokenizer(bf.readLine());
            int v = Integer.parseInt(st.nextToken());
            int u = Integer.parseInt(st.nextToken());

            list[v].add(u);
            list[u].add(v);
        }

        parents = new int[N+1];
    }


    static void bfs(){
        boolean[] visit = new boolean[N+1];
        Arrays.fill(visit,false);

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{1,0});

        while(!q.isEmpty()){
            int[] cur = q.poll();

            int curNode = cur[0], depth = cur[1];
            int size = list[curNode].size();

            for(int i=0; i<size; i++){
                int next = list[curNode].get(i);

                if(!visit[next]){
                    parents[next] = curNode;
                    visit[next] = true;
                    q.add(new int[]{next, depth+1});
                }
            }
        }
    }

    static void solve(){
        bfs();

        for(int i=2; i<N+1; i++){
            System.out.println(parents[i]);
        }
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
