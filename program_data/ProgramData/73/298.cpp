/******************????************************
??
?????? (5*5)???????????????
????????
?????????????????????????
????????�not found�?
?????????????????????????
??????????
????????????4??1???????????8 ??
11 3 5 6 9
12 4 7 8 10
10 5 6 9 11
8 6 4 7 2
15 10 11 20 25
????
??????5?5????
????
?????????????????????
????????"not found"
????
11 3 5 6 9
12 4 7 8 10
10 5 6 9 11
8  6 4 7 2
15 10 11 20 25
????
4 1 8
*********************************************************
????
????????????row[i]
????????????cloumn[j]
??column[row[i]]==i,?????
programmer Qiu Hezi
version 1.0
creat date 2012.10.30 1:13
*********************************************************/
int main()
{
    int a[6][6];
    for (int i=1 ; i<=5 ; i++)
        for (int j=1 ; j<=5 ; j++)
    {
        cin>>a[i][j];
    }

    int max_row[6]={0},min_column[6]={0};
    int line_row[6]={0},line_column[6]={0,1,1,1,1,1};
    //?????????/???????
    for (int j=1 ; j<=5 ; j++)
        min_column[j]=a[1][j];//?????????
    for (int i=1 ; i<=5 ; i++)
        for (int j=1 ; j<=5 ; j++)
    {
        if (a[i][j] > max_row[i])
        {
            max_row[i]=a[i][j];
            line_row[i]=j;
        }
        if (a[i][j] < min_column[j])
        {
            min_column[j]=a[i][j];
            line_column[j]=i;
        }
    }
    int success=0;
    for (int i=1 ; i<=5 ; i++)
        if (line_row[line_column[i]]==i)
        {
            cout<<line_column[i]<<" "<<i<<" "<<a[line_column[i]][i];
            success=1;
        }
    if (success==0)
        cout<<"not found"<<endl;

    return 0;
}


