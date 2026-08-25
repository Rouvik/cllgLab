public class BoxParam
{
	public static void main(String args[])
	{
		Box b1 = new Box(5, 4, 3);
		Box b2 = new Box(5);

		b1.volume();
		b2.volume();
	}
}

class Box
{
	int w, h, d;

	Box(int w, int h, int d)
	{
		this.w = w;
		this.h = h;
		this.d = d;
	}

	Box(int d)
	{
		this.w = d;
		this.h = d;
		this.d = d;
	}

	void volume()
	{
		System.out.println("Volume: " + (w * h * d));
	}
}
