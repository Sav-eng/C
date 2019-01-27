
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Collections;
import java.util.HashMap;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author apirakhoonlor
 */
public class Organization {
    static class ONode implements Comparable{
        int ix;
        int iy;
        long dist;
        public ONode(ONode tN){
            ix = tN.ix;
            iy = tN.iy;
            dist = tN.dist;
        }
        public ONode(int is, int ie, long di){
            ix = is;
            iy = ie;
            dist = di;
        }
        
        public int compareTo(Object target){
            ONode tNode = (ONode) target;
            return Long.compare(dist, tNode.dist);
        }
        
        
        public String toString(){
            String output = "((" + ix + "),("+ iy+"),dist="+dist+")";
            return output;
        }
    }    
    public static long[][] distances;
    
    public static void main(String[] args) throws IOException {        
         BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in)); 
         String line = stdin.readLine(); 
         int numTestCase = Integer.parseInt(line.trim());		 
         StringTokenizer numTokens;
         int[][] points;
         int N, K;
         for(int i=0 ; i < numTestCase ; i++){                     
             line = stdin.readLine();
//             System.out.println(line);
             numTokens = new StringTokenizer(line, " \t\r\n");
             N = Integer.parseInt(numTokens.nextToken());
             K = Integer.parseInt(numTokens.nextToken());
             points = new int[N][2];
             for(int j = 0; j < N; j++){
                 line = stdin.readLine();
                 numTokens = new StringTokenizer(line, " \t\r\n");
                 points[j][0] = Integer.parseInt(numTokens.nextToken());
                 points[j][1] = Integer.parseInt(numTokens.nextToken());
             }
             System.out.println(solve(N, points, K));
         }
    }
    
    public static long solve(int N, int[][] points, int k){
        int i,j,id;
        distances = new long[N][N];
        id = 0;
        long dist;
        boolean[] S = new boolean[N];
        for(i = 0; i < N-1; i++){
            S[i] = false;
            for(j = i+1; j < N; j++){
                dist = Math.abs(points[i][0]- points[j][0]) + Math.abs(points[i][1] - points[j][1]);
                distances[i][j] = dist;
                distances[j][i] = dist;
            }
        }
        S[i] = false;
        S[0] = true;
        PriorityQueue<ONode> tree = new PriorityQueue<>();
        PriorityQueue<ONode> MST = new PriorityQueue<>();
        for(i = 1; i < N; i++){
            tree.add(new ONode(0,i,distances[0][i]));
        }
        int c = 1;
        ONode currNode, tarNode;
        while(!tree.isEmpty() && !isDone(S,N)){
            currNode = tree.remove();
            if(!S[currNode.iy]){
                c++;
                S[currNode.iy] = true;
                MST.add(new ONode(currNode));
                for(i = 1; i < N; i++){
                    if(!S[i]){
                        tree.add(new ONode(currNode.iy, i, distances[currNode.iy][i]));
                    }
                }
            }
        }
//        System.out.println("MST size = " + MST.size()+ " out of N = " + N + " count = " + c);
        for(i = 0; i < N-k; i++){
            MST.remove();
        }
        return MST.peek().dist;
    }
    
    public static boolean isDone(boolean[] S, int N){
        int sdex;
        for(sdex = 0; sdex < N; sdex++){
            if(!S[sdex]){
                return false;
            }
        }
        return true;
    }    
}
