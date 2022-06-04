#include <iostream>
using namespace std;
int BinSearch(int key, const int a[], int begin, int end);
void QS(int a[], int lo, int hi);

int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int b[] = {6,8,7,9,0,1,3,2,4,5};
//    cout << BinSearch(6, a, 0 ,9) << endl;
    QS(b, 0, 9);

    return 0;
}


int BinSearch(int key, const int a[], int lo, int hi){
    while (lo <= hi)
    {   // 被查找的键要么不存在，要么必然存在于 a[lo..hi] 之中
        int mid = lo + (hi - lo) / 2;
        if (key < a[mid]) hi = mid - 1;
        else if (key > a[mid]) lo = mid + 1;
        else return mid;
    }
    return -1;
}
int partition(int a[], int lo, int hi)
{ // 将数组切分为a[lo..i-1], a[i], a[i+1..hi]
    int i = lo, j = hi+1; // 左右扫描指针
    int v = a[lo]; // 切分元素
    while (true)
    { // 扫描左右，检查扫描是否结束并交换元素
        while (a[++i] < v) if (i == hi) break;
        while (v < a[--j]) if (j == lo) break;
        if (i >= j) break;
        swap(a[i], a[j]);
    }
    swap(a[lo], a[j]); // 将v = a[j]放入正确的位置
    return j; // a[lo..j-1] <= a[j] <= a[j+1..hi] 达成
}
void QS(int a[], int lo, int hi){
    if (hi <= lo) return;
    int j = partition(a, lo, hi); // 切分
    QS(a, lo, j-1); // 将左半部分a[lo .. j-1]排序
    QS(a, j+1, hi); // 将右半部分a[j+1 .. hi]排序
}
