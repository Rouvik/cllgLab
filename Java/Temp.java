import java.util.Scanner;

public class Temp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Temperature in C: ");
        float C = sc.nextFloat();

        System.out.println("Temperature in F: " + (C * (9.0 / 5) + 32));
    }
}
