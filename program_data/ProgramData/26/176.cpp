/**
* @file		???????.cpp
* @author	??	1000012792
* @date		2010.12.8
*/
int main()
{
	char s[110];		
	char *p=&s[0];		//????*p????????????
	int flag =0;		//flag????????????????0
	cin.getline(s,110); //??????s[]
	while(*p!='\0')		//s[]????
	{
		if(*p==' '&&flag==0)	//????????????
		{
			cout << *p;			//??????flag??1
			flag = 1;
		}
		else
			if(*p!=' ')			//??????????????????flag????0
			{
				cout << *p;
				flag = 0;
			}
		p++;					//??????
	}
	return 0;
}