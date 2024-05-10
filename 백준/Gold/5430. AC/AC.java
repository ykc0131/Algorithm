
import java.util.*;
import java.lang.*;
import java.io.*;
public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static String cmd;
    static int N;
    static List<String> list;
    static void init() throws Exception {
        cmd = bf.readLine();
        N = Integer.parseInt(bf.readLine());

        String str = bf.readLine();
        str = str.substring(1,str.length()-1);
        StringTokenizer st = new StringTokenizer(str,",");

        list = new ArrayList<>();
        for(int i=0; i<N; i++){
            list.add(st.nextToken());
        }
    }
    static void solve() throws Exception {
        int l=0, r=N-1;
        boolean di = true;
        String[] cmdArr = cmd.split("");
        for(int i=0; i<cmd.length(); i++){
            if(cmdArr[i].equals("R"))
                di = !di;
            else{
                if(di && l < N)
                    l++;
                else if(!di && r >= 0)
                    r--;
                else{
                    bw.write("error\n");
                    return;
                }
            }
        }

        bw.write("[");
        if(r >= l){
            if(di)
                for(int i=l; i<=r; i++){
                    bw.write(list.get(i));
                    if(i!=r)
                        bw.write(",");
                }
            else
                for(int i=r; i>=l; i--){
                    bw.write(list.get(i));
                    if(i!=l)
                        bw.write(",");
                }
        }
        bw.write("]\n");
    }

    public static void main(String[] args) throws Exception {
        int T;
        T = Integer.parseInt(bf.readLine());

        while(T-->0){
            init();
            solve();
        }

        bw.flush();
        bw.close();
    }
}
