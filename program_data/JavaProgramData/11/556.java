package <missing>;

public class GlobalMembers
{
	public static void Main()
	{
		int year;
		int month;
		int day;
		int feb;
		int i;
		int n = 0;

		String tempVar = ConsoleInput.scanfRead();
		if (tempVar != null)
		{
			year = Integer.parseInt(tempVar);
		}
		String tempVar2 = ConsoleInput.scanfRead();
		if (tempVar2 != null)
		{
			month = Integer.parseInt(tempVar2);
		}
		String tempVar3 = ConsoleInput.scanfRead();
		if (tempVar3 != null)
		{
			day = Integer.parseInt(tempVar3);
		}

		if (year % 4 != 0)
		{
			feb = 28;
		}
		else
		{
			if (year % 100 != 0)
			{
				feb = 29;
			}
			else
			{
				if (year % 400 == 0)
				{
					feb = 29;
				}
				else
				{
					feb = 28;
				}
			}
		}



		for (i = 1;i < month;i++)
		{
			if (i == 2)
			{
				n = n + feb;
			}
			else
			{
				if (i == 4 || i == 6 || i == 9 || i == 11)
				{
					n = n + 30;
				}
				else
				{
					n = n + 31;
				}
			}
		}

		n = n + day;

		System.out.printf("%d",n);




	}

}

