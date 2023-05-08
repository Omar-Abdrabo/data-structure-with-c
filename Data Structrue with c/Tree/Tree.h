typedef int KeyType;

#define EQ(a, b) ((a)==(b))
#define LT(a, b) ((a)<(b))
#define LE(a, b) ((a)<=(b))
#define GT(a, b) ((a)>(b))
#define GE(a, b) ((a)>=(b))
//#define EQ(a, b) (!strcmp((a), (b)))
//#define LT(a, b) (strcmp((a), (b))<0)
//#define LE(a, b) (strcmp((a), (b))<=0)
//#define GT(a, b) (strcmp((a), (b))>0)
//#define GE(a, b) (strcmp((a), (b))>=0)


typedef struct {
    int info;
    KeyType key;
} EntryType;

typedef struct treenode {
    EntryType data ;
    struct treenode *right;
    struct treenode *left;
}TreeNode;

typedef TreeNode * Tree;

typedef struct {
    TreeNode *root;
    int size;
    int depth;
}Tree2;

void creatTree (Tree *);
void creatTree2 (Tree2 *);

int treeEmpty (Tree *);
int treeEmpty2 (Tree2 *);

int treeFull (Tree *);
int treeFull2 (Tree2 *);

int treeSizeRec (Tree *);
int treeSize2 (Tree2 *);

int treeDepthRec(Tree *pt);
int treeDepth2 (Tree2 *pt);

void inOrderRec (Tree * , void (*pf)(EntryType ));
void inOrderRec2(Tree2 * , void (*pf)(EntryType ));

void clearTree (Tree *);
void clearTreeAux (Tree *);
void clearTree2 (Tree2 *);

void insertTreeRec (Tree * , EntryType *);
void insertTreeRec2 (Tree2 * , EntryType *);
void insertTreeRec2Aux(Tree * , EntryType *, int *);
void insertTreeItr (Tree * , EntryType *);

int findElementRec (Tree * , EntryType  *pe , KeyType key);
int findElementRec2 (Tree2 * , EntryType  *pe , KeyType key);
int findElementItr(Tree * , EntryType  *pe , KeyType key);

void deleteElement (Tree *pt);
int deleteElementItr(Tree *pt, KeyType key);
















