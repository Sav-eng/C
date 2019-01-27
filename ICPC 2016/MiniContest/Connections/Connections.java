import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Connections {

	public static int count;
	public static boolean[] visited;
	public static int[] postData;
	public static int[] components;
	
	public static void main(String[] args) throws IOException {		
		BufferedReader stdin = new BufferedReader(new InputStreamReader(
				System.in));
		String line = stdin.readLine();
		int numTestCase = Integer.parseInt(line.trim());
		// System.out.println("numTestCase: " + numTestCase);
		StringTokenizer numTokens;
		for (int i = 0; i < numTestCase; i++) {
			count = 0;
			line = stdin.readLine();
			numTokens = new StringTokenizer(line);
			int size = Integer.parseInt(numTokens.nextToken());		
			//System.out.println("size: " + size);
			boolean[][] graph = new boolean[size][size];
			boolean[][] graphR = new boolean[size][size];
			line = stdin.readLine();
			numTokens = new StringTokenizer(line);
			Integer.parseInt(numTokens.nextToken());
			while (numTokens.hasMoreTokens()) {
				int v1 = Integer.parseInt(numTokens.nextToken());
				int v2 = Integer.parseInt(numTokens.nextToken());
				// System.out.println("v1 = " + v1 + " v2 = " + v2);
				graph[v1][v2] = true;
				graphR[v2][v1] = true;
			}
			visited = new boolean[size];
			postData = new int[size];
			findPosts(graphR, size);
			/*System.out.println("posts");
			for (int j = 0 ; j < size ; j++){
				System.out.println(postData[j]);
			}*/
			visited = new boolean[size];
			components = new int[size]; 
			getComponents(graph, size);
			/*System.out.println("components");
			for (int j = 0 ; j < size ; j++){
				System.out.println(components[j]);
			}
			System.out.println("answer");*/
			System.out.println(countComponents( size));
		}
	}

	public static int countComponents(int numNodes) {
		int result = 1;
		for (int i = 0; i < numNodes; i++) {
			if (components[i] > result) {
				result = components[i];
			}
		}
		return result;
	}

	public static void getComponents(boolean[][] adjacency, int numNodes) {
		int componentNumber = 1;
		while (!allVisited(numNodes)) {			
			int start = getOrigin(numNodes);
			//System.out.println("origin:" + start);
			exploreLabel(adjacency, componentNumber,
					start, numNodes);
			componentNumber++;
		}
	}

	public static boolean allVisited(int numNodes) {
		boolean result = true;
		for (int i = 0; i < numNodes; i++) {
			if (!visited[i]) {
				result = false;
				break;
			}
		}
		return result;

	}

	public static void exploreLabel(boolean[][] adjacency, int compN, 
			int origin, int numNodes) {
		visited[origin] = true;
		components[origin] = compN;
		postData[origin] = 0;
		for (int i = 0; i < numNodes; i++) {
			boolean canReach = adjacency[origin][i];
			if (canReach && !visited[i]) {
				exploreLabel(adjacency, compN, i,
						numNodes);
			}
		}
	}

	public static int getOrigin(int numNodes) {
		int max = 0;
		int newOrigin = 0;
		for (int i = 0; i < numNodes; i++) {
			if (postData[i] > max) {
				newOrigin = i;
				max = postData[i];
			}
		}
		return newOrigin;
	}

	public static void findPosts(boolean[][] adjacency, int numNodes) {
		for (int i = 0; i < numNodes; i++) {
			if (!visited[i]) {
				exploreCount(adjacency, i, numNodes);
			}
		}
	}

	public static void exploreCount(boolean[][] adjacency, 
			int origin, int numNodes) {
		count++;
		//System.out.println(count);
		visited[origin] = true;				
		for (int i = 0; i < numNodes; i++) {
			boolean canReach = adjacency[origin][i];
			if (canReach && !visited[i]) {
				exploreCount(adjacency, i, numNodes);
			}
		}
		count++;
		postData[origin] = count;
		
	}

}
