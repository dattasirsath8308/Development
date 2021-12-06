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

    return 0;
}

//  L   D   R