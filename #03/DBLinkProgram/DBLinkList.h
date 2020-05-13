/*******************************************************************************
* FileName:         DBLinkList.h
* Author:           tahara
* Student Number:   3015218126
* Date:             2020/03/03 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #3
*                   这个是助教完成的 .h 文件，请不要更改里面的内容
*******************************************************************************/

#ifndef DBLINKLIST_H
#define DBLINKLIST_H

class DBLinkList
{
private:
    /**
     *   双向链表的节点指针
     *   value:  数据域
     *   nxt:  后继节点
     *   pre:  前驱节点
    */
    struct DBNode
    {
        DBNode *pre, *nxt;
        int value;
    };
    DBNode *head;
    DBNode *tail;
    int len;
public:
    /**
     * 构造函数和析构函数
     */
    DBLinkList();
    ~DBLinkList();

    /**
     * 在location中插入数据data
     * @name void insert(int, int);
	 * @param arg1 需要插入的数据
	 * @param arg2 需要插入数据的位置
	 * 说明: 链表的计数是从0开始的，如果此时 eleNumber == k, 可以插入的区间为[0, k],
     *      假定函数为  insertDBL(dbl, n, i), 则执行后n为第i个元素
    */
    void insert(int data, int location);

    /**
     * 删除链表中第i个元素
     * 提示:  如果删除了最后一个元素，记得让head和tail重置为NULL
     * @name void remove(int);
     * @param arg1 需要执行删除的位置
     * @return
     */
    void remove(int location);

    /**
     * 获得双向链表的长度
     * @name int length();
     * @return int 双向链表的长度
     */
    int length();

    /**
     * 获取第i个元素
     * @name int getData(int);
     * @param arg1 需要获取元素的位置。
     * @return 第i个元素的指。
     */
    int getData(int location);

    /**
     * 将链表进行冒泡排序
     * @name void bubbleSort();
     * @return 
     */
    void bubbleSort();
};
#endif