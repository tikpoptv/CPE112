void test(node **start){
    node *newnode,*ptr;
    int val;

    printf("Enter");
    scanf("%d", &val);
    newnode = (node*)malloc(sizeof(node));  //create a new
    newnode->data = val;  //set value
    newnode->next = NULL;  //set next to NULL

    ptr = *start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        ptr->next = newNode;
    }
    
}

