public class Overload
{
	public void foo()
	{
		System.out.println("Override");
	}

	public void foo(int x)
	{
		System.out.println("Overload");
	}

	public static void main(String args[])
	{
		new Overload().foo();
		new Overload().foo(5);
		new Base().foo();
	}
}

class Base
{
	void foo()
	{
		System.out.println("Base");
	}
}
