import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

    static void solve() throws Exception{
        int[] result = {0,0};
        for(int i=0; i<5; i++){
            StringTokenizer st = new StringTokenizer(bf.readLine());

            int sum = 0;
            while(st.hasMoreTokens()){
                sum += Integer.parseInt(st.nextToken());
            }


            if(result[1] < sum){
                result[0] = i;
                result[1] = sum;
            }
        }

        System.out.println(result[0]+1 + " " + result[1]);
    }

    public static void main(String[] args) throws Exception{
        solve();
    }
}
