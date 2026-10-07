public class Override extends Base
{
	public void foo()
	{
		System.out.println("Called from Override");
	}

	public static void main(String args[])
	{
		new Override().foo();
		new Base().foo();
	}
}

class Base
{
	public void foo()
	{
		System.out.println("Called from base");
	}
}
