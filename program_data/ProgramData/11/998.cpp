main()
{
      int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
      int i,j,k=0,n;
      int y,m,d;
      scanf("%d %d %d",&y,&m,&d);
      if((y%4==0&&y%100!=0)||(y%400==0))
      {
                          for(i=1;i<m;i++)
                          {k=k+b[i];}
                          k=k+d;
                          printf("%d",k);
      }
      k=0;
      if(y%4!=0||(y%100==0&&y%400!=0))
      {
                for(i=1;i<m;i++)
                {k=k+a[i];}
                k=k+d;
                printf("%d",k);
                }
            }