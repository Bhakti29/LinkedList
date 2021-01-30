#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include "slist.h"

Slist slist_new()
{

    Slist s1 = {NULL,NULL,0};
    return s1;
}

uint32_t slist_length(const Slist *list)
{
    assert(list != NULL);
    return list->length;
}

//helper function which is not visible to outside

static Node* _get_new_node_(int32_t val)
{

    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data=val;
    newnode->next=NULL;

    return newnode;
}

//Adding node at the head location
Slist* slist_addnode_head(Slist *list,int32_t val)
{
    assert(list != NULL);
    Node *new_node = _get_new_node_(val);
    new_node->next = list->head;
    list->head=new_node;

    if(list->tail == NULL)
    {
        list->tail = new_node;
    }
    ++list->length;

    assert( (list->length == 1 && list->head == list->tail) ||
            (list->length > 1 && list->head != list->tail)
          );

    return list;
}

//Adding node at the tail of the list
Slist* slist_addnode_tail(Slist *list,int32_t val)
{
    assert(list != NULL);
    Node *new_node = _get_new_node_(val);
    if(list->tail != NULL)
    {
        list->tail->next=new_node;
        list->tail = new_node;
    }
    else
    {
        list->head=list->tail=new_node;
    }
    ++list->length;

    assert( (list->length == 1 && list->head == list->tail) ||
            (list->length > 1 && list->head != list->tail)
          );
    return list;
}

//Searching for a key in the list
uint8_t slist_lookup(const Slist *list,int32_t key)
{

    assert(list != NULL);
    Node *cur = list->head;

    for(cur=list->head; cur!=NULL; cur=cur->next)
    {
        if(cur->data == key)
        {
            break;
        }
    }
    return (cur != NULL);

}

