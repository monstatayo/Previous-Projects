/*COP 3502C Midterm Assignment Two
This program is written by: Gabriel Kim-Perez*/

#include <stdio.h> 
#include <stdlib.h> 

struct soldier {

    int number;
    struct soldier* prev;
    struct soldier* next;
  

};

struct soldier* head = NULL;
struct soldier* last = NULL;
int sentinel;


struct soldier* create_soldier(int sequence) {

    struct soldier* newSoldier = (struct soldier*)malloc(sizeof(struct soldier));
    struct soldier* temp1 = NULL;

    newSoldier->number = sequence;
      

    if (head != NULL) {

        temp1 = head;

        while (temp1->next != head) {

            temp1 = temp1->next;

        }

        temp1->next = newSoldier;
        newSoldier->prev = temp1;
        head->prev = newSoldier;
        newSoldier->next = head;

        head = newSoldier;
    }
  

    else {

        head = newSoldier;

        newSoldier->next = (head);
        newSoldier->prev = (head);
        last = head;
       
    }

  
    sentinel++;
    return newSoldier;
    
}


struct soldier* create_reverse_circle(int n) {

    struct soldier* circle = (struct soldier*)malloc(sizeof(struct soldier));

    int i;

    for (i = n; i > 0; i--) {

        create_soldier((n+1) - i);
       
    }

    return head;

}

struct soldier* rearrange_circle(struct soldier* head) {

    struct soldier* curr, *previous;

    int num;
    int i = 0;

    curr = head;
    previous = last;
  

  
    for (i = 0; i < (sentinel / 2); i++) {


        num = curr->number;
        curr->number = previous->number;

        previous->number = num;

        curr = curr->next;
        previous = previous->prev;

     
    }

    return head;

}


void display(struct soldier* head) {

   struct soldier* final =  (struct soldier*)malloc(sizeof(struct soldier));

    final = head;

    while (final->next != head) {

        printf("%d ", final->number);

        final = final->next;

    }

    printf("%d", final->number);



}

int kill(struct soldier* head, int n, int k) {

    struct soldier* curr, * executed;

    curr = head;
    executed = head;

    int cnt = 1;

    int cnt2 = 1;

    while (cnt < n) {

        cnt2 = 1;

        while (cnt2 < k) {

            curr = executed;
            executed = executed->next;

            cnt2++;

        }

        curr->next = executed->next;

        executed->next->prev = curr;

        free(executed);

        executed = curr->next;

        cnt++;
    }

    head->number = curr->number;
    head->next = head;
    head->prev = head;
    int survived = head->number;


    return survived;

}

int main() {

    struct soldier* list = (struct soldier*) malloc(sizeof(struct soldier));

    int n, k;

    printf("Input: \n");

    scanf("%d %d", &n, &k);


    printf("List: ");

    list = create_reverse_circle(n);

    display(list);

    printf("\nAfter ordering: ");

    list = rearrange_circle(list);

    display(list);

    printf("\nSurvived: %d \n", kill(head, n, k));

}
