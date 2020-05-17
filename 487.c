#define MAX(a, b) (a > b ? a : b)

/* 
1、定义left =0，rigth = 0两个偏移量，0的个数统计变量zero = 0。统计当前包含一个0的连续1最长长度值count = 0；
2、遍历数组，right往右偏移。循环right遇到0则累加zero，当zero>1的时候，left往右偏移，left遇到0则zero减1，直到zero<=1。反之遇到1则不管，相当于right累加（此时还不需要做任何操作），在最后只有当zero<=1的时候，开始判断right-left是否大于count，如果大于count，赋值给count。right++进入下一个循环。
*/

int findMaxConsecutiveOnes(int *arr, int numsSize)
{
    int left = 0, right = 0;
    int zero = 0;
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        if (arr[right] == 0) {
            zero += 1;
        }
        while (zero > 1) {
            if (arr[left] == 0) {
                zero -= 1;
            }
            left += 1;
        }
        res = MAX(res, right - left + 1);
    }
    return res;
}