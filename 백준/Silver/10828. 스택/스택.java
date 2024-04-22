import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static void init() throws Exception {
        N = Integer.parseInt(bf.readLine());
    }

    static void solve() throws Exception {
        Stack<Integer> st = new Stack<>();
        while(N-->0){
            StringTokenizer stt = new StringTokenizer(bf.readLine());

            String cmd = stt.nextToken();
            if(cmd.equals("push")){
                st.push(Integer.parseInt(stt.nextToken()));
            }
            else if(cmd.equals("pop")){
                if(st.isEmpty())
                    System.out.println(-1);
                else
                    System.out.println(st.pop());
            }
            else if(cmd.equals("top")){
                if(st.isEmpty())
                    System.out.println(-1);
                else
                    System.out.println(st.peek());
            }
            else if(cmd.equals("size")){
                System.out.println(st.size());
            }
            else if(cmd.equals("empty")){
                System.out.println(st.empty()?1:0);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
