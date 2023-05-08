#include "Tree.h"
#include  <stdlib.h>

void creatTree (Tree *pt) {
    *pt = NULL;
}

void creatTree2 (Tree2 *pt) {
    pt->root = NULL;
    pt->depth = 0;
    pt->size = 0;
}

int treeEmpty (Tree *pt) {
    return (!*pt);
}

int treeEmpty2 (Tree2 *pt) {
    return !pt->root;
}

int treeFull (Tree *pt) {
    return 0;
}

int treeFull2 (Tree2 *pt) {
    return 0;
}

int treeSizeRec (Tree *pt) {
    if (*pt)
        return 0 ;
    return (1 + treeSizeRec(&(*pt)->left) + treeSizeRec(&(*pt)->right) );
}

int treeSize2 (Tree2 *pt) {
    return pt->size;
}

int treeDepthRec(Tree *pt){
   if (!*pt)
      return 0;
    int a=treeDepthRec(&(*pt)->left);
    int b=treeDepthRec(&(*pt)->right);
    return (a>b)? 1+a : 1+b;
}

int treeDepth2(Tree2 *pt){
   return (pt->depth);
}


void inOrderRec (Tree *pt , void (*pf)(EntryType e)) {
    if (*pt) {
        inOrderRec(&(*pt)->left, pf);
        (*pf) ((*pt)->data);
        inOrderRec(&(*pt)->right , pf);
    }
}

void inOrderRec2(Tree2 *pt , void (*pf)(EntryType e)) {
    inOrderRec(&pt->root,pf);
}

void clearTreeAux (Tree *pt) {
    if(*pt) {
        clearTree(&(*pt)->left);
        clearTree(&(*pt)->right);
        free(*pt);
    }
}

void clearTree (Tree *pt) {
    clearTreeAux(pt);
    *pt = NULL;
}

void clearTree2 (Tree2 *pt) {
    clearTree(&pt->root);
    pt->size = 0;
    pt->depth = 0;
}

void insertTreeRec (Tree *pt , EntryType *pe) {
    if (!*pt) {
        TreeNode *pn = (Tree) malloc(sizeof (TreeNode));
        pn->data = *pe ;
        pn->left = NULL;
        pn->right = NULL;
        *pt = pn;
    } else if (LT( pe->key, (*pt)->data.key) ) {
        insertTreeRec(&(*pt)->left, pe);
    } else {
        insertTreeRec(&(*pt)->right, pe);
    }
}

void insertTreeRec2Aux(Tree *pt , EntryType *pe, int *pdepth) {
    if (!*pt) {
        TreeNode *pn = (Tree) malloc(sizeof (TreeNode));
        pn->data = *pe ;
        pn->left = NULL;
        pn->right = NULL;
        *pt = pn;
    } else if (LT( pe->key, (*pt)->data.key) ) {
        insertTreeRec2Aux(&(*pt)->left, pe,pdepth);
    } else {
        insertTreeRec2Aux(&(*pt)->right, pe,pdepth);
    }
    (*pdepth) ++;
}

void insertTreeRec2(Tree2 *pt, EntryType *pe) {
    int d = 0;
    insertTreeRec2Aux(&pt->root , pe , &d);
    if (d > pt->depth)
        pt->depth = d;
    pt->size ++ ;
}

void insertTreeItr (Tree *pt , EntryType *pe) {
    TreeNode *p , *curr , *prev ;
    p = (Tree) malloc(sizeof (TreeNode));
    p->data = *pe ;
    p->left = NULL;
    p->right = NULL;
    if (!(*pt)) {
        *pt = p ;
    } else {
        curr = *pt ;
        while (curr) {
            prev = curr ;
            if (LT(pe->key , curr->data.key))
                curr = curr->left;
            else
                curr = curr->right;
        }
        if (LT(pe->key , prev->data.key))
            prev->left = p ;
        else
            prev->right = p ;
    }
}

int findElementRec (Tree *pt , EntryType  *pe , KeyType key) {
    if (!(*pt))
        return 0 ;
    if (EQ (key, ((*pt)->data.key))) {
        *pe = (*pt)->data;
        return 1 ;
    } else if (LT (key, (*pt)->data.key))
        findElementRec(&(*pt)->left, pe, key);
     else
        findElementRec(&(*pt)->right, pe, key);
}

int findElementRec2 (Tree2 *pt , EntryType  *pe , KeyType key) {
    return findElementRec(&pt->root , pe , key);
}

int findElementItr(Tree *pt , EntryType  *pe , KeyType key) {
    int found = 0;
    TreeNode *p = *pt;
    while (p &&  !(found = EQ (key, p->data.key) ) ) {
        if (LT (key, p->data.key) )
            p = p->left;
        else
            p = p->right;
    }
    if (found)
        *pe = p->data;
    return found;
}

void deleteElement (Tree *pt) {
    TreeNode *q = *pt , *r ;
    if(!(*pt)->left) {
        *pt = (*pt)->right;
    } else if (!(*pt)->right) {
        *pt = (*pt)->left;
    } else {
        q = (*pt)->left ;
        if(!q->right){
         (*pt)->data=q->data;
         (*pt)->left=q->left;
        }else {
            do {
                r = q;
                q = q->right ;
            }while (q->right);
            (*pt)->data = q->data;
            r->right = q->left ;
        }
    }
    free(q);
}

int deleteElementItr(Tree *pt, KeyType key) {
    TreeNode *q = *pt ;
    int found = 0 ;
    while (q && ! (found = EQ (key, q->data.key) ) ) {
        if (LT (key, q->data.key))
            q = q->left;
        else
            q = q->right ;
    }
    if (found)
        deleteElement(&q);
    return found ;
}






















