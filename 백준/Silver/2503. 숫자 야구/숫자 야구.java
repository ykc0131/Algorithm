import java.util.*;
import java.io.*;
import java.lang.*;
public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

    static int N;
    static List<int[]> list = new ArrayList<>();
    static void init() throws Exception {
        StringTokenizer st = new StringTokenizer(bf.readLine());
        N = Integer.parseInt(st.nextToken());

        for(int i=0; i<N; i++){
            st = new StringTokenizer(bf.readLine());

            int[] tmp = new int[3];
            tmp[0] = Integer.parseInt(st.nextToken());
            tmp[1] = Integer.parseInt(st.nextToken());
            tmp[2] = Integer.parseInt(st.nextToken());
            list.add(tmp);
        }
    }

    static Map<Integer, Integer> m = new HashMap<>();
    static void cal(int index){
        int[] l = list.get(index);
        int n1=l[0]/100, n2=(l[0]%100)/10, n3 = l[0]%10;

        for(int i=1; i<10; i++){
            for(int j=1; j<10; j++){
                for(int k=1; k<10; k++){
                    if(i==j || i==k || j==k)
                        continue;
                    int s = (i==n1 ? 1 : 0) + (j==n2 ? 1 : 0) + (k==n3 ? 1 : 0);
                    int b = (j==n1 || k==n1 ? 1 : 0) + (i==n2 || k==n2 ? 1 : 0 ) + (i==n3 || j == n3 ? 1 : 0);

                    int key = i*100+j*10+k;
                    if(s==l[1] && b==l[2]){
                        if(index==0)
                            m.put(key,1);
                        else if(m.containsKey(key))
                            m.put(key, m.get(key)+1);
                    }
                }
            }
        }
    }

    static void solve(){
        for(int i=0; i<N; i++){
            cal(i);
        }

        int cnt = 0;
        for(Integer i : m.keySet()){
            if(m.get(i)==N)
                cnt++;
        }
        System.out.println(cnt);
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }

}
