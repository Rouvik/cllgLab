public class ConstOverload
{
	ConstOverload() {}

	ConstOverload(int a)
	{
		System.out.println("Called int constructor: " + a);
	}

	ConstOverload(String a)
	{
		System.out.println("Called String constructor: " + a);
	}

	ConstOverload(double a)
	{
		System.out.println("Called double constructor: " + a);
	}

	public static void main(String args[])
	{
		new ConstOverload(5);
		new ConstOverload(5.2);
		new ConstOverload("5");
	}
}
