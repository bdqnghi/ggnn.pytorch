package <missing>;

public class GlobalMembers
{
	public static int m;
	public static int n;
	public static int f(int a,int b) //????????????????????????????2??????
	{
		while (a >= 2 * b)
		{
			a = a / 2;
		}
		while (b >= 2 * a)
		{
			b = b / 2; //???????a?b??????????????????????????ab???????
		}
		if (a > b) //??a??b??????????ab???????a?b?????
		{
			while (a != b && a / 2 != b) //?????a?a/2????b
			{
				a = a / 2;
				b = b / 2;
			}
			return b;
		}
		if (b > a)
		{
			while (a != b && a != b / 2) //??
			{
				a = a / 2;
				b = b / 2;
			}
			return a;
		}
		if (a == b)
		{
			return a;
		}

	}
	public static int Main()
	{
		m = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));
		n = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));
		System.out.print(f(m, n));
		System.out.print("\n");
		return 0;
	}

}

