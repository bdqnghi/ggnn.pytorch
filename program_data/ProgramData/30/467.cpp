/*???1000012904_3.cpp
  ?????100???7???????
  ?????
  ???2010?10?15?
*/
int main()
{
	int n;//????????????
	cin >> n;//?????
	if(n < 100)//????????100??
	{   
		//??????????????????
		int a , b , i , sum = 0;
		for(i = 1 ; i <= n ; i++)//??
		{
			for(a = 0 ; a <= 9 ; a++)//?????
			{
				for(b = 0 ; b <= 9 ; b++)//?????
				{  
					//?????????????
	                                     if(i == a * 10 + b)
				   { 
                                            //???????7????
                                            if(i % 7 != 0 && a != 7 && b !=7)
	                                   sum = sum + i * i;//???????
				   }
				}
			}
		}
         cout << sum << endl;
	}
    return 0;
}