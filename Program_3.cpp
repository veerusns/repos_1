#include<iostream.h>
#include<conio.h>
void display(int array[],int size);
void main()
{
	int array[]={16, 17, 4, 3, 5, 2};
	int num=sizeof(array)/sizeof(array[0]);
	display(array, num);
	getch();
}
void display(int array[],int size)
{
	for (int x=0;x<size;x++)
	{
		int y;
		for (y=x+1;y<size;y++)
		{
			if (array[x]<=array[y])
				break;
		}
		if (y==size)
			cout<<array[x]<<" ";
	}
}
