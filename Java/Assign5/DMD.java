public class DMD extends Base
{
	void foo()
	{
		System.out.println("Child foo");
	}

	public static void main(String args[])
	{
		Base b = new Base();
		b.foo();

		b = new DMD();
		b.foo();
	}
}

class Base
{
	void foo()
	{
		System.out.println("Parent foo");
	}
}
