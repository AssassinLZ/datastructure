#include <iostream>
struct LinkNode
{
    int val;
    LinkNode *next;
    LinkNode(int x)
    : val(x)
    , next(nullptr)
    {}
};


LinkNode *tailinsert()
{
    LinkNode *tail = new LinkNode(10);
    LinkNode *head = tail;
    LinkNode *curr = tail;
    for(int i = 9; i >= 1; i--)
    {
        LinkNode *node = new LinkNode(i);
        head = node;
        head -> next = curr;
        curr = head;
    }
    LinkNode *tmp=head;
    while(tmp)
    {
        std::cout << tmp->val << " ";
        tmp = tmp->next;
    }
    printf("\nhahahahahah\n");
    return head;    
}

void printlist(LinkNode *head)
{

    LinkNode *tmp = head;
    while(tmp -> next != nullptr)
    {
        std::cout << tmp -> val << std::endl;
        tmp = tmp -> next;
    }
}

#if 0
LinkNode *reverse(LinkNode *head, int m, int n)
{
    LinkNode *phead = new LinkNode(-1);
    phead -> next = head;
    LinkNode *mstart = phead;
    LinkNode *nend = phead;
    for(int i = 0; i < m-1; i++)
    {
        mstart = mstart -> next;
    }
    std::cout << "mstart:";
    std::cout << mstart -> val << std::endl;
    for(int i = 0; i < n; i++)
    {
        nend = nend -> next;
    }
    LinkNode *start = mstart -> next;
    LinkNode *curr = start -> next;
    LinkNode *nxt = curr -> next;
    std::cout << "start -> val:" << start -> val << std::endl;
    std::cout << "curr -> val:" << curr -> val << std::endl;
    std::cout << "nxt -> val:" << nxt -> val << std::endl;
    printlist(head);
    mstart -> next -> next = nend -> next;
    mstart -> next = nend;
    std::cout << "mstart -> next -> val:" << mstart -> next -> val << std::endl;
    std::cout << "start -> next:" << start -> next -> val << std::endl;
    while(curr -> next != nend)
    {
        curr -> next = start;
        start = curr;
        curr = nxt;
        nxt = nxt -> next;
    }
    // printlist(head);


    // std::cout << "end:";
    // std::cout << nend -> val << std::endl;
   
    // LinkNode *pre = mstart -> next;
    // std::cout << "pre:" << pre -> val << std::endl;
    // LinkNode *start = pre -> next;
    // std::cout << "start:" << start -> val << std::endl;
    // pre -> next = nend -> next;
    // std::cout << "pre->next->val:" << pre->next->val << std::endl;

    // LinkNode *tmp = start -> next -> next;

    // std::cout << "pre:" << pre -> val << std::endl;
    // printlist(head);
    // while (tmp != nend) 
    // {
    //     start -> next = pre;
    //     pre = start;
    //     start = tmp;
    //     tmp = tmp -> next;
    // }
    // mstart -> next = nend;
    return phead;
}
#endif





#if 1
LinkNode* reverseBetween2(LinkNode* head, int m, int n) {
         //加个表头
        printf("a n s w e r \n");
        LinkNode* res = new LinkNode(-1);
        res->next = head;
        //前序节点
        LinkNode* pre = res; 
        //当前节点
        LinkNode* cur = head; 
        //找到m
        for(int i = 1; i < m; i++){ 
            pre = cur;
            cur = cur->next;
        }
        std::cout << "pre.val:" << pre -> val << std::endl;
        std::cout << "cur.val:" << cur -> val << std::endl;
        //从m反转到n
        printf("for loop:\n");
        for(int i = m; i < n; i++){ 
            LinkNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        //返回去掉表头
        return res->next; 
    }
#endif

#if 1
void reverseBetween1(LinkNode* head, int m, int n) 
{
    printf("f u c k\n");
    LinkNode *phead = new LinkNode(0);
    phead -> next = head;
    LinkNode *left = nullptr;
    LinkNode *right = nullptr;
    LinkNode *start = head;
    LinkNode *end =head;
    for(size_t i = 1; i < m; i++)
    {
        left = start;
        start = start -> next;
    }
    // std::cout << "start:" << (*start).val << std::endl;
    // std::cout << "left  :" << (*left).val << std::endl;
    for(size_t i =1; i < n; i++)
    {
        end = end -> next;
        right = end -> next;
    }
    std::cout << "end  :" << (*end).val << std::endl;
    std::cout << "right  :" << (*right).val << std::endl;
    LinkNode *curr = start -> next;
    LinkNode *pre = start;
    LinkNode *tail = end;
    left->next = end;
    pre->next = right;

    // std::cout << "pre :" << (*pre).val << std::endl;
    // std::cout << "curr :" << (*curr).val << std::endl;

    while(curr != right)
    {
        LinkNode *tmp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = tmp;    
    }
    LinkNode *fuck = phead;
    while(fuck)
    {
        std::cout << fuck->val << " ";
        fuck=fuck->next;
    }
    printf("\n");

}
#endif

int main()
{
    LinkNode *head = tailinsert();
    // printlist(head);
    reverseBetween1(head, 3, 7);
    // printlist(head);
    return 0;
}