import java.util.Scanner;

/**
 * ACM Local 2016
 * @author Pinyo Taeprasartsit
 */
class Pair {
    int row, col;

    Pair(int row, int col) {
        this.row = row;
        this.col = col;
    }
}

public class CyclicTriangleNumber {
    Scanner scan = new Scanner(System.in);
    int N;

    int[] precomputeNumberOfElements(int N) {
        int maxLayer = (N + 2) / 3;
        int[] count = new int[maxLayer];
        count[0] = 1;
        for (int i = 1; i < maxLayer; ++i) {
            count[i] = (count[i - 1] + ((N - (3 * i) + 2) * 3)) % 10;
        }
        return count;
    }

    int distanceFromTop(int row, int col) {
        return row;
    }

    int distanceFromRight(int row, int col) {
        return (N - 1) - col;
    }

    int distanceFromDiagonal(int row, int col) {
        return (col - row);
    }

    Pair getTopStartPoint(int layer) {
        return new Pair(layer, layer * 2);
    }

    Pair getRightStartPoint(int layer) {
        return new Pair(layer, N - 1 - layer);
    }

    Pair getDiagStartPoint(int layer) {
        return new Pair(N - 1 - (2 * layer), N - 1 - layer);
    }

    void solve() {
        N = scan.nextInt();
        final int Q = scan.nextInt();
        int[] count = precomputeNumberOfElements(N);
        for (int i = 0; i < Q; ++i) {
            int row = scan.nextInt();
            int col = scan.nextInt();
            int topDistance = distanceFromTop(row, col);
            int rightDistance = distanceFromRight(row, col);
            int diagDistance = distanceFromDiagonal(row, col);
            int layer = Math.min(topDistance, Math.min(rightDistance, diagDistance));
            
            int base = count[layer];
            int size = N - (3 * layer) - 1;
            if (topDistance <= rightDistance && topDistance <= diagDistance) {
                Pair p = getTopStartPoint(layer);
                System.out.println((base + col - p.col) % 10);
            } else if (rightDistance <= diagDistance) {
                Pair p = getRightStartPoint(layer);
                System.out.println((base + row - p.row + size) % 10);
            } else {
                Pair p = getDiagStartPoint(layer);
                System.out.println((base + p.row - row + 2 * size) % 10);
            }
        }
    }
    
    void process() {
        int T = scan.nextInt();
        for(int i = 0; i < T; ++i) {
            solve();
        }
    }

    public static void main(String[] args) {
        (new CyclicTriangleNumber()).process();
    }
}

/*
2
12 5
7 8
0 0
11 11
9 10
5 6
1000000 6
7000 8000
5212 6824
700000 999999
5000 72913
900000 955555
8775 57412

2 
1 
3 
0 
4

8 
0 
0 
4 
8 
3
*/