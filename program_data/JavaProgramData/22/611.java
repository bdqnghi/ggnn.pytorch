package <missing>;

public class GlobalMembers
{
	public static int Main()
	{
		int[] a = new int[300];
		int n = 0;
		int i = 0;
		int j = 0;
		int m = 0;
		char b;
		while (true)
		{
		 String tempVar = ConsoleInput.scanfRead();
		 if (tempVar != null)
		 {
			 a[n] = Integer.parseInt(tempVar);
		 }
		 String tempVar2 = ConsoleInput.scanfRead(null, 1);
		 if (tempVar2 != null)
		 {
			 b = tempVar2.charAt(0);
		 }
		 n++;
		 /*if(n==2){if(a[0]>a[1]){i=a[0];j=a[1];m=1;}
		 else if(a[0]>a[1]){j=a[0];i=a[1];m=1;}
		 else i=a[0];}
		 if(n>2){
		         if(a[n-1]>i){j=i;i=a[n-1];m=1;}
		         else if(a[n-1]<i&&a[n-1]>j){j=a[n-1];m=1;}}*/
		 if (b != ',')
		 {
			 break;
		 }
		}
		//if(m==0)printf("No\n");
		//else printf("%d\n",j);
		for (i = 0;i < n;i++)
		{
		for (j = 0;j < n - 1;j++)
		{
		 if (a[j] < a[j + 1])
		 {
		  m = a[j];
		  a[j] = a[j + 1];
		  a[j + 1] = m;
		 }
		}
		}
		m = 0;
		for (i = 1;i < n;i++)
		{
		 if (a[i] != a[0])
		 {
		  System.out.printf("%d\n",a[i]);
		  m = 1;
		  break;
		 }
		}
		if (m == 0)
		{
			System.out.print("No\n");
		}
	}


}

