/*��?0?8�?0?6?0?0?0?0?0?7?0?4?0?4?0?5?0?1?0?1?0?7?0?6?0?3?0?4?0?4?0?9?0?4?0?8?0?5?0?6?0?3?0?0?0?2?0?5�?0?7�?0?8?0?2?0?4?0?3?0?3?0?4?0?5?0?1?0?6?0?4?0?5?0?2 
00630018 zhouyan m 20 10.0 28#460 
?0?8?0?1?0?6?0?5?0?8?0?2�?0?6?0?2�?0?6?0?8"end"?0?5�?0?8?0?3
?0?1?0?1?0?7?0?3?0?8?0?1?0?6?0?2 
?0?5?0?0?0?8?0?1?0?6?0?5?0?8?0?2?0?2?0?3?0?6?0?6�?0?7?0?9?0?9 
?0?5�?0?2?0?3 ?0?4?0?9?0?1?0?4 ?0?4?0?8�?0?8 ?0?2�?0?9?0?1 ?0?8?0?1�?0?0 ?0?8?0?1?0?0� 
?0?8?0?2?0?0?0?9?0?8?0?5?0?8?0?1?0?4�?0?8?0?1?0?6?0?2 */
struct student
{
	char info[100];
	struct student *pre;
};
struct student *creat()
{
	struct student *head,*p1,*p2;
	head=(struct student *)malloc(sizeof(struct student));
	p1=head;
	head->pre=0;
	while(1)
	{
		gets(p1->info);
		if(p1->info[0]=='e')
		{
			return p1->pre;
		}
		else
		{
			p2=(struct student *)malloc(sizeof(struct student));
			p2->pre=p1;
			p1=p2;
		}
	}
}
int main()
{
	struct student *p;
	p=creat();
	while(p!=0)
	{
		printf("%s\n",p->info);
		p=p->pre;
	}
	return 0;
}
/*00630018 zhouyan m 20 10 28#4600
0063001 zhouyn f 21 100 28#460000
0063008 zhoyan f 20 1000 28#460000
0063018 zhouan m 21 10000 28#4600000
00613018 zhuyan m 20 100 28#4600
00160018 zouyan f 21 100 28#4600
01030018 houyan m 20 10 28#4600
0630018 zuyan m 21 100 28#4600
10630018 zouan m 20 10 28#46000
end
10630018 zouan m 20 10 28#46000
0630018 zuyan m 21 100 28#4600
01030018 houyan m 20 10 28#4600
00160018 zouyan f 21 100 28#4600
00613018 zhuyan m 20 100 28#4600
0063018 zhouan m 21 10000 28#4600000
0063008 zhoyan f 20 1000 28#460000
0063001 zhouyn f 21 100 28#460000
Press any key to continue*/