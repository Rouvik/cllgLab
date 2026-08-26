import java.util.Scanner;

class Box {
	int w, h, d;

	Box() {
		w = 0;
		h = 0;
		d = 0;
	};

	Box(int _w, int _h, int _d) {
		w = _w;
		h = _h;
		d = _d;
	}

	void setData(int _w, int _h, int _d) {
		w = _w;
		h = _h;
		d = _d;
	}

	int volume() {
		return w * h * d;
	}
}

public class BoxMainConst {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter dimentions of rect: ");
		Box rect = new Box(sc.nextInt(), sc.nextInt(), sc.nextInt());

		Box sq = new Box();
		System.out.print("Enter side of sq: ");
		int s = sc.nextInt();
		sq.setData(s, s, s);

		System.out.println(
				(rect.volume() > sq.volume() ? "Rect" : "Square") +
						" box is larger");
	}
}
