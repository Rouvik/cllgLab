public class AllConst
{
	public static void main(String args[])
	{
		Box b1 = new Box();
		Box b2 = new Box(5, 3, 2);
		Box b3 = new Box(b2);
	}
}

class Box
{
	int w, h, d;

	Box()
	{
		System.out.println("Default constructor called");
		w = h = d = 0;
	}

	Box(int _w, int _h, int _d)
	{
		System.out.println("Parameterized constructor called");
		w = _w;
		h = _h;
		d = _d;
	}

	Box(Box b)
	{
		System.out.println("Copy constructor called");
		this.w = b.w;
		this.h = b.h;
		this.d = b.d;
	}
}
