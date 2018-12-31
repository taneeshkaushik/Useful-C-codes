#include<stdio.h>
#include<stdlib.h>

typedef struct node{
                      int data;
                      struct node* prev;
                      struct node* next;
                     }node;

node* head=NULL;
node* tail=NULL; 



 void delete()
 {
    if(head==NULL)
      {
        return;
        }
      

    if(head->next==NULL)
     { 
       free(head);
       head=NULL;
       tail=NULL;
       return;
       
        }


     node *t=head;    
     head=t->next;
     t->next=NULL;
     free(t);
     t=NULL;
     return;
   }
   






void insert_beg(int nval)
 {

    if(tail==NULL)
      {
       
        tail=(node*)malloc(sizeof(node));
        tail->data=nval;
        tail->prev=NULL;
        head=tail;
        tail->next=NULL;
         return;
       }
   

   else if(tail->prev==NULL)
      {
         node *t;
        t=(node*)malloc(sizeof(node));
        t->next=tail;
        t->data=nval;
        t->prev=NULL; 
        head=t;
        tail->prev=t;
         return;   
         }

    else
    {  
       node *t;
       t=(node*)malloc(sizeof(node));
       t->next=head;
       t->data=nval;
       t->prev=NULL; 
       head->prev=t;      
       head=t;
      return;          
   
     }                                                                                                    


 }


void super_computer(unsigned int n)
 {  
    int b,a,c;
   insert_beg(1); 

  if(n==0||n==1);
     

 else
  {
    node *t;
    int i;
    unsigned int mod=0,carry=0,temp;


    for(i=2;i<=n;i++)
     {
        carry=0;
        t=tail;

        while(t!=NULL)
          {  
             mod=(((t->data)*i)+carry)%10;
             carry=(((t->data)*i)+carry)/10;
             (t->data)=mod; 
             t=t->prev;                        
            }
          
       while(carry!=0)
        { 
           insert_beg(carry%10);
           carry=carry/10;
         }

     }
  }

  node* p=head;
  node *q=tail;
  int i=0;
  while(q->data==0)
   { 
     i++;
     q=q->prev; 
      } 
   printf("%d  ",i);
  while(p!=NULL)
    {    
      printf("%d",p->data);
      p=p->next;
      }
return;
 
 }
 


void main()
{
  int n;
  scanf("%d",&n);
  unsigned int arr[n];
  int i;
   for(i=0;i<n;i++)
     scanf("%d",&(arr[i]));
  printf("\n");
     
   for(i=0;i<n;i++)
    { 
       
       super_computer(arr[i]);

        while(head!=NULL)
          {
             delete();
           
            }
           

       printf("\n");
    

        }
   

 }
 































