void main()
{
	int x;
	scanf("%d",&x);
	if ((x%3==0) && (x%5==0) && (x%7==0))
		printf("3 5 7\n");
	if ((x%3==0) && (x%5==0) && !(x%7==0))
		printf("3 5\n");
	if ((x%3==0) && (x%7==0) && !(x%5==0))
		printf("3 7\n");
	if ((x%5==0) && (x%7==0) && !(x%3==0))
		printf("5 7\n");
	if ((x%3==0) && !(x%5==0) && !(x%7==0))
		printf("3\n");
	if ((x%5==0) && !(x%3==0) && !(x%7==0))
		printf("5\n");
	if ((x%7==0) && !(x%5==0) && !(x%3==0))
		printf("7\n");
	if (!(x%3==0) && !(x%5==0) && !(x%7==0))
		printf("n\n");
}
