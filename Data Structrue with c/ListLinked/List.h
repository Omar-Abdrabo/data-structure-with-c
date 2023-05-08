typedef int EntryType ;

typedef struct listnode {
    EntryType entry;
    struct listnode *next;
}ListNode;

typedef struct {
    int Size;
    ListNode *head;
}listType;

void createList (listType *pl);
void insertElement (int pos , EntryType e , listType *pl);
void deleteElement (int pos , EntryType *pe , listType *pl);
int listFull (listType *pl);
int listEmpty (listType *pl);
int listSize (listType *pl);
void destroyList (listType *pl);
void treaversList (listType *pl , void (*pf) (EntryType e) );
void retrieveElement (int pos ,EntryType *pe , listType *pl) ;
void replaceElement (int pos ,EntryType *pe , listType *pl) ;


