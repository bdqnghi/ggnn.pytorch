import java.util.*;

package <missing>;

public class GlobalMembers
{
	public static int Main()
	{
		char c;
	int i;
	int j;
	int x;
	char[] a = {0, '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
	int[] b = new int[101];
	int m = 0;



	a = new Scanner(System.in).nextLine();
	for (i = 0;i < 101;i++)
	{
		if ((a[i] != '\0') && (a[i + 1] == '\0'))
		{
			x = i;
		}
	}
	for (i = 0;i <= x;i++)
	{
		if (a[i] == ' ')
		{
			b[m] = i;
			m++;
		}
	}
	b[m] = x + 1;
	for (i = m;i > 0;i--)
	{
		for (j = 0;j <= 100;j++)
		{
			if ((j > b[i - 1]) && (j < b[i]))
			{
				System.out.print(a[j]);
				if (j == b[i] - 1)
				{
					System.out.print(" ");
				}
			}



		}
	}
		for (j = 0;j <= 100;j++)
		{
			if (j < b[0])
			{
				System.out.print(a[j]);
			}
		}


		return 0;


	}


















}
