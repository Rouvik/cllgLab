public class Main
{
	public static void main(String args[])
	{
		Complex a = new Complex(5, 2);

		System.out.println(
			a.add(new Complex(1, 1))
			 .subtract(new Complex(1, 3))
			 .multiply(new Complex(2, 5))
			 .complement()
		);

		System.out.printf("%.2f\n", a.modulus());

		System.out.println("Complex Count: " + Complex.getCount());
	}
}

class Complex
{
	private static int count = 0;

	float x, y;

	Complex(float x, float y)
	{
		this.x = x;
		this.y = y;

		count++;
	}

	public String toString()
	{
		return String.format("%.2f%+.2fi", x, y);
	}

	static int getCount()
	{
		return count;
	}

	Complex add(Complex b)
	{
		return new Complex(x + b.x, y + b.y);
	}

	Complex subtract(Complex b)
	{
		return new Complex(x - b.x, y - b.y);
	}

	Complex multiply(Complex b)
	{
		return new Complex(x * b.x - y * b.y, x * b.y + b.x * y);
	}

	double modulus()
	{
		return Math.sqrt(x * x + y * y);
	}

	Complex complement()
	{
		return new Complex(x, -y);
	}
}
