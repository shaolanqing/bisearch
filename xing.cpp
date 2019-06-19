//�۰���ҵ��㷨
#include<stdio.h>
 
#define MaxSize 20
typedef struct
{
    int key;
}RecordType;
 
typedef struct
{
    int length;
    RecordType r[MaxSize + 1];
}RecordList;
 
int BinSearch(RecordList l, int key)
{
    int low = 1;
    int high = l.length;             //�������ֵ
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == l.r[mid].key)
        {
            return mid;              //���Ҫ����ֵkey == l.r[mid].key����mid�±�
        }
        else if (key < l.r[mid].key) 
        {
            high = mid - 1;          //δ�ҵ�����high��midǰ��һλ��ǰ���������
        }
        else
        {
            low = mid + 1;          //�ں���������
        }
    }
    return 0;
}
int main()
{
    RecordList L = { 10, 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};  //��ʼ�����Ա�
    printf("%d\n", BinSearch(L, 30));       //����30���ڵ��±�
    return 0;
}
