package <missing>;

public class GlobalMembers
{
	public static void Main()
	{
		int[] num = new int[300];
		char c;
		int i;
		int j;
		int temp;
		for (i = 0;;i++)
		{
			String tempVar = ConsoleInput.scanfRead();
			if (tempVar != null)
			{
				num[i] = Integer.parseInt(tempVar);
			}
			String tempVar2 = ConsoleInput.scanfRead(null, 1);
			if (tempVar2 != null)
			{
				c = tempVar2.charAt(0);
			}
			if (c != ',')
			{
				break;
			}
		}
		int n = i + 1;
		for (i = 1;i <= n - 1;i++)
		{
			for (j = n - 1;j >= i;j--)
			{
				if (num[j] > num[j - 1])
				{
					temp = num[j];
					num[j] = num[j - 1];
					num[j - 1] = temp;
				}
			}
		}
		int max = num[0];
		int judge = 1;
		for (i = 0;i < n;i++)
		{
			if (num[i] < max)
			{
				judge = 0;
				System.out.printf("%d\n",num[i]);
				break;
			}
		}
		if (judge == 1)
		{
			System.out.print("No\n");
		}
	}
}

