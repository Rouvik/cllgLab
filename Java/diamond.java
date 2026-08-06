import java.util.Scanner;

public class diamond {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter height: ");
        int n = sc.nextInt();

        for (int i = 1; i <= 2 * n - 1; i++) {
            for (int j = 0; j < (i < n ? n - i : i - n); j++) {
                System.out.print(' ');
            }

            for (int j = 0; j < (i < n ? i : 2 * n - i); j++) {
                System.out.print("* ");
            }
            
            System.out.println();
        }
    }
}
