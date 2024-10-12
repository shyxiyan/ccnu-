#include "SeqList.h"

// 集合运算函数实现  
void Union(SeqList A, SeqList B, SeqList* C) {
    int i;
    for (i = 0; i < A.length; i++) {
        ListInsert_Sq(C, C->length + 1, A.elem[i]);
    }

    for (i = 0; i < B.length; i++) {
        if (LocateElem_Sq(*C, B.elem[i]) == 0) {
            ListInsert_Sq(C, C->length + 1, B.elem[i]);
        }
    }
}

void Intersection(SeqList A, SeqList B, SeqList* C) {
    // 找到 A 和 B 的交集  
    int i;
    for (i = 0; i < A.length; i++) {
        if (LocateElem_Sq(B, A.elem[i]) != 0) {
            ListInsert_Sq(C, C->length + 1, A.elem[i]);
        }
    }
}

void Difference(SeqList A, SeqList B, SeqList* C) {
    // A,B的差集
    int i;
    for (i = 0; i < A.length; i++) {
        if (LocateElem_Sq(B, A.elem[i]) == 0) {
            ListInsert_Sq(C, C->length + 1, A.elem[i]);
        }
    }
}

int main() {
    SeqList A, B, C;
    InitList_Sq(&A, LIST_INIT_SIZE, LISTINCREMENT);
    InitList_Sq(&B, LIST_INIT_SIZE, LISTINCREMENT);
    InitList_Sq(&C, LIST_INIT_SIZE, LISTINCREMENT);

    // 输入集合 A  
    printf("*************** 输入集合 A ***************\n");
    int numA;
    printf("集合 A 的元素个数 = ");
    scanf("%d", &numA);
    printf("输入集合 A 的元素 = ");
    int i;
    for (i = 0; i < numA; i++) {
        ElemType e;
        scanf("%d", &e);
        ListInsert_Sq(&A, i + 1, e);
    }

    // 输入集合 B  
    printf("*************** 输入集合 B ***************\n");
    int numB;
    printf("集合 B 的元素个数 = ");
    scanf("%d", &numB);
    printf("输入集合 B 的元素 = ");
    for (i = 0; i < numB; i++) {
        ElemType e;
        scanf("%d", &e);
        ListInsert_Sq(&B, i + 1, e);
    }

    // 进行操作  
    Union(A, B, &C);
    printf("A ∪ B = ");
    ListTraverse(C);

    ClearList_Sq(&C);
    Intersection(A, B, &C);
    printf("A ∩ B = ");
    ListTraverse(C);

    ClearList_Sq(&C);
    Difference(A, B, &C);
    printf("A - B = ");
    ListTraverse(C);

    ClearList_Sq(&C);
    Difference(B, A, &C);
    printf("B - A = ");
    ListTraverse(C);
    // 清理内存  
    DestroyList_Sq(&A);
    DestroyList_Sq(&B);
    DestroyList_Sq(&C);

    return 0;
}
