public class Main
{
	public static void main(String args[])
	{
		Point a = new Point(5, 2),
		      b = new Point(6, 7);

		System.out.println(Point.dist(a, b));
	}
}

class Point
{
	int x, y;

	Point(int x, int y)
	{
		this.x = x;
		this.y = y;
	}

	static double dist(Point a, Point b)
	{
		return Math.sqrt(Math.pow(a.x - b.x, 2) + Math.pow(a.y - b.y, 2));
	}
}
