/**
 * @file         1.cpp
 * @author       ??? 
 * @date         2013-12-04 
 * @description
 *               ???????????? 
 **/ 

int n, k, p;    // n??????p?????????????? 

// apple(num) ???num?????????????????? 
int apple(int num)
{
    // ?n????p?????????? n * p + k ??? 
    if (num == n) return (n * p + k);
    
    // v????apple(num + 1), tot ?????????????? 
    int v, tot;
    
    v = apple(num + 1);
    while (v % (n - 1) != 0)
    {
          // ??v????n - 1??????????????????? 
          ++p;
          v = apple(num + 1);
    }
    
    // ???????????????????????????????? 
    tot = v + v / (n - 1) + k;
    return tot;
}

int main()
{
    cin >> n >> k;
    
    // ???????????????
    // ??????0???(= =!) 
    p = 1;
    cout << apple(1);
    
    return 0;
} 