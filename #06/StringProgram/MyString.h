/*******************************************************************************
* FileName:         MyString.h
* Author:           super
* Student Number:   0000000000
* Date:             2020/03/18 13:50:28
* Version:          v1.0
* Description:      Data Structure Experiment #6
*******************************************************************************/

#ifndef MYSTRING_H
#define MYSTRING_H

class MyString{
private:
    char* myStr;
    int len;
public:
    /**
        构造函数
        @name MyString(const char*);
        @param  const char* 需要构建为String的字符串。
        @return
    */
    MyString(const char* str);

    //析构函数
    ~MyString();

    /**
     * 将字符串location的位置以及之后的位置替换为str
        @name replace(const char*, const int&);
        @param  const char* 需要替换的字符串
                const int& 需要替换的位置
        @return  void
    */
    void replace(const char* str, int location);

    /**
        返回字符串长度
        @name length()
        @param
        @return  int 字符串的长度
    */
    int length() const;


    /**
        查找str在字符串中第一次出现的位置
        @name length()
        @param const char* 需要查找的字符串
        @return  int 字符串str第一次出现的位置，如果没有出现，则返回-1.
    */
    int find(const char*) const;

    /**
        返回储存的字符串的C语言风格表示。
        @name c_string()
        @param
        @return  const char*  返回的C语言风格字符串。
    */
    const char* c_string() const;
};
#endif