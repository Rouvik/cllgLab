import java.util.Scanner;

public class Prime {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter n: ");
		int n = sc.nextInt();

		for(int i = 2; i < n; i++) {
			if(n % i == 0) {
				System.out.println("Not prime");
				return;
			}
		}

		System.out.println("Prime");
	}
}
