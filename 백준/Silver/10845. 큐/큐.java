import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static int N;

    static void init() throws Exception {
        N = Integer.parseInt(bf.readLine());
    }

    static void solve() throws Exception {
        Queue<Integer> q = new LinkedList<>();
        int pre = -1;
        while(N-->0){
            StringTokenizer stt = new StringTokenizer(bf.readLine());

            String cmd = stt.nextToken();
            if(cmd.equals("push")){
                int value = Integer.parseInt(stt.nextToken());
                q.add(value);
                pre = value;
            }
            else if(cmd.equals("pop")){
                if(q.isEmpty())
                    System.out.println(-1);
                else{
                    System.out.println(q.peek());
                    q.remove();
                }
            }
            else if(cmd.equals("size")){
                System.out.println(q.size());
            }
            else if(cmd.equals("empty")){
                System.out.println(q.isEmpty()?1:0);
            }
            else if(cmd.equals("front")){
                if(q.isEmpty())
                    System.out.println(-1);
                else
                    System.out.println(q.peek());
            }
            else if(cmd.equals("back")){
                if(q.isEmpty())
                    System.out.println(-1);
                else
                    System.out.println(pre);
            }
        }
    }

    public static void main(String[] args) throws Exception{
        init();
        solve();
    }
}
