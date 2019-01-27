/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.*;
import java.io.*;

/**
 *
 * @author apirakhoonlor
 */
public class MadMax {
    static class MMNode implements Comparable{
        int start;
        int end;
        int cost;
        public MMNode(int s, int e, int c){
            cost = c;
            start = s;
            end = e;
        }
        
        public int compareTo(Object target){
            MMNode tNode = (MMNode) target;
            return Integer.compare(cost, tNode.cost);
        }
        
        public String toString(){
            String output = start + ", " + end + ": " + cost;
            return output;
        }
    }
    
    int[][] c_graph;
    boolean[] S;
    int N;    
    PriorityQueue<MMNode> tree;
    int MAX_C = 600000;
    
    public void init(int gsize){
        N = gsize;
        S = new boolean[gsize];
        int gdex, rdex, cdex;
        for(gdex = 0; gdex < gsize; gdex++){
            S[gdex] = false;
        }
        c_graph = new int[N][N];
        for(rdex = 0; rdex < gsize; rdex++){
            for(cdex = 0; cdex < gsize; cdex++){
                c_graph[rdex][cdex] = MAX_C;
            }
        }
    }
    
    public void construct(){
        long totalCost = 0;
        MMNode currNode, tarNode;
        tree = new PriorityQueue<>();
        S[0] = true;
        int sdex, min_value, min_dex;
        for(sdex = 1; sdex < N; sdex++){
            if(c_graph[0][sdex] < MAX_C){
                tree.add(new MMNode(0, sdex, c_graph[0][sdex]));
            }
        }
        int c = 1;
        while(!tree.isEmpty() && !isDone()){
            currNode = tree.remove();
            if(!S[currNode.end]){
                c++;
                totalCost += (long) currNode.cost;
                S[currNode.end] = true;
                for(sdex = 0; sdex < N; sdex++){
                    if(!S[sdex]){
                        if(c_graph[currNode.end][sdex] < MAX_C){
                            tree.add(new MMNode(currNode.end, sdex, c_graph[currNode.end][sdex]));
                        }
                    }
                }
            }
        }
        System.out.println(totalCost);
    }
    
    public void printBool(){
        int sdex;
        for(sdex = 0; sdex < N; sdex++){
            System.out.print(sdex + ":" + S[sdex]);
        }
        System.out.println();
    }
    
    public boolean isDone(){
        int sdex;
        for(sdex = 0; sdex < N; sdex++){
            if(!S[sdex]){
                return false;
            }
        }
        return true;
    }    
    
  public static void main (String arg[])throws IOException {
    BufferedReader br = new BufferedReader (
			   new InputStreamReader(System.in));
    String line = br.readLine();
    StringTokenizer tokens;
    int numTestCase = Integer.parseInt(line);
    int ndex, cNum, rNum, ldex, rdex, cdex;
    String riskSt, costSt;
    MadMax flowControl = new MadMax();
    for(ndex = 0; ndex < numTestCase; ndex++){
        line = br.readLine();
        tokens = new StringTokenizer(line, " \t\r\n");
        cNum = Integer.parseInt(tokens.nextToken());
        rNum = Integer.parseInt(tokens.nextToken());
        flowControl.init(cNum);
        for(ldex = 0; ldex < rNum; ldex++){
            line = br.readLine();
            tokens = new StringTokenizer(line, " \t\r\n");
            rdex = Integer.parseInt(tokens.nextToken())-1;
            cdex = Integer.parseInt(tokens.nextToken())-1;
            costSt = tokens.nextToken();
            flowControl.c_graph[rdex][cdex] = Integer.parseInt(costSt);                
            flowControl.c_graph[cdex][rdex] = Integer.parseInt(costSt);                
        }
        flowControl.construct();
    }
  }
  
  
  
}
