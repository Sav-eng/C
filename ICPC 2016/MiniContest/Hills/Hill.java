
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author apirakhoonlor
 */
public class Hill {
    public static int MAX = 600000;
    public static int min_i = -1;
    public static int min_j = -1;
    
	public static void main(String[] args) throws IOException {
		
		 BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in)); 
		 String line = stdin.readLine(); 
		 int numTestCase = Integer.parseInt(line.trim());		 
		 StringTokenizer numTokens;
                 int[][] input;
                 int size, si, sj, ek, el;
		 for(int i=0 ; i < numTestCase ; i++){                     
			 line = stdin.readLine();
                         numTokens = new StringTokenizer(line, " \t\r\n");
                         size = Integer.parseInt(numTokens.nextToken());
                         si = Integer.parseInt(numTokens.nextToken())-1;
                         sj = Integer.parseInt(numTokens.nextToken())-1;
                         ek = Integer.parseInt(numTokens.nextToken())-1;
                         el = Integer.parseInt(numTokens.nextToken())-1;
                         input = new int[size][size];
                         for(int j = 0; j < size; j++){
                             line = stdin.readLine();
                             numTokens = new StringTokenizer(line, " \t\r\n");
                             for(int k = 0; k < size; k++){
                                 input[j][k] = Integer.parseInt(numTokens.nextToken());
                             }
                         }
                         System.out.println(solve(size, si, sj, ek, el, input));
		 }
	}
        
        public static int solve(int size, int si, int sj, int ek, int el, int[][] input){
            int[][] distances = new int[size][size];
            boolean[][] visited = new boolean[size][size];
            int i,j, ci, cj, step, elev;
            for(i = 0; i < size; i++){
                for(j = 0; j < size; j++){
                    distances[i][j] = MAX;
                    visited[i][j] = false;
                }
            }
            distances[si][sj] = 0;
            visited[si][sj] = true;
            int maxNum = size*size;
            boolean done = false;
            ci = si;
            cj = sj;
            step = 0;
//            System.out.println("Begin");
            while(step < maxNum && !done){
//                System.out.println("step " + step + " ci,cj::" + ci + "," + cj);
                visited[ci][cj] = true;
                if(ci == ek && cj == el){
                    return distances[ci][cj];
                }
                if((ci - 1) >= 0 && !visited[ci-1][cj]){
                    elev = distances[ci][cj]+ Math.abs(input[ci][cj] - input[ci-1][cj]);
//                    System.out.println("elev " + elev);
                    if(distances[ci-1][cj] > elev){
                        distances[ci-1][cj] = elev;
                    }
//                    System.out.println("left " + distances[ci-1][cj]);
                }                
                if((cj - 1) >= 0 && !visited[ci][cj-1]){
                    elev = distances[ci][cj]+ Math.abs(input[ci][cj] - input[ci][cj-1]);
//                    System.out.println("elev " + elev);
                    if(distances[ci][cj-1] > elev){
                        distances[ci][cj-1] = elev;
                    }
//                    System.out.println("up " + distances[ci][cj-1]);
                }
                if((ci + 1) < size && !visited[ci+1][cj]){
                    elev = distances[ci][cj]+ Math.abs(input[ci][cj] - input[ci+1][cj]);
//                    System.out.println("elev " + elev);
                    if(distances[ci+1][cj] > elev){
                        distances[ci+1][cj] = elev;
                    }
//                    System.out.println("right " + distances[ci+1][cj]);
                }                
                if((cj + 1) < size && !visited[ci][cj+1]){
                    elev = distances[ci][cj]+ Math.abs(input[ci][cj] - input[ci][cj+1]);
//                    System.out.println("elev " + elev);
                    if(distances[ci][cj+1] > elev){
                        distances[ci][cj+1] = elev;
                    }
//                    System.out.println("down " + distances[ci][cj+1]);
                }
                if(!setMin(distances,visited,size)){
                    done = true;
                }else{ 
                    ci = min_i;
                    cj = min_j;
                }
                step++;
            }
            return distances[ci][cj];
        }
        
        public static boolean setMin(int[][] dist, boolean[][] visited, int size){
            int i,j;
            int min;
            min = MAX;
            min_i = -1;
            min_j = -1;
            for(i = 0; i < size; i++){
                for(j = 0; j < size; j++){
                    if(!visited[i][j] && dist[i][j] < min){
                        min =  dist[i][j];
                        min_i = i;
                        min_j = j;
                    }
                }
            }
            if(min_i < 0 || min_j < 0){
                return false;
            }
            return true;
        }
    
}
