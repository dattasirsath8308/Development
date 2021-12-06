#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *Lchild;
    struct node *Rchild;
}NODE, *PNODE, **PPNODE;

void Insert(PPNODE Head, int no)
{
    PNODE newn = new NODE;

    newn ->data = no;
    newn -> Lchild =NULL;
    newn -> Rchild =NULL;

    if(*Head == NULL)
    {
        *Head = newn; // 33 line no inserst
    }
    else
    {
        PNODE temp = *Head;

        while(1) //while(true) // Unconditional  for(;;) -> for lop 
        {
            if(temp -> data == no)
            {
                cout<<"Duplicate node \n";
                delete newn; // jo agodar hota to jr prt aala tr tyala delete kra
                break;
            }
            //     100       51  >  27
            // else if(temp -> data > no) // small data
            else if(no < (temp -> data)) // small data
            {
                if(temp -> Lchild == NULL)
                {
                    temp -> Lchild = newn;
                    break;
                }
                temp = temp ->Lchild;

            }
            // else if(temp -> data < no) // large data -> right sathi Lchild
            //      27     21
            else if(no > (temp -> data)) // large data
            {
                //     
                if(temp -> Rchild ==NULL)
                {
                    //100 -> 200  = 900
                    temp -> Rchild = newn;
                    break;
                }
                //100  100  -> 900
                temp = temp ->Rchild;
            }
        }
    }
}

bool Search(PNODE Head , int no) // no search sathi
{
    // bool flag = false;
    if(Head == NULL) // if tree is empty
    {
        return false;
    }
    else // tree contains atleast one node
    {
        // while(1) // tree serch hot nahi toparyant firat rahto
        while( Head != NULL)
        {
            // 100 -> 51   ==  75
            if(Head -> data == no) // ha condition node sapdato
            {
                // flag = true;
                break;
            }

            else if(no > (Head ->data)) // 75 > 51  -> Rchild
            {
                Head = Head ->Rchild; // 100  = 100 -> 300 // 101 chya right jr asel tr Rchil kade ja

            }
            else if(no < (Head ->data))
            {
                Head = Head ->Lchild; // 100 = 100 -> 400 
            }
        }
        if(Head == NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

int Count(PNODE Head)
{
    static int iCnt = 0;
    if(Head != NULL)
    {
        iCnt++;
        Count(Head ->Lchild); // tree ahe tyamule 2 recursion func ghrtne
        Count(Head ->Rchild);

    }
    return iCnt;
}

int CountLeaf(PNODE Head) // juyana left right konich nahi
{
    static int iCnt = 0;
    if(Head != NULL)
    {
        if(Head ->Lchild == NULL && Head ->Rchild == NULL)
        {
            iCnt++;
       }
        CountLeaf(Head ->Lchild); // tree ahe tyamule 2 recursion func ghrtne
        CountLeaf(Head ->Rchild);

    }
    return iCnt;
}

int CountParent(PNODE Head) // juyana left right konich nahi
{
    static int iCnt = 0;
    if(Head != NULL)
    {
        if(Head ->Lchild != NULL || Head ->Rchild != NULL)
        {
            iCnt++;
       }
        CountParent(Head ->Lchild); // tree ahe tyamule 2 recursion func ghrtne
        CountParent(Head ->Rchild);

    }
    return iCnt;
}

void Inorder(PNODE Head) //LDR
{
    if(Head != NULL)
    {
        Inorder(Head ->Lchild); // L
        cout<<Head->data<<"\n"; // D
        Inorder(Head ->Rchild); // R
    }
}

void Postorder(PNODE Head) //LRD
{
    if(Head != NULL)
    {
        Postorder(Head ->Lchild); // L
        Postorder(Head ->Rchild); // R
        cout<<Head->data<<"\n"; // D

    }
}

void Preorder(PNODE Head) //DLR
{
    if(Head != NULL)
    {
        cout<<Head->data<<"\n"; // D
        Preorder(Head ->Lchild); // L
        Preorder(Head ->Rchild); // R

    }
}

int main()
{
    int no = 0 , iret = 0;
    PNODE first = NULL;
    bool bret = false;

    Insert(&first,51); // parent
    Insert(&first,21);
    Insert(&first,101);

    cout<<"Enter number to search \n";
    cin>>no;

    bret = Search(first,no);
    if(bret == true)
    {
        cout<<"Data is there \n";
    }
    else
    {
        cout<<"Data is Not there \n";

    }

    iret = Count(first);
    cout<<"Number of Node are :"<<iret<<"\n";

    iret = CountLeaf(first);
    cout<<"Number of Leaf Node are :"<<iret<<"\n";

    iret = CountParent(first);
    cout<<"Number of Leaf Node are :"<<iret<<"\n";

    cout<<"Inorder \n";
    Inorder(first);


    cout<<"Postorder \n";
    Postorder(first);


    cout<<"Preorder \n";
    Preorder(first);

    return 0;
}

//  L   D   R

// D = 51 Focus on D
/*
Inorder   L -D -R  //21 51 101 

Preorder   D - L -R  // 51  21 101 

Post-order   L -R -D  // 21 101 51

*/