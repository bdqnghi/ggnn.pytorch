
int main()
{
	int A,B,C,a,b,c,i,j,day=0;
	scanf("%d %d %d\n%d %d %d",&A,&B,&C,&a,&b,&c);
	if(A<a){
		for(j=B;j<=12;j++){
		if(j==1||j==3||j==5||j==7||j==8||j==10||j==12)
			day+=31;
		if(j==4||j==6||j==9||j==11)
			day+=30;
		if(j==2&&(A%4==0&&A%100!=0||A%400==0))
			day+=29;
		if(j==2&&(A%4!=0||(A%100==0&&A%400!=0)))
			day+=28;
		}
		day-=C-1;
	if(a-A>1){
		for(i=A+1;i<=a-1;i++){
			if(i%4==0&&i%100!=0||i%400==0){
			day+=366;
			}else{
			day+=365;
			}
		}
	}
	for(j=0;j<=b-1;j++){
		if(j==1||j==3||j==5||j==7||j==8||j==10||j==12)
			day+=31;
		if(j==4||j==6||j==9||j==11)
			day+=30;
		if(j==2&&(a%4==0&&a%100!=0||a%400==0))
			day+=29;
		if(j==2&&(a%4!=0||(a%100==0&&a%400!=0)))
			day+=28;
		if(j==0)
			day+=0;
	}
	day+=c-1;
	}
	if(A==a){
		if(B==b)
		day=c-C;
		if(b>B){
		if(B==1||B==3||B==5||B==7||B==8||B==10||B==12)
			day+=31;
		if(B==4||B==6||B==9||B==11)
			day+=30;
		if(B==2&&(A%4==0&&A%100!=0||A%400==0))
			day+=29;
		if(B==2&&(A%4!=0||(A%100==0&&A%400!=0)))
			day+=28;
		day-=C-1;
		if(b-B>1){
			for(j=B+1;j<=b-1;j++){
			if(j==1||j==3||j==5||j==7||j==8||j==10||j==12)
			day+=31;
			if(j==4||j==6||j==9||j==11)
			day+=30;
			if(j==2&&(A%4==0&&A%100!=0||A%400==0))
			day+=29;
			if(j==2&&(A%4!=0||(A%100==0&&A%400!=0)))
			day+=28;
			}
		}
		day+=c-1;
		}
	}
	printf("%d",day);
	return 0;
}