import java.util.Scanner;

public class RepStr {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter count: ");
        int count = sc.nextInt();

        System.out.print("Enter word: ");
        String word = sc.next();

        for (int i = 0; i < count; i++) {
            System.out.print(word + ' ');
        }
    }
}
