/*ASSIGNMENT:-10
Q1. Write a program to create a SLL for storing the n cricket player details having members name and batting average.
Display only that player information whose batting average is greater than or equal to 50.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    char pname[10];
    char tname[10];
    int score;
    struct node *link;
};
struct node *start = NULL, *fresh, *ptr;
void create();
void traverse();
void check();
int main() {
    int n, i;
    printf("Enter the number of players data need to be entered: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter the player details (name, team name and score): ");
        create();
    }
    printf("\nAll players details are:");
    traverse();
    printf("\nThe details of players who have scored >= 50 are:");
    check();
    return 0;
}
void create() {
    char pname[10], tname[10];
    int s;
    scanf("%s %s %d", &pname, &tname, &s);
    fresh = (struct node*)malloc(sizeof(struct node));
    if (fresh == NULL) {
        printf("\nMemory insufficient!!!");
        return;
    }
    strcpy(fresh->pname, pname);
    strcpy(fresh->tname, tname);
    fresh->score = s;
    fresh->link = NULL;
    if (start == NULL) {
        start = fresh;
    } else {
        ptr = start;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = fresh;
    }
}
void traverse() {
    if (start == NULL) {
        printf("\nList is Empty!!!");
        return;
    }
    ptr = start;
    while (ptr != NULL) {
        printf("\n%s %s %d", ptr->pname, ptr->tname, ptr->score);
        ptr = ptr->link;
    }
}
void check() {
    if (start == NULL) {
        printf("\nList is Empty!!!!");
        return;
    }
    ptr = start;
    while (ptr != NULL) {
        if (ptr->score >= 50) {
            printf("\n%s %s %d", ptr->pname, ptr->tname, ptr->score);
        }
        ptr = ptr->link;
    }
}
