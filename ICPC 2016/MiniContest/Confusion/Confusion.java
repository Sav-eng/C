import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class Confusion {
	public static ArrayList<int[]> formula;
	public static ArrayList<int[]> working;
	
	public static void main(String[] args) throws IOException {
		BufferedReader stdin = new BufferedReader(new InputStreamReader(
				System.in));
		String line = stdin.readLine();
		int numTestCase = Integer.parseInt(line.trim());
		StringTokenizer numTokens;
		for (int i = 0; i < numTestCase; i++) {
			line = stdin.readLine();
			numTokens = new StringTokenizer(line);
			int numC = Integer.parseInt(numTokens.nextToken());
			int numP = Integer.parseInt(numTokens.nextToken());
			 formula = new ArrayList<int[]>(0);
			for(int k = 0 ; k < numC ; k++){
				int[] clause = new int[2];
				formula.add(clause);
			}
			//System.out.println("numC =" + numC);
			for(int j = 0 ; j < numC ; j++){				
				int[] clause = new int[2];
				int literal0 = Integer.parseInt(numTokens.nextToken());
				int literal1 = Integer.parseInt(numTokens.nextToken());
				clause[0] = literal0;
				clause[1] = literal1;				
				formula.set(j,clause);
			}			
			if(UP()){
				System.out.println("yes");
			}
			else System.out.println("no");
		}

	}
	
	public static boolean UP(){
		boolean result = true;		
		while(!formula.isEmpty()){
		working = (ArrayList<int[]>) formula.clone();
		int literal = working.get(0)[0];
		if(literal == 0){
			literal = working.get(0)[1];
		}
		UPL(literal);
		if(!satisfiable(working)){
			working = (ArrayList<int[]>) formula.clone();
			UPL(-literal);
			if(!satisfiable(working)){
				result = false;
				break;
			}
		}
		Iterator<int[]> iter = formula.iterator();
		formula = working;
		}
		return result;
	}
	
	public static boolean satisfiable(ArrayList<int[]> test){
		boolean result = true;
		Iterator<int[]> iter = test.iterator();
		while(iter.hasNext()){
			int[] clause = iter.next();
			if(clause[0] == 0 && clause[1] == 0) {
				result = false;
				break;
			}
		}
		return result;
	}
	
	
	public static void UPL(int literal){
		ArrayDeque<Integer> queue = new ArrayDeque<Integer>();
		queue.add(literal);
		
		while(!queue.isEmpty()){
		//System.out.println(queue);
		ArrayList<int[]> scratch = new ArrayList<int[]>();
		
		//I have to do this because .copy() just gives a shallow copy and we need to reset the clause values
		Iterator<int[]> preScan = working.iterator();
		while(preScan.hasNext()){
			int[] clause = preScan.next();
			int[]scratchClause = new int[2];
			scratchClause[0] = clause[0];
			scratchClause[1] = clause[1];
			scratch.add(scratchClause);
			//System.out.print("(" + clause[0] + "," + clause[1] + ")");
		}
		//System.out.println();
		
		int workLit = queue.pop();
		Iterator<int[]> iter = working.iterator();	
		int removeCount = 0;
		int position = 0;
		while(iter.hasNext()){
			int[] clause = iter.next();
			if(clause[0] == workLit || clause[1] == workLit){
				scratch.remove(position - removeCount);
				removeCount++;
			}
			else {
				if(clause[0] == -workLit){ //mistake is probably here. must edit clause in scratch, not working
					scratch.get(position - removeCount)[0] = 0;
					if(clause[1]!= 0){
					queue.add(clause[1]);}
				}
				if(clause[1] == -workLit){
					scratch.get(position - removeCount)[1] = 0;
					if(clause[0] != 0) {
					queue.add(clause[0]);}
				}
				
			}
			position++;
		}
		working = scratch;			
	}
	}

}
