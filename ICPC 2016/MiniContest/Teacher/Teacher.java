
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.PriorityQueue;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author apirakhoonlor
 */
public class Teacher {
    
        static class TNode implements Comparable{
            int id;
            int end;
            int start;
            public TNode(int i, int st, int en){
                id = i;
                end = en;
                start = st;
            }
        
        public int compareTo(Object target){
            TNode tarNode = (TNode) target;
            return Integer.compare(end, tarNode.end);
        }
        
        public String toString(){
            String output = id + ":<" + start + ", " + end + ">";
            return output;
        }
        }
        public static TNode[] end;
        public static long[] cost;
        public static int PSIZE;
        
	public static void main(String[] args) throws IOException {
		
		 BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in)); 
		 String line = stdin.readLine(); 
		 int numTestCase = Integer.parseInt(line.trim());		 
		 StringTokenizer numTokens;
                 int[][] input;
                 int size, si, sj, ek;
                 long el;
		 for(int i=0 ; i < numTestCase ; i++){                     
			 line = stdin.readLine();
                         size = Integer.parseInt(line.trim());
                         PSIZE = size;
                         end = new TNode[size];
                         cost = new long[size];
                         for(int j = 0; j < size; j++){
                             line = stdin.readLine();
                             numTokens = new StringTokenizer(line, " \t\r\n");
                             si = Integer.parseInt(numTokens.nextToken());
                             ek = Integer.parseInt(numTokens.nextToken())+si;
                             el = Long.parseLong(numTokens.nextToken());
                             end[j] = new TNode(j,si,ek);
                             cost[j] = el;
                         }
                         System.out.println(solve());
		 }
	}
        
        public static long solve(){
            Arrays.sort(end);
            long[] M = new long[PSIZE+1];
            int i, cdi;
            long ch;
            M[0] = 0;
            for(i = 1; i <= PSIZE; i++){
                cdi = getPI(end[i-1].start, i-1);
                ch = cost[end[i-1].id] + M[cdi+1];
                M[i] = Math.max(M[i-1],ch);
            }
            return M[PSIZE];
        }
        
        public static int getPI(int st, int cdex){
//            return Arrays.binarySearch(end, st);
            int max_e = -1;
            int max_i = -1;
            int i;
            for(i = cdex-1; i >= 0; i--){
                if(end[i].end < st && end[i].end > max_e){
                    max_e = end[i].end;
                    max_i = i;
                }
            }
            return max_i;
        }
        
        
    
}
