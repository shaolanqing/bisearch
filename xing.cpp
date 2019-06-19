//折半查找的算法
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
    int high = l.length;             //置区间初值
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == l.r[mid].key)
        {
            return mid;              //如果要查找值key == l.r[mid].key返回mid下标
        }
        else if (key < l.r[mid].key) 
        {
            high = mid - 1;          //未找到，把high往mid前移一位在前半区间查找
        }
        else
        {
            low = mid + 1;          //在后半区间查找
        }
    }
    return 0;
}
int main()
{
    RecordList L = { 10, 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};  //初始化线性表
    printf("%d\n", BinSearch(L, 30));       //查找30所在的下标
    return 0;
}
