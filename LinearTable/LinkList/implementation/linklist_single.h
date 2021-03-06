// 单链表的实现(带头节点)

#if !defined(_LINKLIST_SINGLE_H_)
#define _LINKLIST_SINGLE_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkList
{
    ElemType e;            // 数据域
    struct LinkList *next; // 后继节点
} LinkList;

LinkList CreateList(void);                               // 初始化函数
int Length(LinkList *L);                                 // 返回表长
LinkList *LocateElem(LinkList *L, ElemType e);           // 按值查找 返回指针指向元素所在节点 若无则返回null[注意空指针检验]
bool GetElem(LinkList *L, int i, ElemType *e);           // 按位查找 返回元素值e
void ListInsert_head(LinkList *L, ElemType e);           // 插入值为e的元素 头插法
void ListInsert_tail(LinkList *L, ElemType e);           // 插入值为e的元素 尾插法
void ListInsert_mid(LinkList *L, ElemType e, int index); // 插入值为e的元素 插入到第index位后面
bool ListDelete(LinkList *L, int i, ElemType *e);        // 删除第i个位置的元素并将值通过e返回
void PrintList(const LinkList *L);                       // 顺序打印单链表所有元素值
bool Empty(const LinkList *L);                           // 判断表是否为空
void DestroyList(LinkList *L);                           // 销毁表

// 功能实现
LinkList CreateList(void)
{
    LinkList *L = (LinkList *)malloc(sizeof(LinkList)); // 头节点
    L->next = NULL;
    return *L;
}

int Length(LinkList *L)
{
    int count = 0;
    LinkList *p = L;
    while (p->next != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

LinkList *LocateElem(LinkList *L, ElemType e)
{
    LinkList *p = L;
    while (p->next != NULL)
    {
        if (p->e == e)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

bool GetElem(LinkList *L, int i, ElemType *e)
{
    if (i > Length(L))
    {
        return false;
    }
    LinkList *p = L;
    int count = i;
    for (int i = 0; i < count; i++)
    {
        p = p->next;
    }
    *e = p->e;
    return true;
}

void ListInsert_head(LinkList *L, ElemType e)
{
    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    p->e = e;
    p->next = L->next;
    L->next = p;
}

void ListInsert_tail(LinkList *L, ElemType e)
{
    LinkList *p = L, *m;
    m = (LinkList *)malloc(sizeof(LinkList));
    m->e = e;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = m;
    m->next = NULL;
}

void ListInsert_mid(LinkList *L, ElemType e, int index)
{
    if (index <= Length(L))
    {
        LinkList *p = L, *m;
        m = (LinkList *)malloc(sizeof(LinkList));
        m->e = e;

        for (int i = 0; i < index; i++)
        {
            p = p->next;
        }
        m->next = p->next;
        p->next = m;
    }
    else
    {
        fprintf(stderr, "INSERT ERROR: index out of range!\n");
    }
}

bool ListDelete(LinkList *L, int i, ElemType *e)
{
    if (i > Length(L))
    {
        return false;
    }
    LinkList *p = L, *q;
    for (int j = 0; j < i - 1; j++)
    {
        p = p->next;
    }
    q = p->next;
    *e = q->e;
    p->next = q->next;
    free(q);
    return true;
}

void PrintList(const LinkList *L)
{
    LinkList *p = L->next;
    while (p->next != NULL)
    {
        printf("%d ", p->e);
        p = p->next;
    }
    printf("%d\n", p->e);
}

bool Empty(const LinkList *L)
{
    if (L->next == NULL)
    {
        return true;
    }
    return false;
}

void DestroyList(LinkList *L)
{
    int len = Length(L);
    ElemType e;
    for (int i = 0; i < len; i++)
    {
        ListDelete(L, 1, &e);
        printf("delete %d\n", e);
    }
    free(L);
    printf("List has been destroyed!\n");
}

#endif // _LINKLIST_SINGLE_H_
