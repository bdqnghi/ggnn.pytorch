int main()
{
	int n,a[7],i;
	cin>>n;
	a[1]=(int)(n/100);
	a[2]=(int)((n-a[1]*100)/50);
	a[3]=(int)((n-a[1]*100-a[2]*50)/20);
	a[4]=(int)((n-a[1]*100-a[2]*50-a[3]*20)/10);
	a[5]=(int)((n-a[1]*100-a[2]*50-a[3]*20-a[4]*10)/5);
	a[6]=(int)((n-a[1]*100-a[2]*50-a[3]*20-a[4]*10-a[5]*5)/1);
	for(i=1;i<=6;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}

   

 
