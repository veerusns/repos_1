#include<stdio.h>
#include<string.h>
#include<conio.h>
void main()
{
    int small,second_small;
    int arr[50],size,i;
    clrscr();
    printf("\nEnter the Number of Elements:\t");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
	      printf("\nEnter the %d element:\t",i+1);
	      scanf("%d",&arr[i]);
    }
    if(arr[0]<arr[1])
    {
	      small=arr[0];
	      second_small=arr[1];
    }
    else
    {
      small=arr[1];
      second_small=arr[0];
    }
    for(i=2;i<size;i++)
    {
	      if(arr[i]<small)
	      {
		        second_small=small;
		        small=arr[i];
        }
	      else if(arr[i]<second_small)
	      {
	          second_small=arr[i];
        }
    }
    printf(" \nThe Smallest element is %d", small);
    printf(" \nThe Second Smallest element is %d", second_small);
    getch();
}
