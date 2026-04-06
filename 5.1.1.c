#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;

// Create a new node with given data
NODE createNodeInCLL(int data) {
    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Create CLL with n nodes
NODE createCLL(     int n  ) {
	
// write your code here...
	 int data;

    NODE head = NULL, temp = NULL, last = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        temp = createNodeInCLL(data);
        if (head == NULL) {
            head = temp;
        } else {
            last->next = temp;
        }
        last = temp;
    }
    if (last != NULL) {
        last->next = head; // make it circular
    }
    return head;


}

// Traverse CLL
void traverseListInCLL(  NODE head    ) {

// write your code here...
	  if (head == NULL) {
        printf("CLL is empty\n");
        return;
    }
    NODE temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");


}

// Insert at given position in CLL
NODE insertAtPositionInCLL(  NODE head , int pos, int data       ) {
	
//write your code here..
 NODE temp = createNodeInCLL(data);
    if (head == NULL) {
        if (pos == 1) { // insert in empty list
            temp->next = temp;
            return temp;
        } else {
            printf("Position not found\n");
            return head;
        }
    }

    if (pos == 1) { // insert at beginning
        NODE last = head;
        while (last->next != head) last = last->next;
        temp->next = head;
        last->next = temp;
        head = temp;
        return head;
    }

    NODE curr = head;
    int count = 1;
    while (count < pos - 1 && curr->next != head) {
        curr = curr->next;
        count++;
    }

    if (count == pos - 1) {
        temp->next = curr->next;
        curr->next = temp;
    } else {
        printf("Position not found\n");
    }
    return head;

	
}

// Delete node at given position in CLL
NODE deleteAtPositionInCLL(   NODE head , int pos    ) {
	
	if (head == NULL) {
        printf("CLL is empty\n");
        return head;
    }

    NODE curr = head, prev = NULL;

    // Deleting first node
    if (pos == 1) {
        NODE last = head;
        while (last->next != head) last = last->next;

        if (head->next == head) { // only one node
            printf("Deleted element: %d\n", head->data);
            free(head);
            return NULL;
        }

        last->next = head->next;
        NODE temp = head;
        head = head->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return head;
    }

    int count = 1;
    prev = head;
    curr = head->next;
    while (count < pos - 1 && curr != head) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (count == pos - 1 && curr != head) {
        prev->next = curr->next;
        printf("Deleted element: %d\n", curr->data);
        free(curr);
    } else {
        printf("Position not found\n");
    }

    return head;
	
}

// Reverse CLL
NODE reverseCLL(    NODE head     ) {
	
//write your code here...
 if (head == NULL || head->next == head) return head;

    NODE prev = NULL, curr = head, nextNode;
    NODE first = head;

    do {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    } while (curr != head);

    first->next = prev; // complete circular link
    head = prev;

    return head;

}

// Concatenate two CLLs
NODE concatCLL(     NODE first , NODE second      ) {

//write your code here..
   if (first == NULL) return second;
    if (second == NULL) return first;

    NODE last1 = first;
    while (last1->next != first) last1 = last1->next;

    NODE last2 = second;
    while (last2->next != second) last2 = last2->next;

    last1->next = second;
    last2->next = first;

    return first;


}

int main() {
    NODE first = NULL, second = NULL;
    int x, pos, op, n;

    while (1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                first = createCLL(n);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 5:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    traverseListInCLL(first);   // <-- display reversed list
                }
                break;
            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d", &n);
                second = createCLL(n);
                first = concatCLL(first, second);
                printf("Concatenated CLL:\n");
                traverseListInCLL(first);
                break;
            case 7:
                exit(0);
        }
    }
}