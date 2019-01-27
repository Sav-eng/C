import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Maze {

	public static void main(String[] args) throws IOException {
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in)); 
		 String line = stdin.readLine(); 
		 int numTestCase = Integer.parseInt(line.trim());
		 //System.out.println("numTestCase: " + numTestCase);
		 StringTokenizer numTokens;	
		 for(int i = 0 ; i< numTestCase ; i++){
			 line = stdin.readLine();
			 numTokens = new StringTokenizer(line);
			 int size = Integer.parseInt(numTokens.nextToken());
			 int start = Integer.parseInt(numTokens.nextToken());
			 int exit = Integer.parseInt(numTokens.nextToken());
			 //System.out.println("size: " + size + " " + "start: " + start + " " + "exit: " + exit);
			boolean[][] matrix = new boolean[size][size];
			line = stdin.readLine();
			numTokens = new StringTokenizer(line);
			Integer.parseInt(numTokens.nextToken());
			 while(numTokens.hasMoreTokens()){
				 int v1 = Integer.parseInt(numTokens.nextToken());
				 int v2 = Integer.parseInt(numTokens.nextToken());				 
				 //System.out.println("v1 = " + v1 + " v2 = " + v2);
				 matrix[v1][v2] = true;
			 }
			 boolean[] visited = new boolean[size];	
			 explore(matrix, visited, start, size);
			 if(visited[exit] == true){
				 System.out.println("yes");
			 }
			 else System.out.println("no");
			}	
	}
	
	public static void explore(boolean[][] adjacency, boolean[] searched, int origin, int numRooms){
		 searched[origin] = true;
		 for(int i=0 ; i < numRooms ; i ++){
			 boolean canReach = adjacency[origin][i];
			 if(canReach && !searched[i]){
				 explore(adjacency, searched, i, numRooms);
			 }
		 }
	 }
}
