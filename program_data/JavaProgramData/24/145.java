package <missing>;

public class GlobalMembers
{
	public static void Main()
	{
		String a = new String(new char[5000]);
		char[][] b = new char[50][100];
		int[] c = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		int i;
		int j;
		int k = 0;
		int t;
		int max = 0;
		int min = 0;
		int sum = 0;
		for (i = 0;i < 5000;i = i + 1)
		{
			a = tangible.StringFunctions.changeCharacter(a, i, '\0'); //????????? ??GETS????????\0
		}
		a = new Scanner(System.in).nextLine();
		for (i = 0;i < a.length();)
		{
			for (j = 0;a.charAt(j + sum + k) != ' ' && a.charAt(j + sum + k) != '\0';j++)
			{
			c[k] = c[k] + 1;
			b[k][j] = a.charAt(j + sum + k); //??A??????????
			i++;
			}
			b[k][j] = '\0';
			k++;
			i++;
			sum = j + sum;
		}
		max = c[0];
		min = c[0];
		for (t = 1;t < k;t++)
		{
			if (c[t] > max)
			{
				max = c[t];
			}
		}
		for (t = 1;t < k;t++)
		{
			if (c[t] < min)
			{
				min = c[t];
			}
		}
		for (t = 0;t < k;t++)
		{
			if (max == c[t])
			{
			   System.out.printf("%s\n",b[t]);
			   break;
			}
		}


			for (t = 0;t < k;t++)
			{
				if (min == c[t])
				{
					System.out.printf("%s\n",b[t]);
					break;
				}
			}
	}

}

