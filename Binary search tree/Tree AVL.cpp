#include <iostream>
#include <queue>
using namespace std;
 
#define LH -1
#define EH 0
#define RH 1
 
struct AVLNode
{
    int x;
    char CSCB;
    AVLNode *pLeft;
    AVLNode *pRight;
};
 
typedef AVLNode * AVLTree;
 
void CreateAVLTree(AVLTree &Root)
{
    Root = NULL;
}
 
AVLNode *CreateAVLNode(int x)
{
    AVLNode *p = new AVLNode;
 
    if (!p) exit(1);
 
    p->CSCB = EH;
    p->x = x;
    p->pLeft = NULL;
    p->pRight = NULL;
 
    return p;
}
 
//cay con trai lech trai
void Rotate_Left_Left(AVLTree &Root)
{
    AVLNode *p;
 
    p = Root->pLeft;
    Root->pLeft = p->pRight;
    p->pRight = Root;
 
    switch (p->CSCB)
    {
    case LH:
        Root->CSCB = EH;
        p->CSCB = EH;
        break;
    case EH:
        p->CSCB = RH;
        Root->CSCB = LH;
        break;
    }
 
    Root = p;
}
 
//cay con phai lech phai
void Rotate_Right_Right(AVLTree &Root)
{
    AVLNode *p;
 
    p = Root->pRight;
    Root->pRight = p->pLeft;
    p->pLeft = Root;
 
    switch (p->CSCB)
    {
    case EH:
        Root->CSCB = RH;
        p->CSCB = EH;
        break;
    case RH:
        p->CSCB = EH;
        Root->CSCB = EH;
        break;
    }
 
    Root = p;
}
 
//cay con phai lech trai
void Rotate_Right_Left(AVLTree &Root)
{
    AVLNode *p1, *p2;
 
    p1 = Root->pRight;
    p2 = p1->pLeft;
    Root->pRight = p2->pLeft;
    p1->pLeft = p2->pRight;
    p2->pLeft = Root;
    p2->pRight = p1;
 
    switch (p2->CSCB)
    {
    case LH:
        Root->CSCB = EH;
        p1->CSCB = RH;
        break;
    case EH:
        Root->CSCB = EH;
        p1->CSCB = EH;
        break;
    case RH:
        Root->CSCB = LH;
        p1->CSCB = EH;
        break;
    }
 
    p2->CSCB = EH;
    Root = p2;
}
 
//cay con trai lech phai
void Rotate_Left_Right(AVLTree &Root)
{
    AVLNode *p1, *p2;
 
    p1 = Root->pLeft;
    p2 = p1->pRight;
    Root->pLeft = p2->pRight;
    p1->pRight = p2->pLeft;
    p2->pRight = Root;
    p2->pLeft = p1;
 
    switch (p2->CSCB)
    {
    case LH:
        p1->CSCB = EH;
        Root->CSCB = RH;
        break;
    case EH:
        Root->CSCB = EH;
        p1->CSCB = EH;
        break;
    case RH:
        Root->CSCB = EH;
        p1->CSCB = LH;
        break;
    }
 
    p2->CSCB = EH;
    Root = p2;
}
 
//Can bang khi cay lech trai
int BalanceLeft(AVLTree &Root)
{
    AVLNode *p;
 
    p = Root->pLeft;
 
    switch (p->CSCB)
    {
    case LH:
        Rotate_Left_Left(Root);
        return 2;
    case EH:
        Rotate_Left_Left(Root);
        return 1;
    case RH:
        Rotate_Left_Right(Root);
        return 2;
    }
}
 
//can bang cay lech phai
int BalanceRight(AVLTree &Root)
{
    AVLNode *p;
 
    p = Root->pRight;
 
    switch (p->CSCB)
    {
    case RH:
        Rotate_Right_Right(Root);
        return 2;
    case EH:
        Rotate_Right_Right(Root);
        return 1;
    case LH:
        Rotate_Right_Left(Root);
        return 2;
    }
}
 
//Chen 1 node vao cay AVL
int InsertNode(AVLTree &Root, int x)
{
    int Res;
    if (Root)
    {
        //gia tri da co trong cay
        if (Root->x == x) return 0;
 
        //Root->x > x
        //chen vao ben trai
        if (Root->x > x)
        {
            Res = InsertNode(Root->pLeft, x);
            if (Res < 2) return Res;
 
            //Res >= 2
            switch (Root->CSCB)
            {
            case RH:
                Root->CSCB = EH;
                return 1;
            case EH:
                Root->CSCB = LH;
                return 2;
            case LH:
                BalanceLeft(Root);
                return 1;
            }
        }
 
        //Root->x < x
        //chen vao ben phai
        else
        {
            Res = InsertNode(Root->pRight, x);
 
            if (Res < 2) return Res;
 
            //Res >= 2
            switch (Root->CSCB)
            {
            case LH:
                Root->CSCB = EH;
                return 1;
            case EH:
                Root->CSCB = RH;
                return 2;
            case RH:
                BalanceRight(Root);
                return 1;
            }
        }
    }
 
    Root = CreateAVLNode(x);
    return 2;
}
 
//Tim node the mang
int SearchStandFor(AVLTree &Root, AVLNode *&p)
{
    int Res;
 
    if (p->pLeft)
    {
        Res = SearchStandFor(Root, p->pLeft);
 
        if (Res < 2) return Res;
 
        switch (p->CSCB)
        {
        case LH:
            p->CSCB = EH;
            return 1;
        case EH:
            p->CSCB = RH;
            return 2;
        case RH:
            return BalanceRight(Root);
        }
    }
 
    Root->x = p->x;
    Root = p;
    p = p->pRight;
    return 2;
}
 
//Xoa 1 node tren cay
int DelNode(AVLTree &Root, int x)
{
    int Res;
 
    //Khong ton tai node nay tren cay
    if (!Root) return 0;
 
    //Qua duoc if tren tuc la ton tai
    //Root->x > x => Sang ben trai tim xoa
    if (Root->x > x)
    {
        Res = DelNode(Root->pLeft, x);
 
        //Neu co xoa thi Res = 1 hoac 2. 2 tuc thay doi chieu cao cay
        if (Res < 2) return Res;
 
        //Chieu cao bi thay doi
        switch (Root->CSCB)
        {
        case LH:
            Root->CSCB = EH;
            return 2;
        case EH:
            Root->CSCB = RH;
            return 1;
        case RH:
            return BalanceRight(Root);
        }
    }
 
    if (Root->x < x)
    {
        Res = DelNode(Root->pRight, x);
 
        if (Res < 2) return Res;
 
        switch (Root->CSCB)
        {
        case LH:
            return BalanceLeft(Root);
        case EH:
            Root->CSCB = LH;
            return 1;
        case RH:
            Root->CSCB = EH;
            return 2;
        }
    }
    else
    {
        //Root->x = x
        AVLNode *p1 = Root;
 
        if (Root->pLeft == NULL)
        {
            Root = Root->pRight;
            Res = 2;
        }
        else
        {
            if (Root->pRight == NULL)
            {
                Root = Root->pLeft;
                Res = 2;
            }
            else
            {
                Res = SearchStandFor(p1, Root->pRight);
 
                if (Res < 2) return Res;
                switch (Root->CSCB)
                {
                case RH:
                    Root->CSCB = EH;
                    return 2;
                case EH:
                    Root->CSCB = LH;
                    return 1;
                case LH:
                    return BalanceRight(Root);
                }
            }
            delete p1;
            return Res;
        }
    }
 
}
 
//Duyet theo muc
void Level(AVLTree Root)
{
    queue<AVLTree> q;
    AVLTree p;
 
    if (Root == NULL) return;
 
    p = Root;
    q.push(p);
 
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << p->x << endl;
 
        if (p->pLeft) q.push(p->pLeft);
        if (p->pRight) q.push(p->pRight);
    }
}
 
void Input(AVLTree &Root)
{
    int x;
    do
    {
        cout << "x = 0 de thoat: x = ";
        cin >> x;
        if (x == 0) break;
        InsertNode(Root, x);
    } while (1);
}
 
int main()
{
    AVLTree Root;
    CreateAVLTree(Root);
    InsertNode(Root, 112);
    InsertNode(Root, 114);
    InsertNode(Root, 545);
    InsertNode(Root, 777);
    InsertNode(Root, 864);
    InsertNode(Root, 870);
    InsertNode(Root, 900);
    InsertNode(Root, 475);
    InsertNode(Root, 863);
    InsertNode(Root, 865);
    InsertNode(Root, 867);
    InsertNode(Root, 875);
    InsertNode(Root, 888);
    InsertNode(Root, 915);
    DelNode(Root, 777);
    DelNode(Root, 888);
    Level(Root);
    system("pause");
}
