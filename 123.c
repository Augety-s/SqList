#include<stdio.h>
#include<stdbool.h>
#define MaxSize 50
typedef struct{
	int data[MaxSize];
	int length;
}SqList;
void ListInit(SqList *L){
	L->length = 0;
	for (int i = 0; i < MaxSize; i++)
		L->data[i] = 0;

}
bool ListInsert(SqList* L, int i, int e) {
	if (i<1 || i>L->length + 1)
	{

		return false;
	}
	if (L->length >= MaxSize)
		return false;
	for (int j = L->length; j >= i; j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
	return true;
}
bool Del_Min(SqList *L,int *value) {
	if (L->length == 0)
		return false;
	*value = L->data[0];
	int pos = 0;
	for (int i = 1;i < L->length; i++){
		if (L->data[i] < *value) {
			*value = L->data[i];
			pos = i;
		}
	}
	L->data[pos] = L->data[L->length - 1];
}
int main()
{
	SqList list;
	SqList *L=&list;
	ListInit(L);
	ListInsert(L, 1, 5);
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 6);
	ListInsert(L, 4, 10);
	int value=0;
	int* a = &value;
	Del_Min(L, a);
	printf("最小值为%d", value);
	return 0;
}
