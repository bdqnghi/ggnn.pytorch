void main()
{
	int a,b,c,d,e,f,g,h,j,k,n;
	h=0;
	scanf ("%d %d %d",&a,&b,&c);
	scanf ("%d %d %d",&d,&e,&f);
	for (g=a+1;g<=d;g++)
	{
		if(g%400==0||(g%4==0&&g%100!=0))
		{
			h+=1;
		}
	}
	int days[12]={0,31,59,90,120,151,181,212,243,273,304,334};
	j=days[b-1];
    k=days[e-1];
	n=365*(d-a);
	if(a%400==0||(a%4==0&&a%100!=0)&&(b==1||b==2))
		h+=1;
	if(d%400==0||(d%4==0&&d%100!=0)&&(e==1||e==2))
		h-=1;
	n=n+h-j+k-c+f;
	printf("%d\n",n);
}