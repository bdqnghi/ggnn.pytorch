int main()
{
	int number, sum;
	cin >> number;
	sum = 0; //????????????0 
	
	for(int i = 1; i <= number; i++) //???????????�number�?????????? 
	{
		sum += i * i;
	}
	
	for(int k = 1; k <= number; k++) //???7??????? 
	{
		if((k % 7) == 0 || (k % 10) == 7 || (k / 10) == 7) //?????7??????7?????????7???????7 
			sum = sum - k * k;
	}
	
	cout << sum << endl; //????? 
	return 0;
}
