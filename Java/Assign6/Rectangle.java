import java.util.Scanner;

public class Rectangle extends TwoDShape
{
	public void area()
	{
		System.out.println("Area: " + (dim1 * dim2));
	}

	Rectangle(int d1, int d2)
	{
		dim1 = d1; dim2 = d2;
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter rect 1 dims: ");
		Rectangle r1 = new Rectangle(sc.nextInt(), sc.nextInt());
		r1.area();

		System.out.print("Enter rect 2 dims: ");
		Rectangle r2 = new Rectangle(sc.nextInt(), sc.nextInt());
		r2.area();
	}
}

abstract class TwoDShape
{
	int dim1, dim2;
	abstract void area();
}

