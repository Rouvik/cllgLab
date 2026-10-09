public class Rectangle extends TwoDShape
{
	public void area()
	{
		return dim1 * dim2;
	}
}

abstract class TwoDShape
{
	int dim1, dim2;
	abstract void area();
}
