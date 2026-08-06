public class armstrong {
    public static void main(String[] args) {
        for (int i = 1; i <= 1000; i++) {
            int t = i, r = 0;
            while (t > 0) {
                int d = t % 10;
                r += d * d * d;
                t /= 10;
            }

            if (r == i) {
                System.out.println(i);
            }
        }
    }
}
