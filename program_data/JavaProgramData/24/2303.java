import java.util.*;

package <missing>;

public class GlobalMembers
{
	public static int Main()
	{
		String a = new String(new char[201]);
		char[][] b =
		{
			{'0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'}
		};
//C++ TO JAVA CONVERTER TODO TASK: Pointer arithmetic is detected on this variable, so pointers on this variable are left unchanged:
		char * p = null;
		a = new Scanner(System.in).nextLine();
		int i = 0;
		int l = a.length();
		int t = 0;
		int[] s = new int[201];
		p = a;
		while (*p != '\0')
		{
			if (*p != ' ' && *p != ',')
			{
				s[t]++;
				b[t][i] = p;
				i++;
			}
			else
			{
				i = 0;
				t++;
			}
			p++;
		}
		int temp1 = s[0];
		int temp2 = s[0];
		String c;
		String d;
		c = b[0];
		d = b[0];
		for (i = 0; i <= t; i++)
		{
			if (temp1 > s[i] && s[i] != 0)
			{
				temp1 = s[i];
				c = b[i];
			}
			if (temp2 < s[i] && s[i] != 0)
			{
				temp2 = s[i];
				d = b[i];
			}
		}
		for (; d != null && d != '0';)
		{
			System.out.print(d++);
		}
		System.out.print("\n");
		for (; c != null && c != '0';)
		{
			System.out.print(c++);
		}
		System.out.print("\n");
		return 0;

	}
}
