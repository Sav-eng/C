import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class LonelyRobots {

	public static void main(String[] args) throws IOException {
		BufferedReader stdin = new BufferedReader(new InputStreamReader(
				System.in));
		String line = stdin.readLine();
		int numTestCase = Integer.parseInt(line.trim());
		StringTokenizer numTokens;
		for (int i = 0; i < numTestCase; i++) {
			line = stdin.readLine();
			numTokens = new StringTokenizer(line);
			int maxChanges = Integer.parseInt(numTokens.nextToken());

			line = stdin.readLine();
			numTokens = new StringTokenizer(line);

			int a = Integer.parseInt(numTokens.nextToken());
			char[] codeA = new char[a];
			for (int j = 0; j < a; j++) {
				codeA[j] = numTokens.nextToken().charAt(0);
			}

			line = stdin.readLine();
			numTokens = new StringTokenizer(line);

			int b = Integer.parseInt(numTokens.nextToken());
			char[] codeB = new char[b];
			for (int j = 0; j < b; j++) {
				codeB[j] = numTokens.nextToken().charAt(0);
			}
			int distance = editDist(codeA, a, codeB, b);
			//System.out.println(distance);
			if(distance <= maxChanges){
				System.out.println("yes");
			}
			else System.out.println("no");
		}

	}

	public static int editDist(char[] A, int a, char[] B, int b) {
		int result = 0;
		int[][] matrix = new int[a+1][b+1];
		for(int i = 0 ; i < a+1 ; i++){
			matrix[i][0] = i; 
		}
		for(int j = 0 ; j < b+1 ; j++){
			matrix[0][j] = j; 
		}
		 for(int i = 1 ; i < a+1 ; i++){
			 for(int j = 1 ; j < b+1 ; j++){
				 if(A[i-1]!=B[j-1]){
					 matrix[i][j] = Math.min(Math.min(matrix[i-1][j] + 1, 
							 matrix[i][j-1] + 1), 
							 matrix[i-1][j-1] + 1);
				 }
				 if(A[i-1]==B[j-1]){
					 matrix[i][j] = Math.min(Math.min(matrix[i-1][j] + 1, 
							 matrix[i][j-1] + 1), 
							 matrix[i-1][j-1]);
				 }
			 }
		 }
		 result = matrix[a][b];
		return result;
	}
}
