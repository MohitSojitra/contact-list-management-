//
//  main.cpp
//  oep_c++
//
//  Created by Mohit on 14/04/19.
//  Copyright © 2019 Mohit. All rights reserved.
//
// in this project we devloped a phone contact list
#include <iostream>
#include<string.h>
using namespace std;




class contact{
public:
    static int counter;
    long int number;
    char name[20];
    int rel;
    int cNumber = 0;
    contact *link;
    void inc(){
        cNumber = counter;
    }


};
int contact::counter = 0;

contact *first,*new1,*temp;





contact* add_contact(){
    temp = first;
    new1 = new contact;
    new1->link = NULL;
    cout<<"\n enter the number ";
    cin>>new1->number;
   
    cout<<"\n enter the name ";
    cin>>new1->name;
    
    cout<<"\n press 1: friend ";
    cout<<"\n press 2: relative ";
    cout<<"\n press 3: other ";
    cout<<"\n enter your relation ";
    cin>>new1->rel;
    
    if(temp == NULL){
        first = new1;
    }
    else{
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = new1;
        
        
    }
    temp->counter++;
    new1->inc();

 cout<<"\n you have total "<<temp->counter<<" number of contact in list";
   
    return first;
}

void display1(){
    temp = first;
    
    if(temp == NULL){
        cout<<"\n list is empty ";
    }
    else{
        while(true){
            if(temp == NULL){
                break;}
            cout<<"\n name : --  "<<temp->name<<"\n";
            cout<<"\n mobileNo : -- "<<temp->number<<"\n";
            switch (temp->rel) {
                case 1:
                    cout<<"\n relation : --  friend\n";
                   
                    break;
                case 2:
                    
                    cout<<"\n relation : --  relative\n";
                    break;
                case 3:
                    
                    cout<<"\n relation : --  other\n";
                    break;
                default:
                    break;
            }
            temp = temp->link;
        }
    }
}

contact *delete_contact(){
    temp = first;
    contact *temp1;
    temp1 = NULL;
    int ch;
    long int number1;
   
    
    if(temp == NULL){
        cout<<"\n list is empty \n";
    }
    else{
        
        cout<<"\n press 1:- delete by name ";
        cout<<"\n press 2:- delete by number ";
        cout<<"\n enter your choice ";
        cin>>ch;
        if(ch == 1){
            cout<<"\n enter name ";
            char name1[20];
            cin>>name1;
           
            
            while(temp != NULL){
                
                while(temp != NULL){
                    if( strcmp(name1, temp->name) == 0){
                        break;
                    }
                    
                    temp = temp->link;
                   
                    
                }
                if(temp == NULL){    // error is here
                    cout<<"\n contact not found ";
                    
                }
                else{
                    
                    cout<<"\n contact number = "<<temp->cNumber;
                    cout<<"\n name : --  "<<temp->name<<"\n";
                    cout<<"\n mobileNo : -- "<<temp->number<<"\n";
                    switch (temp->rel) {
                        case 1:
                            cout<<"\n relation : --  friend\n";
                            
                            break;
                        case 2:
                            
                            cout<<"\n relation : --  relative\n";
                            break;
                        case 3:
                            
                            cout<<"\n relation : --  other\n";
                            break;
                        default:
                            break;
                    }
                   
                }
                if(temp == NULL){
                    break;
                }
                else{
                    temp = temp->link; // errror
                    
                }
                
            }
            
            cout<<"\n which contact number you delete ";
            int count;
            cin>>count;
            temp = first;
            while(temp -> cNumber != count){
                temp1 = temp;
                temp = temp->link;
            }
         
            if(temp -> cNumber == count){
                temp1->link = temp->link; // error
                cout<<"\n delete successfully";
                free(temp);
            }
            else{
                cout<<"\n contact not found ";
            }
            
        }
        else if(ch == 2){
            cout<<"\n enter the number ";
            cin>>number1;
            while(temp->number != number1 && temp->link != NULL){
                temp1 = temp;
                temp = temp->link;
            }
            if(temp->number == number1){
                temp1->link = temp->link;
                cout<<"\n delete successfully";
                free(temp);
            }
            else{
                cout<<"\n contact not found ";
            }
        }
        
    }
    
    
    return first;
}

contact *find_contact(){
    int ch;
    temp = first;
    cout<<"\n press 1:- find by the name";
    cout<<"\n press 2:- find by the number";
    cout<<"\n press 3:- find by the relation";
    cin>>ch;
    
    switch(ch){
        case 1:
            cout<<"\n enter name ";
            char name1[20];
            cin>>name1;
            
            while(temp != NULL){
                
                while(temp != NULL){
                    if( strcmp(name1, temp->name) == 0){
                        break;
                    }
                
                    temp = temp->link;
                    
                }
                if(temp == NULL){    // error is here
                    cout<<"\n contact not found ";
                    
                }
                else{
                    cout<<"\n name : --  "<<temp->name<<"\n";
                    cout<<"\n mobileNo : -- "<<temp->number<<"\n";
                    switch (temp->rel) {
                        case 1:
                            cout<<"\n relation : --  friend\n";
                            
                            break;
                        case 2:
                            
                            cout<<"\n relation : --  relative\n";
                            break;
                        case 3:
                            
                            cout<<"\n relation : --  other\n";
                            break;
                        default:
                            break;
                    }
                }
                if(temp == NULL){
                    break;
                }
                else{
                    temp = temp->link; // errror
                    
                }
            }
            
            
            
            
            
            break;
        case 2:
            cout<<"\n enter number ";
            long int num1;
            cin>>num1;
            if(temp != NULL){
         
                while(temp->number != num1 && temp != NULL){
                    temp = temp->link;
                    
                }
                if(temp == NULL){    // error is here
                    cout<<"\n contact not found ";
                    
                }
                else{
                    cout<<"\n name : --  "<<temp->name<<"\n";
                    cout<<"\n mobileNo : -- "<<temp->number<<"\n";
                    switch (temp->rel) {
                        case 1:
                            cout<<"\n relation : --  friend\n";
                            
                            break;
                        case 2:
                            
                            cout<<"\n relation : --  relative\n";
                            break;
                        case 3:
                            
                            cout<<"\n relation : --  other\n";
                            break;
                        default:
                            break;
                    }
                }
          
            
            }
            else{
                cout<<"\n contact list are the empty";
            }
            
            
            
            
            break;
        case 3:
            int ch;
            cout<<"\n press 1: friend ";
            cout<<"\n press 2: relative ";
            cout<<"\n press 3: other ";
            cout<<"\n enter your relation ";
            cin>>ch;
            
            if(temp == NULL){
                cout<<"\n sorry your list is empty";
            }
            else{
                while(temp != NULL){
                   
                    while(temp->rel != ch && temp != NULL){
                       
                        temp = temp->link;
                        
                    }
                    if(temp == NULL){    // error is here
                        cout<<"\n contact not found ";
                        
                    }
                    else{
                        cout<<"\n name : --  "<<temp->name<<"\n";
                        cout<<"\n mobileNo : -- "<<temp->number<<"\n";
                        switch (temp->rel) {
                            case 1:
                                cout<<"\n relation : --  friend\n";
                                
                                break;
                            case 2:
                                
                                cout<<"\n relation : --  relative\n";
                                break;
                            case 3:
                                
                                cout<<"\n relation : --  other\n";
                                break;
                            default:
                                break;
                        }
                    }
                    if(temp == NULL){
                        break;
                    }
                    else{
                        temp = temp->link; // errror
                        
                    }
                }
                
               
            }
            
            break;
        default:
            cout<<"\n enter valid choice ";
            break;
    }
    
    
    
    
    
    return first;
}


int main(){
    while(1){
    int choice;
    cout<<"\n enter 1: for add contact ";
    cout<<"\n enter 2: for delete contact ";
    cout<<"\n enter 3: for find contact ";
    cout<<"\n enter 4: for show contact ";
    cout<<"\n enter 5: exit ";
    
        
    
    cout<<"\n enter your choice ";
    cin>>choice;
        
    switch (choice) {
        case 1:
            first = add_contact();
            break;
        case 2:
            first = delete_contact();
            break;
        case 3:
            first = find_contact();
            break;
        case 4:
            display1();
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
    }
    }
    
    
    return 0;
    
}

