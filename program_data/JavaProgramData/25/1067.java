package <missing>;

public class GlobalMembers
{
	public static int Main()
	{
		int n;
		n = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));
		System.out.print("\n");
		int[] num = new int[1001];
		for (int i = 0;i < 1001;i++)
		{
			num[i] = 0;
		}
		num[0] = 1; //???????1
		for (int i = 0;i < n;i++)
		{ //??n??????
		   for (int j = 0;j < 1000;j++)
		   { //?????????
			  num[j] = num[j] + num[j];
		   }
		   for (int j = 0;j < 1000;j++)
		   { //??????????10??????
			  if (num[j] >= 10)
			  {
				 num[j + 1] = num[j + 1] + 1;
				 num[j] = num[j] - 10;
			  }
		   }
		}
		int k = 1000;
		while (num[k] == 0)
		{
			k--; //???????0???
		}
		for (int i = k;i >= 0;i--) //??????
		{
			System.out.print(num[i]);
		}
		System.out.print("\n");
		return 0;
	}



}

