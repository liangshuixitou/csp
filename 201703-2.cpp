#include <iostream>
using namespace std;

typedef struct ListNode
{
    struct ListNode *pre;
    struct ListNode *nex;
    int data;
} LNode;

int main()
{
    int n, m;
    int num, step;
    cin >> n >> m;
    LNode *p, *t, *head;
    head = new LNode;
    head->nex = head->pre = NULL;

    //创建双向链表
    for (int i = n; i > 0; --i)
    {
        p = new LNode;
        p->data = i;
        p->nex = head->nex;
        if (head->nex)
        {
            head->nex->pre = p;
        }
        head->nex = p;
        p->pre = head;
    }

    //进行排队操作
    while (m--)
    {
        cin >> num >> step;
        //1. 查找到那个学号
        p = head->nex;
        while (p && p->data != num)
        {
            p = p->nex;
        }
        //2.进行移动(分类讨论)
        t = p;
        if (step > 0)
        {
            while (step > 0 && t->nex)
            {
                step--;
                t = t->nex;
            }
            if (p != t)
            {
                p->pre->nex = p->nex;
                if (p->nex)
                {
                    p->nex->pre = p->pre;
                }
                p->nex = t->nex;
                p->pre = t;
                if (t->nex)
                {
                    t->nex->pre = p;
                }
                t->nex = p;
            }
        }

        if (step < 0)
        {
            while (step < 0 && t->pre != head)
            {
                step++;
                t = t->pre;
            }
            if (p != t)
            {
                p->pre->nex = p->nex;
                if (p->nex)
                    p->nex->pre = p->pre;
                p->pre = t->pre;
                p->nex = t;
                t->pre->nex = p;
                t->pre = p;
            }
        }
    }

    p = head->nex;
    while (p)
    {
        cout << p->data << " ";
        p = p->nex;
    }
    system("pause");
    return 0;
}