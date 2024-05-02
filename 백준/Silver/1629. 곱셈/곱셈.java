
import java.util.*;
import java.io.*;
import java.lang.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static int A,B,C;
    static void init() throws Exception{
        StringTokenizer st = new StringTokenizer(bf.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        bf.close();
    }

    static int re(int val){
        if(val==1)
            return A%C;

        long tmp = ((long)re(val/2)%C);

        long result = (tmp*tmp)%C;
        if(val%2==1)
            result = (int)((result%C * ((long)A%C))%C);
        return (int)result;
    }

    static void solve(){
        System.out.println(re(B));
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
