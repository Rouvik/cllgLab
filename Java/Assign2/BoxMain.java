import java.util.Scanner;

class Box {
	int w, h, d;

	void setData(int w, int h, int d)
	{
		this.w = w;
		this.h = h;
		this.d = d;
	}

	int volume() { return w * h * d; }
}

public class BoxMain {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);

		Box rect = new Box();
		System.out.print("Enter dimentions of rect: ");
		rect.setData(sc.nextInt(), sc.nextInt(), sc.nextInt());

		Box sq = new Box();
		System.out.print("Enter dimentions of sq: ");
		sq.setData(sc.nextInt(), sc.nextInt(), sc.nextInt());

		System.out.println(
			(rect.volume() > sq.volume() ? "Rect" : "Square") +
			" box is larger"
		);
	}
}
