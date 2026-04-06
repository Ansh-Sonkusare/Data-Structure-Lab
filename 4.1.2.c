#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};

typedef struct node* NODE;

NODE createNode(int x) {
    //write your code here..

      NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    return temp;
    
}

NODE addNode(NODE first, int x) {
    //write your code here..
    
      NODE temp = createNode(x);

    if (first == NULL) {
        return temp;
    }

    NODE cur = first;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = temp;
    return first;
    
    
}

NODE concatenate(NODE t1, NODE t2) {
    //write your code here..
    
     if (t1 == NULL) return t2;
    if (t2 == NULL) return t1;

    NODE cur = t1;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = t2;
    return t1;

}

void displayList(NODE first) {
    //write your code here..
        NODE cur = first;

    while (cur != NULL) {
        printf("%d --> ", cur->data);
        cur = cur->next;
	}
    printf("NULL\n");
    
}