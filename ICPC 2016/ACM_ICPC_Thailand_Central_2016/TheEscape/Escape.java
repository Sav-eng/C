import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Escape {
	public static int mapSize = 50;
	public static int bound = mapSize * mapSize + 1; // fixed number longer than
														// longest path

	public static void main(String[] args) throws IOException {

		int[] shortestPathTo = new int[3]; // stores shortest path to each
											// staircase of current level
		int[] nextPath = new int[3]; // used in update process for
										// shortestPathTo
		BufferedReader stdin = new BufferedReader(new InputStreamReader(
				System.in));
		String line = stdin.readLine();
		int numTestCase = Integer.parseInt(line.trim());

		StringTokenizer numTokens;
		for (int i = 0; i < numTestCase; i++) {
			int[][] paths = new int[mapSize][mapSize];
			for (int j = 0; j < mapSize; j++) {
				for (int k = 0; k < mapSize; k++) {
					paths[j][k] = bound;
				}
			}
			line = stdin.readLine();
			numTokens = new StringTokenizer(line);
			int startx = Integer.parseInt(numTokens.nextToken());
			int starty = Integer.parseInt(numTokens.nextToken());
			int ladderZerox = Integer.parseInt(numTokens.nextToken());
			int ladderZeroy = Integer.parseInt(numTokens.nextToken());
			int ladderOnex = Integer.parseInt(numTokens.nextToken());
			int ladderOney = Integer.parseInt(numTokens.nextToken());
			int ladderTwox = Integer.parseInt(numTokens.nextToken());
			int ladderTwoy = Integer.parseInt(numTokens.nextToken());

			int trapZerox = 0;
			int trapZeroy = 0;
			int trapOnex = 0;
			int trapOney = 0;
			int trapTwox = 0;
			int trapTwoy = 0;

			int numWalls = Integer.parseInt(numTokens.nextToken());
			//System.out.println(numWalls);
			for (int j = 0; j < numWalls; j++) {
				int wallx = Integer.parseInt(numTokens.nextToken());
				int wally = Integer.parseInt(numTokens.nextToken());
				paths[wallx][wally] = -1;
			}

			shortestPathTo[0] = shortLevel(paths, startx, starty, ladderZerox,
					ladderZeroy);
			shortestPathTo[1] = shortLevel(paths, startx, starty, ladderOnex,
					ladderOney);
			shortestPathTo[2] = shortLevel(paths, startx, starty, ladderTwox,
					ladderTwoy);
			//System.out.println("[" + shortestPathTo[0] + " " + shortestPathTo[1] + " " + shortestPathTo[2] + "]");

			// dynamically calculate shortest paths to each ladder on floor 2
			for (int n = 2; n < 27; n++) {
				paths = new int[mapSize][mapSize];
				for (int j = 0; j < mapSize; j++) {
					for (int k = 0; k < mapSize; k++) {
						paths[j][k] = bound;
					}
				}
				line = stdin.readLine();
				numTokens = new StringTokenizer(line);
				trapZerox = Integer.parseInt(numTokens.nextToken());
				trapZeroy = Integer.parseInt(numTokens.nextToken());
				trapOnex = Integer.parseInt(numTokens.nextToken());
				trapOney = Integer.parseInt(numTokens.nextToken());
				trapTwox = Integer.parseInt(numTokens.nextToken());
				trapTwoy = Integer.parseInt(numTokens.nextToken());
				ladderZerox = Integer.parseInt(numTokens.nextToken());
				ladderZeroy = Integer.parseInt(numTokens.nextToken());
				ladderOnex = Integer.parseInt(numTokens.nextToken());
				ladderOney = Integer.parseInt(numTokens.nextToken());
				ladderTwox = Integer.parseInt(numTokens.nextToken());
				ladderTwoy = Integer.parseInt(numTokens.nextToken());

				numWalls = Integer.parseInt(numTokens.nextToken());

				//System.out.println(numWalls);
				for (int j = 0; j < numWalls; j++) {
					int wallx = Integer.parseInt(numTokens.nextToken());
					int wally = Integer.parseInt(numTokens.nextToken());
					paths[wallx][wally] = -1;
				}

				nextPath[0] = Math.min(
						Math.min(
								shortLevel(paths, trapZerox, trapZeroy,
										ladderZerox, ladderZeroy)
										+ shortestPathTo[0],
								shortLevel(paths, trapOnex, trapOney,
										ladderZerox, ladderZeroy)
										+ shortestPathTo[1]),
						shortLevel(paths, trapTwox, trapTwoy, ladderZerox,
								ladderZeroy) + shortestPathTo[2]) + 1;

				nextPath[1] = Math.min(
						Math.min(
								shortLevel(paths, trapZerox, trapZeroy,
										ladderOnex, ladderOney)
										+ shortestPathTo[0],
								shortLevel(paths, trapOnex, trapOney,
										ladderOnex, ladderOney)
										+ shortestPathTo[1]),
						shortLevel(paths, trapTwox, trapTwoy, ladderOnex,
								ladderOney) + shortestPathTo[2]) + 1;

				nextPath[2] = Math.min(
						Math.min(
								shortLevel(paths, trapZerox, trapZeroy,
										ladderTwox, ladderTwoy)
										+ shortestPathTo[0],
								shortLevel(paths, trapOnex, trapOney,
										ladderTwox, ladderTwoy)
										+ shortestPathTo[1]),
						shortLevel(paths, trapTwox, trapTwoy, ladderTwox,
								ladderTwoy) + shortestPathTo[2]) + 1;

				for (int j = 0; j < 3; j++) {
					shortestPathTo[j] = nextPath[j];
				}
				//System.out.println("[" + shortestPathTo[0] + " " + shortestPathTo[1] + " " + shortestPathTo[2] + "]");
			}

			line = stdin.readLine();
			numTokens = new StringTokenizer(line);

			trapZerox = Integer.parseInt(numTokens.nextToken());
			trapZeroy = Integer.parseInt(numTokens.nextToken());
			trapOnex = Integer.parseInt(numTokens.nextToken());
			trapOney = Integer.parseInt(numTokens.nextToken());
			trapTwox = Integer.parseInt(numTokens.nextToken());
			trapTwoy = Integer.parseInt(numTokens.nextToken());
			ladderZerox = Integer.parseInt(numTokens.nextToken());
			ladderZeroy = Integer.parseInt(numTokens.nextToken());

			numWalls = Integer.parseInt(numTokens.nextToken());
			//System.out.println(numWalls);

			for (int j = 0; j < numWalls; j++) {
				int wallx = Integer.parseInt(numTokens.nextToken());
				int wally = Integer.parseInt(numTokens.nextToken());
				paths[wallx][wally] = -1;
			}

			int shortExit = Math.min(
					Math.min(
							shortLevel(paths, trapZerox, trapZeroy,
									ladderZerox, ladderZeroy)
									+ shortestPathTo[0],
							shortLevel(paths, trapOnex, trapOney, ladderZerox,
									ladderZeroy) + shortestPathTo[1]),
					shortLevel(paths, trapTwox, trapTwoy, ladderZerox,
							ladderZeroy) + shortestPathTo[2]) + 1;
			System.out.println(shortExit);
		}

	}

	// length of shortest path from (ox, oy) to (dx, dy) on same dungeon level
	public static int shortLevel(int[][] level, int ox, int oy, int dx, int dy) {
		int result = 0;
		int[][] workingLevel = new int[mapSize][mapSize];
		
		for(int i = 0 ; i < mapSize ; i++){
			for (int j = 0 ; j < mapSize ; j++){
				workingLevel[i][j] = level[i][j];
			}
		}
		
		boolean[][] known = new boolean[mapSize][mapSize];
		boolean[][] current = new boolean[mapSize][mapSize];
		workingLevel[ox][oy] = 0;
		known[ox][oy] = true;
		for (int i = 0; i < mapSize; i++) {
			for (int j = 0; j < mapSize; j++) {
				if (level[i][j] == -1) {
					known[i][j] = true;
				}
			}
		}
		
		boolean cont = true;
		while (cont) {
			//System.out.println("update0");
			current = new boolean[mapSize][mapSize];
			for (int i = 0; i < mapSize; i++) {
				for (int j = 0; j < mapSize; j++) {
					if (known[i][j] && workingLevel[i][j] != -1) {
						//System.out.println("update1");
						for (int k = -1; k < 2; k++) {
							for (int l = -1; l < 2; l++) {
								if(i + k >= 0 && j + l >= 0 && i + k < mapSize && j + l < mapSize){
								if (!known[i + k][j + l]
										&& workingLevel[i + k][j + l] != -1) {
									workingLevel[i + k][j + l] = Math.min(
											workingLevel[i + k][j+l], workingLevel[i][j] + 1);
									current[i + k][j + l] = true;
									//System.out.println(workingLevel[i+k][j+l]);
								}
								}
							}
						}
					}
				}
			}
			cont = false;
			for(int i = 0 ; i < mapSize; i++){
				for(int j = 0 ; j < mapSize ; j++){
					if(current[i][j] == true){
						known[i][j] = true;
						cont = true;
					}
				}
			}
		}
		result = workingLevel[dx][dy];
		return result;
	}



}
