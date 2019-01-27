import java.io.*;
import java.util.*;

public class Carrot {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        
        int numCases = Integer.parseInt(in.readLine());
        
        for (int caseNo=0;caseNo<numCases;++caseNo) 
            solveCarrot(in, out);
       
        out.close();
    }
    
    static int getIntegerOrDefault(Integer n, int deft) { 
        return (n==null)?deft:n;
    }
    public static void solveCarrot(BufferedReader in, PrintWriter out) throws IOException {
        StringTokenizer header = new StringTokenizer(in.readLine());
        int W = Integer.parseInt(header.nextToken());
        int L = Integer.parseInt(header.nextToken());
        int n = Integer.parseInt(header.nextToken());
        
        NavigableSet<Integer> ends = new TreeSet<>();
        for (int i=0;i<n;++i) {
            StringTokenizer stok = new StringTokenizer(in.readLine());
            String cmd = stok.nextToken();
            int lo = Integer.parseInt(stok.nextToken()); 
            int hi = Integer.parseInt(stok.nextToken())+1;
            
            if (cmd.equals("harvest")) {
                int prevArea = (lo - ends.floor(lo))*L;
                int nextArea = (ends.ceiling(hi) - hi)*L;
                out.printf("%d %d\n", prevArea, nextArea);
            }
            
            if (ends.contains(hi)) { ends.remove(hi); } else { ends.add(hi);  }
            if (ends.contains(lo)) { ends.remove(lo); } else { ends.add(lo);  }
            
            if (cmd.equals("plant")) {
                hi = ends.ceiling(hi); lo = ends.floor(lo);
                
                int prevArea = (lo - getIntegerOrDefault(ends.lower(lo), 0))*L;
                int nextArea = (getIntegerOrDefault(ends.higher(hi), W) - hi)*L;
                
                out.printf("%d %d\n", prevArea, nextArea);                
            }
        }
        out.printf("--\n");
    }
}