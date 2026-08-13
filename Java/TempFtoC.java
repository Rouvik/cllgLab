import java.util.Scanner;

public class TempFtoC {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter temp in F: ");
		float F = sc.nextFloat();

		System.out.println("Temperature in C: " + ((F - 32) * (5.0 / 9)));
	}
}
