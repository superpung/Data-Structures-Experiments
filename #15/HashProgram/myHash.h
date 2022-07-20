/*******************************************************************************
* FileName:         myHash.h
* Author:           super
* Student Number:   0000000000
* Date:             2020/05/20 14:00:55
* Version:          v1.0
* Description:      Data Structure Experiment #15
*******************************************************************************/


class MyHash{
private:
    struct HashNode {
        int value;
        int key;
        HashNode* next;
    };
    struct TableNode {
        HashNode* head;
    };

    TableNode* HashTable;
public:
    /**
     *  声明一个哈希表，哈希表中元素最多为max_element个。
        @name MyHash(int max_element)
        @param arg1  哈希表对最大元素个数
        @return
    */
    MyHash(int max_element);


    /**
     *  析构函数
        @name
        @param
        @return
    */
    ~MyHash();




    /**
     *  获取哈希表中键值为key的元素的值。
        @name int getvalue(int);
        @param  arg1 需要获取值的主键
        @return int 对应key值储存的结果
    */
    int getvalue(int key);



    /**
     *  将哈希表中键值为key的值设定为value。
        @name void setvalue(int, int);
        @param  arg1 需要设定的键值key
        @param  arg2 需要被设定的值value
        @return void
    */
    void setvalue(int key, int value);
};