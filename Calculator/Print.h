/*
 * Print类用来输出所得到的队列。
    函数：接收一个队列，并逐个输出，每输出一个换一行。

        例如：
        输入：-100*(20+1)
        输出：
        -
        100
        *
        (
        20
        +
        1
        )
 */

#ifndef PRINT_H_
#define PRINT_H_

#include<queue>
#include"Scan.h"
using namespace std;

class Print
{
public:
	void PrintQueue(queue<string> theQueue);
};

#endif
