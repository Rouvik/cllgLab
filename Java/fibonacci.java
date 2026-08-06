public class fibonacci {
    public static void main(String[] args) {
        long a = 1, b = 0, c = 0;

        for (int i = 0; i < 50; i++) {
            c = a + b;
            a = b;
            b = c;

            System.out.println(c);
        }
    }
}
