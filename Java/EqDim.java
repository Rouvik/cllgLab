public class EqDim
{
	public static void main(String args[])
	{
		Box b1 = new Box(5, 4, 3);
		Box b2 = new Box(4, 5, 6);
		Box b1c = new Box(b1);

		if(b1.equals(b2))
		{
			System.out.println("b1 == b2");
		}

		if(b1.equals(b1c))
		{
			System.out.println("b1 == b1c");
		}
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

	Box(Box obj)
	{
		this.w = obj.w;
		this.h = obj.h;
		this.d = obj.d;
	}

	boolean equals(Box obj)
	{
		return w == obj.w && h == obj.h && d == obj.d;
	}
}
