/*
 * pointer1.8.cpp
 *
 *  Created on: 2013-12-8
 *      Author: st
 *      ?? - ??(12-4) ????

?? POJ 2910
??
?????????????30????????????????????????????????????????

????
?????,?????30

????
???????????,??????. (??????)

????
123*456U17960? 302tab5876

????
123
456
17960
302
5876

??
??????????gets(c)
 *
 */
int main()
{
	char str[35];
    cin.getline(str,35);
    char *p1,*p2;
    int i;
    p1=str;
    p2=str;
    int m=strlen(str);
    for(i=0;i<m;i++){
    	if((i==m-1)&&(str[m-1]>=48)&&(str[m-1]<=57)){    //?????????
    	    p2=&str[m];                                  //???????????????????p2??????
    	if((*p1!='-')&&(*p1>=48)&&(*p1<=57))
    		while(p1!=p2)
    		 cout<<*p1++;
    	else {
    	      while((*p1<48)||(*p1>57))
    	     	 p1++;
    	      while(p1!=p2)                              //????
    	         cout<<*p1++;
    	      }
    	}
    	else                                             //??????
    		if((((str[i]<48)||(str[i]>57))&&(str[i]!=' '))&&(str[i-1]>=48)&&(str[i-1]<=57)){
    		p2=&str[i];
        if((*p1!='-')&&(*p1>=48)&&(*p1<=57)){            //??????
        	while(p1!=p2)
        		cout<<*p1++;
           cout<<endl;
           p1++;

          }
        else {                                            //????????
        	while((*p1<48)||(*p1>57))
     	      p1++;
        	while(p1!=p2)
        	   cout<<*p1++;
        	   cout<<endl;
        	   p1++;
        }

    	}

    }


}
