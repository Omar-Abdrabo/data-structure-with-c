#define MAXQUEUE 6

typedef int EntryType ;

typedef struct {
        int first ;
        int rear ;
        int Size;
        EntryType entry [MAXQUEUE];
}queueType;

void creatQueue (queueType *pq);
void append (EntryType e , queueType *pq);
void remov (EntryType *pe , queueType *pq) ;
int queueFull (queueType *pq);
int queueEmpty (queueType *pq);
void treaversQueue (queueType *pq , void (*pf) (EntryType e) );
int queueSize (queueType *pq);
void clearQueue (queueType *pq);
