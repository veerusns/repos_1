#include <iostream.h>
#include<conio.h>
#define MAX_HEAP 128
#define ARR_SIZE(arr) sizeof(arr)/sizeof(arr[0])
inline void Exchange(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
bool Bigger(int a, int b)
{
	return a > b;
}
bool Smaller(int a, int b)
{
	return a < b;
}
int Avg(int a, int b)
{
	return (a + b) / 2;
}
int Sig_Num(int a, int b)
{
	if( a == b )
		return 0;
	return a < b ? -1 : 1;
}
class Heap
{
public:
	Heap(int *b, bool (*c)(int, int)) : ARRAY(b), comp(c)
	{
		heap_size = -1;
	}
	virtual ~Heap()
	{
		if( ARRAY )
		{
			delete[] ARRAY;
		}
	}
	virtual bool Insert(int e) = 0;
	virtual int Get_Top() = 0;
	virtual int Extract_Top() = 0;
	virtual int Get_Count() = 0;
protected:
	int left(int i)
	{
		return 2 * i + 1;
	}
	int right(int i)
	{
		return 2 * (i + 1);
	}
	int parent(int i)
	{
		if( i <= 0 )
		{
			return -1;
		}
		return (i - 1)/2;
	}
	int *ARRAY;
	bool (*comp)(int, int);
	int heap_size;
	int top(void)
	{
		int max = -1;
		if( heap_size >= 0 )
		{
			max = ARRAY[0];
		}
		return max;
	}
	int count()
	{
		return heap_size + 1;
	}
	void heapify(int i)
	{
		int p = parent(i);
		if( p >= 0 && comp(ARRAY[i], ARRAY[p]) )
		{
			Exchange(ARRAY[i], ARRAY[p]);
			heapify(p);
		}
	}
	int Delete_Top()
	{
		int del = -1;

		if( heap_size > -1)
		{
			del = ARRAY[0];
			Exchange(ARRAY[0], ARRAY[heap_size]);
			heap_size--;
			heapify(parent(heap_size+1));
		}
		return del;
	}
	bool Insert_Helper(int key)
	{
		bool boo = false;
		if( heap_size < MAX_HEAP  )
		{
			boo = true;
			heap_size++;
			ARRAY[heap_size] = key;
			heapify(heap_size);
		}
		return boo;
	}
};
class Max_Heap : public Heap
{
public:
	Max_Heap() : Heap(new int[MAX_HEAP ], &Bigger) { }
	~Max_Heap() { }
	int Get_Top()
	{
		return top();
	}
	int Extract_Top()
	{
		return Delete_Top();
	}
	int Get_Count()
	{
		return count();
	}
	bool Insert(int key)
	{
		return Insert_Helper(key);
	}
};
class Min_Heap : public Heap
{
public:
	Min_Heap() : Heap(new int[MAX_HEAP], &Smaller) { }
	~Min_Heap() { }
	int Get_Top()
	{
		return top();
	}
	int Extract_Top()
	{
		return Delete_Top();
	}
	int Get_Count()
	{
		return count();
	}
	bool Insert(int key)
	{
		return Insert_Helper(key);
	}
};
int Get_Median(int i, int &j, Heap &k, Heap &l)
{
	int sig = Sig_Num(k.Get_Count(), l.Get_Count());
	switch(sig)
	{
	case 1: 

		if( i < j ) 
		{
			l.Insert(k.Extract_Top());
			l.Insert(i);
		}
		else
		{
			l.Insert(i);
		}
		j = Avg(k.Get_Top(), l.Get_Top());
		break;
	case 0: 
		if( i < j ) 
		{
			l.Insert(i);
			j = k.Get_Top();
		}
		else
		{
			l.Insert(i);
			j = l.Get_Top();
		}
		break;
	case -1: 
		if( i < j ) 
		{
			k.Insert(i);
		}
		else
		{
			k.Insert(l.Extract_Top());
			l.Insert(i);
		}
		j = Avg(k.Get_Top(), l.Get_Top());
		break;
	}
	return j;
}
void Print_Median(int ARRAY[], int size)
{
	int m = 0; 
	Heap *left = new Max_Heap();
	Heap *right = new Min_Heap();
	for(int i = 0; i < size; i++)
	{
		m = Get_Median(ARRAY[i], m, *left, *right);
		cout<<m;
	}
	delete left;
	delete right;
}
void main()
{
	int ARRAY[] = {5, 15, 1, 3, 2};
	int size = ARR_SIZE(ARRAY);
	Print_Median(ARRAY, size);
	getch();
}
