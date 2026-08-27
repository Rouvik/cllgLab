public class MethodObject
{
	String name;

	MethodObject() { name = ""; }

	MethodObject(String n)
	{
		name = n;
	}

	MethodObject callme(String name)
	{
		return new MethodObject("callme " + name);
	}

	void show()
	{
		System.out.println(name);
	}

	public static void main(String args[])
	{
		new MethodObject().callme("maybe").show();
	}
}
