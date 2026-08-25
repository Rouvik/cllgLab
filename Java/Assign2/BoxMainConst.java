import java.util.Scanner;

class Box {
	int w, h, d;

	Box(int w, int h, int d)
	{
		this.w = w;
		this.h = h;
		this.d = d;
	}

	int volume() { return w * h * d; }
}

public class BoxMainConst {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter dimentions of rect: ");
		Box rect = new Box(sc.nextInt(), sc.nextInt(), sc.nextInt());

		System.out.print("Enter dimentions of sq: ");
		Box sq = new Box(sc.nextInt(), sc.nextInt(), sc.nextInt());

		System.out.println(
			(rect.volume() > sq.volume() ? "Rect" : "Square") +
			" box is larger"
		);
	}
}
