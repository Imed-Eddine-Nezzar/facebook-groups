import java.util.Scanner;
class Matrix {
    public static void main(String[] args) {
        int N;
        Scanner stdin = new Scanner(System.in);
        do {
            System.out.print("Enter the hight of Matrix: ");
            N = stdin.nextInt();
        } while (N % 2 == 0);

        // filling the Matrix
        char[][] A = new char[N][N];
        for (int i= 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j || i == N/2 || j == N-i-1 || j == N/2) A[i][j] = '*';
                else A[i][j] = ' ';
            }
        }

        // printing the result
        for (int i  = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                System.out.printf("%c ", A[i][j]);
            }
            System.out.print("\n");
        }
    }
}
