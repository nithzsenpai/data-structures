struct ListNode* middleNode(struct ListNode* head) {
    int count;
    struct ListNode *temp=head;
    struct ListNode*current=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    if(count%2==0)
    {
        
        for(int i=0;i<((count/2)+1)-1;i++)
        {
            current=current->next;

        }
        return current;
    }
    else
    {
        for(int i=0;i<((count+1)/2)-1;i++)
        {
            current=current->next;

        }

        return current;

    }
}
