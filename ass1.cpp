#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct move
{
	int killing;
	int doubling;
	int pairanchor;
	int single;
	int barpoint;
	int normal;
	int litelo;
	int barmove;
	int s1,d1,s2,d2;
}move;
move steps[100];
int movecount=0;

int main()
{
	int A[13]={0};
	int B[13]={0};
	int array[25];
	int array1[25];
//	char name[10];
//	cin>>name;
//	int lolflag=0;
	for(int i=0;i<12;i++)
	{
			cin>>A[i];
	}
	for(int i=0;i<12;i++)
	{
			cin>>B[i];
	}
	int dice1,dice2,z;
	cin>>dice1>>dice2;
	cin>>z;
/*	if(strcmp("Alice",name)==0)
	{*/
		int j=0;
		for(int i=11;i>=0;i--)
		{
			array[j++]=B[i];
		}
		for(int i=0;i<12;i++)
		{
			array[j++]=A[i];
		}
//	}
/*	else 
	{
		int j=0;
		for(int i=11;i>=0;i--)
		{
			array[j++]=-A[i];
		}
		for(int i=0;i<12;i++)
		{
			array[j++]=-B[i];
		}
	}*/

	int stemp,dtemp,killed=0;
	int moved=0,smove=0;
	for(int i=0;i<24 && z==0;i++)
	{
		moved=0;
		smove=0;
		killed=0;
		if(array[i]>0)
		{
			if(i+dice1<=23)
			{
				if(array[i+dice1]>=-1)
				{
					for(int k=0;k<24;k++)
					{
						array1[k]=array[k];
					}
					stemp=i;
					array1[i]--;
					if(array[i+dice1]==-1)
					{
						array1[i+dice1]=1;
						killed=1;
					}
					else
						array1[i+dice1]++;
					dtemp=i+dice1;
					moved=1;
				}
			}
		}
		for(int j=0;j<24 && moved==1 &&smove==0;j++)
		{
			if(array1[j]>0)
			{
				if(j+dice2<=23)
				{
					if(array1[j+dice2]>=-1)
					{

						steps[movecount].s1=stemp;
						steps[movecount].d1=dtemp;
						steps[movecount].s2=j;
						steps[movecount].d2=j+dice2;
						if(dtemp==21)
						{
							if(array[dtemp]==1)
							{
								steps[movecount].pairanchor=1;
							}
						}
						if((j+dice2)==21)
						{
							if(array[(j+dice2)]==1)
							{
								steps[movecount].pairanchor=1;
							}
						}		
						if(killed==1)
						{
							steps[movecount].killing=1;
						}
						if(array[dtemp]==-1 || array[(j+dice2)]==-1)
						{
							steps[movecount].killing=1;
						}
						if(array[dtemp]==1 || array[(j+dice2)]==1)
						{

							steps[movecount].doubling=1;
						}
						if(array[stemp]==2 || array[j]==2)
						{
							steps[movecount].single=1;
						}
						if(dtemp==17)
						{
							if(array[dtemp]==1)
							{
							steps[movecount].barpoint=1;

							}
						}
						if((j+dice2)==17)
						{
							if(array[(j+dice2)]==1)
							{
							steps[movecount].barpoint=1;

							}
						}

						movecount++;

					}
				}
			}
		}
		killed=0;
		if(array[i]>0)
		{
			if(i+dice2+dice1<=23)
			{
				if(array[i+dice2]>=-1 && array[i+dice1+dice2]>=-1 && array[i+dice1]>=-1)
				{
					for(int k=0;k<24;k++)
					{
						array1[k]=array[k];
					}
					stemp=i;
					array1[i]--;
					if(array[i+dice2]==-1)
					{
						killed=1;
						array1[i+dice2]=1;
					}
					else
						array1[i+dice2]++;
					dtemp=i+dice2;
					moved=1;
					smove=1;
				}
			}
		}
		for(int j=0;j<24 && smove==1 &&moved==1;j++)
		{
			if(array1[j]>0)
			{
				if(j+dice1<=23)
				{
					if(array1[j+dice1]>=-1 && j==dtemp)
					{

						steps[movecount].s1=stemp;
						steps[movecount].d1=dtemp;
						steps[movecount].s2=j;
						steps[movecount].d2=j+dice1;
						if(dtemp==21)
						{
							if(array[dtemp]==1)
							{
								steps[movecount].pairanchor=1;
							}
						}
						if((j+dice2)==21)
						{
							if(array[(j+dice2)]==1)
							{
								steps[movecount].pairanchor=1;
							}
						}		
						if(killed==1)
						{
							steps[movecount].killing=1;
						}
						if(array[dtemp]==-1 || array[(j+dice2)]==-1)
						{
							steps[movecount].killing=1;
						}
						if(array[dtemp]==1 || array[(j+dice2)]==1)
						{

							steps[movecount].doubling=1;
						}
						if(array[stemp]==2 || array[j]==2)
						{
							steps[movecount].single=1;
						}
						if(dtemp==17)
						{
							if(array[dtemp]==1)
							{
							steps[movecount].barpoint=1;

							}
						}
						if((j+dice2)==17)
						{
							if(array[(j+dice2)]==1)
							{
							steps[movecount].barpoint=1;

							}
						}

						movecount++;
					}
				}
			}
		}
	}
	for(int i=0;i<24 && z==0;i++)
	{
		moved=0;
		smove=0;
		killed=0;
		if(array[i]>0)
		{
			if(i+dice1<=23)
			{
				if(array[i+dice1]>=-1)
				{
					for(int k=0;k<24;k++)
					{
						array1[k]=array[k];
					}
					stemp=i;
					array1[i]--;
					if(array[i+dice1]==-1)
					{
						killed=1;
						array1[i+dice1]=1;
					}
					else
						array1[i+dice1]++;
					dtemp=i+dice1;
					moved=1;
				}
			}
		}
		int moved1=0;
		for(int j=0;j<24 && moved==1;j++)
		{
			if(array1[j]>0)
			{
				if(j+dice2<=23)
				{
					if(array1[j+dice2]>=-1)
					{
						moved1=1;
					}
				}
			}
		}
		if(moved==1 && moved1==0)
		{
			steps[movecount].s1=stemp;
			steps[movecount].d1=dtemp;
			steps[movecount].s2=0;
			steps[movecount].d2=0;
						if(dtemp==21)
						{
							if(array[dtemp]==1)
							{
								steps[movecount].pairanchor=1;
							}
						}
			/*			if((j+dice2)==21)
						{
							if(array[(j+dice2)]==1)
							{
								steps[movecount].pairanchor=1;
							}
						}		*/
						if(killed==1)
						{
							steps[movecount].killing=1;
						}
						if(array[dtemp]==-1 )
						{
							steps[movecount].killing=1;
						}
						if(array[dtemp]==1 )
						{

							steps[movecount].doubling=1;
						}
						if(array[stemp]==2 || array[0]==2)
						{
							steps[movecount].single=1;
						}
						if(dtemp==17)
						{
							if(array[dtemp]==1)
							{
							steps[movecount].barpoint=1;

							}
						}

			movecount++;
		}
		moved=0;
		moved1=0;
		killed=0;
		if(array[i]>0)
		{
			if(i+dice2<=23)
			{
				if(array[i+dice2]>=-1)
				{
					for(int k=0;k<24;k++)
					{
						array1[k]=array[k];
					}
					stemp=i;
					array1[i]--;
					if(array[i+dice2]==-1)
					{
						killed=1;
						array1[i+dice2]=1;
					}
					else
						array1[i+dice2]++;
					dtemp=i+dice2;
					moved=1;
				}
			}
		}
		for(int j=0;j<24 && moved==1;j++)
		{
			if(array1[j]>0)
			{
				if(j+dice1<=23)
				{
					if(array1[j+dice1]>=-1)
					{
						moved1=1;
					}
				}
			}
		}
		if(moved==1 && moved1==0)
		{
			steps[movecount].s1=stemp;
			steps[movecount].d1=dtemp;
			steps[movecount].s2=0;
			steps[movecount].d2=0;
						if(dtemp==21)
						{
							if(array[dtemp]==1)
							{
								steps[movecount].pairanchor=1;
							}
						}
						if(killed==1)
						{
							steps[movecount].killing=1;
						}
						if(array[dtemp]==-1)
						{
							steps[movecount].killing=1;
						}
						if(array[dtemp]==1)
						{

							steps[movecount].doubling=1;
						}
						if(array[stemp]==2 || array[0]==2)
						{
							steps[movecount].single=1;
						}
						if(dtemp==17)
						{
							if(array[dtemp]==1)
							{
							steps[movecount].barpoint=1;

							}
						}

			movecount++;
		}
	}
	if(z>=2)
	{
		if(array[dice1-1]>=-1)
		{
			if(array[dice2-1]>=-1)
			{
				steps[movecount].s1=-1;
				steps[movecount].d1=dice1-1;
				steps[movecount].s2=-1;
				steps[movecount].d2=dice2-1;
				steps[movecount].barmove=1;
				movecount++;
				z-=2;


			}
			else
			{
				z--;
				steps[movecount].s1=-1;
				steps[movecount].d1=dice1-1;
				steps[movecount].s2=-2;
				steps[movecount].d2=-2;
				steps[movecount].barmove=1;

				movecount++;
			}
		}
		else if(array[dice2-1]>=-1)
		{
			z--;
			steps[movecount].s1=-1;
			steps[movecount].d1=dice2-1;
			steps[movecount].s2=-2;
			steps[movecount].d2=-2;
			steps[movecount].barmove=1;
			movecount++;
		}
	}
	else if(z==1)
	{
		if(array[dice1-1]>=-1)
		{	
			for(int j=0;j<24;j++)
			{
				if(array[j]>0)
				{
					if(j+dice2<=23)
					{
						if(array[j+dice2]>=-1)
						{
							steps[movecount].s1=-1;
							steps[movecount].d1=dice1-1;
							steps[movecount].s2=j;
							steps[movecount].d2=j+dice2;
						if((j+dice2)==21)
						{
							if(array[(j+dice2)]==1)
							{
								steps[movecount].pairanchor=1;
							}
						}		
						if(killed==1)
						{
							steps[movecount].killing=1;
						}
						if(array[dice1-1]==-1 || array[(j+dice2)]==-1)
						{
							steps[movecount].killing=1;
						}
						if(array[dice1-1]==1 || array[(j+dice2)]==1)
						{

							steps[movecount].doubling=1;
						}
						if(array[-1]==2 || array[j]==2)
						{
							steps[movecount].single=1;
						}
						if((dice1-1)==17)
						{
							if(array[(dice1-1)]==1)
							{
							steps[movecount].barpoint=1;

							}
						}
						if((j+dice2)==17)
						{
							if(array[(j+dice2)]==1)
							{
							steps[movecount].barpoint=1;

							}
						}
/*
						if(d1==21)
						{
							if(array[d1]==1)
							{
								steps[movecount].pairanchor=1;
							}
						}
						if(d2==21)
						{
							if(array[d2]==1)
							{
								steps[movecount].pairanchor=1;
							}
						}		
						if(killed==1)
						{
							steps[movecount].killing=1;
						}
						if(array[d1]==-1 || array[d2]==-1)
						{
							steps[movecount].killing=1;
						}
						if(array[d1]==1 || array[d2]==1)
						{

							steps[movecount].doubling=1;
						}
						if(array[s1]==2 || array[s2]==2)
						{
							steps[movecount].single=1;
						}
						if(d1==17)
						{
							if(array[d1]==1)
							{
							steps[movecount].barpoint=1;

							}
						}
						if(d2==17)
						{
							if(array[d2]==1)
							{
							steps[movecount].barpoint=1;

							}
						}*/
						
						steps[movecount].barmove=2;

							movecount++;
						}
					}
				}
			}
			z-=1;
		}
		if(array[dice2-1]>=-1)
		{	
			for(int j=0;j<24;j++)
			{
				if(array[j]>0)
				{
					if(j+dice1<=23)
					{
						if(array[j+dice1]>=-1)
						{
							steps[movecount].s1=-1;
							steps[movecount].d1=dice2-1;
							steps[movecount].s2=j;
							steps[movecount].d2=j+dice1;
						if((j+dice1)==21)
						{
							if(array[(j+dice1)]==1)
							{
								steps[movecount].pairanchor=1;
							}
						}		
						if(killed==1)
						{
							steps[movecount].killing=1;
						}
						if(array[dice2-1]==-1 || array[(j+dice1)]==-1)
						{
							steps[movecount].killing=1;
						}
						if(array[dice2-1]==1 || array[(j+dice1)]==1)
						{

							steps[movecount].doubling=1;
						}
						if(array[-1]==2 || array[j]==2)
						{
							steps[movecount].single=1;
						}
						if(dtemp==17)
						{
							if(array[dice2-1]==1)
							{
							steps[movecount].barpoint=1;

							}
						}
						if((j+dice1)==17)
						{
							if(array[(j+dice1)]==1)
							{
							steps[movecount].barpoint=1;

							}
						}
/*
						if(d1==21)
						{
							if(array[d1]==1)
							{
								steps[movecount].pairanchor=1;
							}
						}
						if(d2==21)
						{
							if(array[d2]==1)
							{
								steps[movecount].pairanchor=1;
							}
						}		
						if(killed==1)
						{
							steps[movecount].killing=1;
						}
						if(array[d1]==-1 || array[d2]==-1)
						{
							steps[movecount].killing=1;
						}
						if(array[d1]==1 || array[d2]==1)
						{

							steps[movecount].doubling=1;
						}
						if(array[s1]==2 || array[s2]==2)
						{
							steps[movecount].single=1;
						}
						if(d1==17)
						{
							if(array[d1]==1)
							{
							steps[movecount].barpoint=1;

							}
						}
						if(d2==17)
						{
							if(array[d2]==1)
							{
							steps[movecount].barpoint=1;

							}
						}*/
						
						steps[movecount].barmove=2;

							movecount++;
						}
					}
				}
			}
			z-=1;
		}
	}
	if(movecount==2)
	{
		if(steps[0].s1==steps[1].s1 && steps[0].d2==steps[1].d2 && steps[0].s2==steps[1].s2)
		{
			if(steps[0].d1>steps[1].d1)
			{
				steps[1].litelo=1;
			}
			if(steps[0].d1<steps[1].d1)
			{
				steps[0].litelo=1;
			}
		}
	}
	int evaluation=0;
	int trigger=0;
	cout<<movecount<<endl;
	for(int i=0;i<movecount;i++)
	{
		if(steps[i].litelo==0)
			cout<<steps[i].s1<<" "<<steps[i].d1<<" "<<steps[i].s2<<" "<<steps[i].d2<<endl;
	}
	for(int i=0;i<movecount;i++)
	{
		int now=0;
		if(steps[i].pairanchor==1)
		{
			now+=40;
		}
		if(steps[i].killing==1)
		{
			now+=45;
		}
		if(steps[i].doubling==1)
		{
			now+=25;
		}
		if(steps[i].single==1)
		{
			now-=10;
		}
		if(steps[i].barpoint==1)
		{
			now+=15;
		}
		if(steps[i].barmove==1)
		{
			now+=40;
		}
		if(steps[i].barmove==2)
		{
			now+=40;
		}
		if(now>evaluation)
		{
			evaluation=now;
			trigger=i;
		}
	}
//	cout<<evaluation<<endl;
	cout<<steps[trigger].s1<<" "<<steps[trigger].d1<<" "<<steps[trigger].s2<<" "<<steps[trigger].d2<<endl;
/*	if(steps[trigger].s1==steps[trigger].d1)
	{
		cout<<"pass";
	}
	if(steps[trigger].s1<0)
	{
		cout<<"Z";
	}
	if(steps[trigger].s1<12  && steps[trigger].s1>=0 && strcmp("Alice",name)==0 && steps[trigger].s1!=steps[trigger].d1)
	{
		cout<<"B";
		cout<<13-(steps[trigger].s1%12+1);
	}
	else if(steps[trigger].s1>=12&& steps[trigger].s1>=0 && strcmp("Alice",name)==0 && steps[trigger].s1!=steps[trigger].d1)
	{
		cout<<"A";
		cout<<(steps[trigger].s1%12+1);
	}
	if(steps[trigger].s1<12 && steps[trigger].s1>=0 && strcmp("Bob",name)==0 && steps[trigger].s1!=steps[trigger].d1)
	{
		cout<<"A";
		cout<<13-(steps[trigger].s1%12+1);
	}
	else if(steps[trigger].s1>=12 && steps[trigger].s1>=0&& strcmp("Bob",name)==0 &&  steps[trigger].s1!=steps[trigger].d1)
	{
		cout<<"B";
		cout<<(steps[trigger].s1%12+1);
	}
	cout<<" ";
	if(steps[trigger].d1<12  && strcmp("Alice",name)==0 && steps[trigger].s1!=steps[trigger].d1)
	{
		cout<<"B";
		cout<<13-(steps[trigger].d1%12+1);
	}
	else if(steps[trigger].d1>=12 && strcmp("Alice",name)==0 && steps[trigger].s1!=steps[trigger].d1)
	{
		cout<<"A";
		cout<<(steps[trigger].d1%12+1);
	}
	if(steps[trigger].d1<12 && strcmp("Bob",name)==0 && steps[trigger].s1!=steps[trigger].d1)
	{
		cout<<"A";
		cout<<13-(steps[trigger].d1%12+1);
	}
	else if(steps[trigger].d1>=12 && strcmp("Bob",name)==0 && steps[trigger].s1!=steps[trigger].d1)
	{
		cout<<"B";
		cout<<(steps[trigger].d1%12+1);
	}
	cout<<"\n";

	if(steps[trigger].s2<0)
	{
		cout<<"Z";
	}
	if(steps[trigger].s2==steps[trigger].d2)
	{
		cout<<"pass";
	}
	if(steps[trigger].s2<12 && steps[trigger].s2>=0 && strcmp("Alice",name)==0 && steps[trigger].s2!=steps[trigger].d2)
	{
		cout<<"B";
		cout<<13-(steps[trigger].s2%12+1);
	}
	else if(steps[trigger].s2>=12   && steps[trigger].s2>=0&& strcmp("Alice",name)==0  &&  steps[trigger].s2!=steps[trigger].d2)
	{
		cout<<"A";
		cout<<(steps[trigger].s2%12+1);
	}
	if(steps[trigger].s2<12  && steps[trigger].s2>=0  && strcmp("Bob",name)==0 && steps[trigger].s2!=steps[trigger].d2)
	{
		cout<<"A";
		cout<<13-(steps[trigger].s2%12+1);
	}
	else if(steps[trigger].s2>=12  && steps[trigger].s2>=0  && strcmp("Bob",name)==0 && steps[trigger].s2!=steps[trigger].d2)
	{
		cout<<"B";
		cout<<(steps[trigger].s2%12+1);
	}
	cout<<" ";
	if(steps[trigger].d2<12 && strcmp("Alice",name)==0  && steps[trigger].s2!=steps[trigger].d2) 
	{
		cout<<"B";
		cout<<13-(steps[trigger].d2%12+1);
	}
	else if(steps[trigger].d2>=12 && strcmp("Alice",name)==0 && steps[trigger].s2!=steps[trigger].d2)
	{
		cout<<"A";
		cout<<(steps[trigger].d2%12+1);
	}
	if(steps[trigger].d2<12 && strcmp("Bob",name)==0  && steps[trigger].s2!=steps[trigger].d2)
	{
		cout<<"A";
		cout<<13-(steps[trigger].d2%12+1);
	}
	else if(steps[trigger].d2>=12 && strcmp("Bob",name)==0 && steps[trigger].s2!=steps[trigger].d2)
	{
		cout<<"B";
		cout<<(steps[trigger].d2%12+1);
	}
	cout<<endl;*/

	return 0;
}
