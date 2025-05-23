import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.io.*;
import java.util.*;

class Pair{
	int x,y;
	
	Pair(){}
	
	Pair(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class Main {
    static int n, m, cnt = 1;
    static Pair[] blackStone;
    static int[] redStone;
    static int ans = 0;
    static StringBuilder sb = new StringBuilder();
    static BufferedReader br;
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    
    public static void main(String[] args) throws IOException {
		// System.setIn(Main.class.getResourceAsStream("/Algorithm/input.txt"));
		br = new BufferedReader(new InputStreamReader(System.in));
	    StringTokenizer st = new StringTokenizer(br.readLine());

	    n = Integer.parseInt(st.nextToken());
	    m = Integer.parseInt(st.nextToken());
	    ans = 0;

	    redStone = new int[n];
	    blackStone = new Pair[m];
	    
	    for(int i = 0; i < n;i++) {
	    	st = new StringTokenizer(br.readLine());
	 	    redStone[i] = Integer.parseInt(st.nextToken());
	    }
	    
	    
	    for(int i = 0; i < m;i++) {
	    	st = new StringTokenizer(br.readLine());
	    	int x =  Integer.parseInt(st.nextToken());
	    	int y =  Integer.parseInt(st.nextToken());
	 	    blackStone[i] = new Pair(x,y);
	 	    }
	    	
	    
	    solve();
		  
	    System.out.print(ans);
	    
    }

    public static void solve() throws IOException {
        // 입력부
    	// 자바는 minheap
    	// PriorityQueue<Integer> pq = new PriorityQueue<>();
    	TreeSet<Integer> redS = new TreeSet<>();
    	
    	
        for(int i = 0; i < n;i++) 
        	redS.add(redStone[i]);
	    
        // y값이 작은 순으로정렬
        // y가 같으면 x값이 작은 순으로
        Arrays.sort(blackStone, (a, b) -> {
            if (a.y!= b.y) return a.y - b.y; 
            return a.x - b.x;                  
        });
	 
        // for(int i = 0; i < m;i++) 
	 	//     System.out.println(blackStone[i].x + " " + blackStone[i].y);
        
    	int cur = -1;
	    for(int i = 0; i < m;i++) {
	    	int x = blackStone[i].x;
	    	int y = blackStone[i].y;
	    	
	    	if(redS.ceiling(x) != null) {
	    		int num = redS.ceiling(x);
	    		if(num <= y) {
	    			ans++;
	    			redS.remove(num);
	    		}	
	    	}
	    }
   }

}