public class Overload
{
	void print(int a)
	{
		System.out.println("Printing an integer: " + a);
	}

	void print(String a)
	{
		System.out.println("Printing a String: " + a);
	}

	void print(double a)
	{
		System.out.println("Printing a double: " + a);
	}

	public static void main(String args[])
	{
		Overload o = new Overload();
		o.print(5);
		o.print(5.23);
		o.print("5");
	}
}
