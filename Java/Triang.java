import java.util.Scanner;

public class Triang {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter 3 sides: ");
		int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();

		float p = a + b + c, s = p / 2.0f;
		System.out.print(
			"Perimeter: " + p +
			"\nArea: " + Math.sqrt(s * (s - a) * (s - b) * (s - c))
		);
	}
}
