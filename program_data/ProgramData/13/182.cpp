/**
  *file  ????????
  *author ???
  *date   10.27
  *function ??n????n???????????????10-100??? 
            ??????????????????????????????????????????? 
*/
int main()
{
	int n, a[20001], i, j;
	cin >> n;
	for(i = 1; i <= n; i++)				//???n??
	{
		cin >> a[i];
	}
	cout << a[1];
	for(i = 2; i <= n; i++)
	{
		for(j = i - 1; j >= 1; j--)
		{
			if(a[j] == a[i])
			{
				break;
			}
		}
		if(j == 0)						//??j??0????????????
		{
			cout << " " << a[i]; 
		}
	}
	return 0;
}