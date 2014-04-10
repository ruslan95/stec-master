
#include <string>
 
template<class T> 
/*!
  Более детальное описание класса.
*/

class Stack  
{
public: 
	//! Конструктор.
        Stack():tail(0), head(0)    
        {
        }
          //! Деструктор.
        ~Stack() 
        {
              while(head)
              {
                  tail=head->next;
                  delete head;
                  head=tail;
              }
        }
 
        void push(T val)
        {
                Node* Temp;
                Temp=new Node;
                Temp->elem=val;
                if(tail==0)
                {
                        tail=Temp;
                }
                else
                {
                        Temp->next=tail;
                        tail=Temp;
                }
        }
 
        T top()
        {
                if(tail==0)
                {
                        throw std::string("Stack is empty!");
                }
                return tail->elem;
        }
 
        void pop()
        {
                if(tail==0)
                {
                        throw std::string("Stack is empty!");
                }
                Node* delptr=tail;
                tail=tail->next;
                delete delptr;
        }
 
        void print()
        {
                if(tail==0)
                {
                        throw std::string("Stack is empty!");
                }
                for(Node* ptr=tail; ptr!=0; ptr=ptr->next)
                {
                        std::cout<<ptr->elem<<' ';
                }
                std::cout<<'\n';
        }
private:
        struct Node
        {
                Node():elem(0), next(0)
                {
                }
                Node* next;
                T elem;
        };
        Node* head;
        Node* tail;
};
 
