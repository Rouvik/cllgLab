import java.util.Scanner;

public class Palindrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        int t = n, r = 0;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            r = r * 10 + d;
        }

        System.out.println(t + " is " + (t == r ? "palindrome" : "not palindrome"));
    }
}
