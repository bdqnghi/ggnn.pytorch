int main()
{
    int m,n,a[20][20]={0},i,j;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
    {
                    for(j=0;j<n;j++)
                    {
                                    scanf("%d",&a[i][j]);
                    }
    }
   
    
    for(i=0;i<m;i++)
    {
                    for(j=0;j<n;j++)
                    {
                                     if(i==0&&j==0)
                                     {
                                                   if((a[i][j]>=a[i+1][j])&&(a[i][j]>=a[i][j+1]))
                                                   printf("0 0\n");
                                     }
                                     else if(i==m-1&&j==0)
                                     {
                                                    if((a[i][j]>=a[i-1][j])&&(a[i][j]>=a[i][j+1]))                               
                                                   printf("%d 0\n",m-1);           
                                     }
                                     else if(i==m-1&&j==n-1)
                                     {
                                                    if((a[i][j]>=a[i-1][j])&&(a[i][j]>=a[i][j-1]))                               
                                                   printf("%d %d\n",m-1,n-1);
                                     }
                                      else if(i==0&&j==n-1)
                                     {
                                                    if((a[i][j]>=a[i+1][j])&&(a[i][j]>=a[i][j-1]))                               
                                                   printf("0 %d\n",n-1);
                                     }
                                     else if((i==0)&&(j>0)&&(j<n-1))
                                     {
                                          if((a[i][j]>=a[i][j+1])&&(a[i][j]>=a[i][j-1])&&(a[i][j]>=a[i+1][j]))
                                          printf("%d %d\n",i,j);
                                     }
                                     else if((i==m-1)&&(j>0)&&(j<n-1))
                                     {
                                          if((a[i][j]>=a[i][j+1])&&(a[i][j]>=a[i][j-1])&&(a[i][j]>=a[i-1][j]))
                                          printf("%d %d\n",i,j);
                                     }
                                     else if((j==0)&&(i>0)&&(i<m-1))
                                     {
                                          if((a[i][j]>=a[i+1][j])&&(a[i][j]>=a[i-1][j])&&(a[i][j]>=a[i][j+1]))          
                                          printf("%d %d\n",i,j);
                                     }
                                     else if((j==n-1)&&(i>0)&&(i<m-1))
                                     {
                                          if((a[i][j]>=a[i+1][j])&&(a[i][j]>=a[i-1][j])&&(a[i][j]>=a[i][j-1]))       
                                          printf("%d %d\n",i,j);
                                     }
                                     else
                                     {
                                         if((a[i][j]>=a[i+1][j])&&(a[i][j]>=a[i-1][j])&&(a[i][j]>=a[i][j-1])&&(a[i][j]>=a[i][j+1]))
                                         printf("%d %d\n",i,j);
                                     }
                    }
    }
    
    return 0;
}
                                                    
                                    
