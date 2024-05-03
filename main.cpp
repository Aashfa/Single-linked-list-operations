#include <iostream>
using namespace std;
class Node{
	    public:
		    int value;
		    Node *nxtnode;
			Node(){
				value=0;
				nxtnode=NULL;
			}//constructor
	};//Node class
	
class SLL{
	Node *head;
	Node *current;
	Node *previous;
	Node *temp;
	Node *next;
	public:
		int size;
		SLL(){ head=NULL;
			size=0;
		}//constructor
		void reverse(){
			    previous=NULL;
			  	current=head;
			  	next=NULL;		
			  	while(current!=NULL){
                    next = current->nxtnode;
                    current->nxtnode = previous;
                    previous = current;
                    current = next;
                } 
                       head=previous;
		}//reverse
		void display_entire_list(){
			current=head;
				while(current!=NULL){
					cout<<" "<<current->value;
					current=current->nxtnode;}
		}//display entire list
		void create_empty_list(){
			Node * head=NULL;
			
		}//create list
		
		void insertion(){
	        char choice;
	        int v;
    	    cout<<"\t\t === Insertion Menu ===\n";
		    cout<<"\t a. At the start of list\n";
		    cout<<"\t b. At the specific location\n";
		    cout<<"\t c. At the end of list\n";
		    cout<<"\t d. Exit\n";
		    do{
		      cout<<"Enter choice (in lower case) : ";
		      cin>>choice;
		      if(choice!='a' && choice!='b' && choice!='c' && choice!='d'){
		      	cout<<"Invalid choice!\n";
			  }//if
			  }while(choice!='a' && choice!='b' && choice!='c' && choice!='d');
			  if(choice=='d'){
			  	exit(1);
			  }
			  cout<<"Enter value : ";
			  cin>>v;
			  switch(choice){
			  	case'a':{
						Node* newnode=new Node;
				        newnode->value=v;
				        newnode->nxtnode=NULL;
				        if(head==NULL){
					       head=newnode;
         			    }
				        else{
					       newnode->nxtnode=head;
					       head=newnode;
				        }
						}
						//insert at start
				        break;
			    case'b':{
				        int pos;
				        do{
			    	      cout<<"Enter position: ";
			    	      cin>>pos;
			    	      if (pos < 1 || pos > size + 1) {
                            cout << "Invalid position" << endl;
                          }
                          }while(pos < 1 || pos > size + 1);
			    	    
				          Node* newnode = new Node;
                          newnode->value = v;
                          if(head==NULL){
					        head=newnode;
         			      }
                          else if (pos == 1) {
                            newnode->nxtnode = head;
                            head = newnode;
                          }
                          else{
                            previous = head;
                            for (int i = 1; i<pos-1; i++) {
                               previous = previous->nxtnode;
                            }
                            newnode->nxtnode = previous->nxtnode;
                            previous->nxtnode = newnode;
                            }
                        }
                        //insert at specific location
			    	    break;
			  	case'c':
			  		{ Node* newnode=new Node;
				      newnode->value=v;
				      newnode->nxtnode=NULL;
					  if(head == NULL){
					   head=newnode;
				      }
				      else{
				        current =head;
				        while(current->nxtnode!=NULL){
					      current=current->nxtnode;
				        }
				        current->nxtnode=newnode;
				      }
			  		}
					//insert at end
			  }//switch
			  size++;
		}//insertion
		
		void deletion(){
			char choice;
    	    cout<<"\t\t === Deletion Menu ===\n";
		    cout<<"\t a. At the start of list\n";
		    cout<<"\t b. At the specific location\n";
		    cout<<"\t c. At the end of list\n";
		    cout<<"\t d. Delete by value\n";
		    cout<<"\t e. Exit\n";
		    do{
		      cout<<"Enter choice (in lower case) : ";
		      cin>>choice;
		      if(choice!='a' && choice!='b' && choice!='c' && choice!='d' && choice!='e'){
		      	cout<<"Invalid choice!\n";
			  }//if
			}while(choice!='a' && choice!='b' && choice!='c' && choice!='d'&& choice!='e');
			if(choice=='e'){
			  	exit(1);
			}
			if(head==NULL){
			  	cout<<"\n No nodes are exist.\n";
			}
			else{
			    switch(choice){
			  	    case'a':
						temp=head;
						head=head->nxtnode;
						delete temp;
						cout<<"\nNode deleted.\n";
						size--;
					    //delete at start
					    break;
			  	    case'b':
			  		    int pos;
				        do{
			    	        cout<<"Enter position: ";
			    	        cin>>pos;
			    	        if (pos < 1 || pos > size + 1) {
                               cout << "Invalid position" << endl;
                            }
                        }while(pos < 1 || pos > size + 1);
                        if(pos==1){
                        	temp=head;
						    head=head->nxtnode;
						    delete temp;
						    cout<<"\nNode deleted.\n";
						    size--;
                        }
						else{
							temp=head;
			  		        previous=head;
			  		         for (int i = 0; i<pos-1; i++) {
			  		    	    previous=temp;
			  		    	    temp=temp->nxtnode;
						    }
						    previous->nxtnode=temp->nxtnode;
						    delete temp;
						    cout<<"\nNode deleted.\n";
						    size--;}
                        //delete at specific location
                        break;
			  	    case'c':
			  		    temp=head;
			  		    previous=head;
			  		    while(temp->nxtnode!=NULL){
			  		    	previous=temp;
			  		    	temp=temp->nxtnode;
						}
						previous->nxtnode=NULL;
						delete temp;
						cout<<"\nNode deleted.\n";
						size--;
				    	//delete at end of list
			  	    case'd':
			  	    	{
						int value;
			  	    	bool del=false;
			  	    	cout<<"Enter value: ";
			  	    	cin>>value;
			  	    	current = head; 
                        previous = NULL; 
                        while (current != NULL) { 
                           if (current->value == value) { 
                               if (previous == NULL) { 
                                  head = current->nxtnode; 
                                }
								else { 
                                   previous->nxtnode = current->nxtnode;
                                }
                               temp = current; 
                               current = current->nxtnode; 
                               delete temp;
							   del=true;
							   cout<<"Node deleted"<<endl;
							   size--; 
                            }
							else { 
                                previous = current; 
                                current = current->nxtnode; 
                            }
                        }
					    if(del==false){
					    	cout<<"Value is not present in list."<<endl;
						}
					}//delete by value
			  		    
			    }//switch
		}//else
			
		}//deletion
		
		void display(){
			char choice;
    	    cout<<"\t\t === Display Menu ===\n";
		    cout<<"\t a. Entire list\n";
		    cout<<"\t b. Even Values\n";
		    cout<<"\t c. Odd vaues\n";
		    cout<<"\t d. Ascending order\n";
		    cout<<"\t e. Descending order\n";
		    cout<<"\t f. Reverse order\n";
		    cout<<"\t g. Exit\n";
		    do{
		      cout<<"Enter choice (in lower case) : ";
		      cin>>choice;
		      if(choice!='a' && choice!='b' && choice!='c' && choice!='d' && choice!='e' && choice!='f'&& choice!='g'){
		      	cout<<"Invalid choice!\n";
			  }//if
			}while(choice!='a' && choice!='b' && choice!='c' && choice!='d'&& choice!='e' && choice!='f'&& choice!='g');
			if(choice=='g'){
			  	exit(1);
			}
            switch(choice){
            	case'a':
            		if (head==NULL){
            			cout<<"list is empty";
					}
					else{
            		display_entire_list();
            	    }
            		break;
            	case'b':
            		if (head==NULL){
            			cout<<"list is empty";
					}
					else{bool even=false;
						current=head;
				        while(current!=NULL){
					    if(current->value%2==0){
					    	even=true;
					        cout<<" "<<current->value;}
					    current=current->nxtnode;}
					    if (even==false){
					    	cout<<"No even value is present.\n";
						}
					}
					    break;
            	case'c':
            		if (head==NULL){
            			cout<<"list is empty";
					}
					else{bool odd=false;
						current=head;
				        while(current!=NULL){
					    if(current->value%2==1){
					      odd=true;
					      cout<<" "<<current->value;}
					    current=current->nxtnode;}
					    if (odd==false){
					    	cout<<"No odd value is present.\n";
						}
					}
					    
					    break;
            	case'd':
            		{if (head==NULL){
            			cout<<"list is empty";
					}
					else{
					    int count=0;
            		    int array[size];
            		    current=head;
				        while(current!=NULL){
				     	  array[count]=current->value;
				    	  current=current->nxtnode;
						  count++;
					    }
					    for(int i=0;i<size-1;i++){
                            for(int j=0;j<size-i-1;j++){
                                if(array[j]>array[j+1]){
                                  int temp=array[j];
                                  array[j]=array[j+1];
                                  array[j+1]=temp;
                                }
                            }
                        }
                        cout<<"\nAscending order"<<endl;
					    for(int i=0;i<size;i++){
						   cout<<" "<<array[i];
					    }
					}
					break;}
            	case'e':
            		{if(head==NULL){
            			cout<<"list is empty";
					 }
					else{
					    int count=0;
            		    int array[size];
            		    current=head;
				        while(current!=NULL){
				        	array[count]=current->value;
				    	    current=current->nxtnode;
						    count++;
					    }
					    for(int i=0;i<size-1;i++){
                            for(int j=0;j<size-i-1;j++){
                                if(array[j]<array[j+1]){
                                  int temp=array[j];
                                  array[j]=array[j+1];
                                  array[j+1]=temp;
                                }
                            }
                        }
                        cout<<"\nDescending order"<<endl;
					    for(int i=0;i<size;i++){
					     	cout<<" "<<array[i];
					    }
					}
					 break;}

            	case'f':
            		if(head==NULL){
            			cout<<"List is Empty\n";
					}
					else{
            		reverse();
				    display_entire_list();
				    reverse();}
            		break;
			}//switch
		}//display
		
		void swapping(){
			char choice;
    	    cout<<"\t\t === Swapping Menu ===\n";
		    cout<<"\t a. Swap by location\n";
		    cout<<"\t b. Swap by value\n";
		    cout<<"\t c. Exit\n";
		    do{
		      cout<<"Enter choice (in lower case) : ";
		      cin>>choice;
		      if(choice!='a' && choice!='b' && choice!='c'){
		      	cout<<"Invalid choice!\n";
			  }//if
			}while(choice!='a' && choice!='b' && choice!='c');
			if(choice=='c'){
			  	exit(1);
			}
			if(head==NULL){
				cout<<"List is empty.\n";
			}
			else if(size<2){
				cout<<"Value can not be swap because ther is only one value in list .\n";
			  }
			else{
			switch(choice){
			  	case'a':
			  		int loc1,loc2;
			  		do{
			  		cout<<"Enter location1 you want to swap value : ";
			  		cin>>loc1;
			  		if(loc1 < 1 || loc1 > size){
			  			cout<<"Invalid location!\nEnter again!\n";
					}}while(loc1 < 1 || loc1 > size);
			  		do{
			  		cout<<"Enter location2 you want to swap value with : ";
			  		cin>>loc2;
			  		if(loc2 < 1 || loc2> size){
			  			cout<<"Invalid location!\nEnter again!\n";
					}}while(loc2 < 1 || loc2 > size);
			  		
			  		Node* pos1;
					pos1 = head;
                    Node* pos2 ;
					pos2= head;
					int value;
                    for(int i = 1; i < loc1; i++){
                        pos1 = pos1->nxtnode;
                    }
                    for(int i = 1; i < loc2; i++){
                        pos2 = pos2->nxtnode;
                    }
                    value=pos1->value;
                    pos1->value=pos2->value;
                    pos2->value=value;
			  		break;
			  	case'b':
			  		bool present1=false;
			  		bool present2=false;
			  		int value1,value2;
			  		do{
			  		cout<<"Enter value1 you want to swap: ";
			  		cin>>value1;
			  		current=head;
				    while(current!=NULL){
					if(current->value==value1){
						present1=true;
					}
					current=current->nxtnode;} 
					if(present1==false){
						cout<<"\nThis value is not present in list.\n";
						cout<<"Enter again!\n";
					}
					}while(present1==false);
			  		
			  		do{
			  		cout<<"Enter value2 you want to swap: ";
			  		cin>>value2;
			  		current=head;
				    while(current!=NULL){
					if(current->value==value2){
						present2=true;
					}
					current=current->nxtnode;} 
					if(present2==false){
						cout<<"\nThis value is not present in list.\n";
						cout<<"Enter again!\n";
						
					}
					}while(present2==false);
	
			  		current=head;
			  		while(current!=NULL){
					if(current->value==value1||current->value==value2){
						if(current->value==value2){
						current->value=value1;		
				     	}
				     	else if(current->value==value1){
						current->value=value2;
					}
					}
					    current=current->nxtnode;}
					  break;
			}//switch
		}//else
		}//swapping
		
		void copy(){
			char choice;
    	    cout<<"\t\t === Copy Menu ===\n";
		    cout<<"\t a. Copy one value to other location\n";
		    cout<<"\t b. Copy multiple value from one location to other location\n";
		    cout<<"\t c. Copy entire list values to another list\n";
		    cout<<"\t d. Exit\n";
		    do{
		      cout<<"Enter choice (in lower case) : ";
		      cin>>choice;
		      if(choice!='a' && choice!='b' && choice!='c' && choice!='d'){
		      	cout<<"Invalid choice!\n";
			  }//if
			}while(choice!='a' && choice!='b' && choice!='c' && choice!='d');
			if(choice=='d'){
			  	exit(1);
			}
			switch(choice){
			  	case'a':
		            int loc1,loc2;
			  		do{
			  		cout<<"Enter location which value you want to copy : ";
			  		cin>>loc1;
			  		if(loc1 < 1 || loc1 > size){
			  			cout<<"Invalid location!\nEnter again!\n";
					}}while(loc1 < 1 || loc1 > size);
			  		do{
			  		cout<<"Enter location you want to paste value : ";
			  		cin>>loc2;
			  		if(loc2 < 1 || loc2> size+1){
			  			cout<<"Invalid location!\nEnter again!\n";
					}}while(loc2 < 1 || loc2 > size+1);
			  		Node* pos1;
					pos1 = head;
                    Node* pos2 ;
					pos2= head;
                    for(int i = 1; i < loc1; i++){
                        pos1 = pos1->nxtnode;
                    }
                    if(loc2==size+1){
                       size++;
                       Node* newnode=new Node;
				       newnode->value=pos1->value;
				       newnode->nxtnode=NULL;
				       current =head;
				       while(current->nxtnode!=NULL){
					      current=current->nxtnode;
				        }
				        current->nxtnode=newnode;
				      }
					
                    else{
                      for(int i = 1; i < loc2; i++){
                        pos2 = pos2->nxtnode;
                      }
                    pos2->value=pos1->value;}
			  		
				      break;
			  		
			  	case'b':
			  		{int arrsize;
					int arr[arrsize];
			  		int loc1,loc2,location;
			  		do{
			  		cout<<"Enter location from which value you want to copy : ";
			  		cin>>loc1;
			  		if(loc1 < 1 || loc1 > size){
			  			cout<<"Invalid location!\nEnter again!\n";
					}}while(loc1 < 1 || loc1 > size);
			  		do{
			  		cout<<"Enter end of location you want to stop copy(must be greater than the location from which you start to copy): ";
			  		cin>>loc2;
			  		if(loc2 < 1 || loc2 > size || loc2<loc1){
			  			cout<<"Invalid location!\nEnter again!\n";
					}}while(loc2 < 1 || loc2 > size|| loc2<loc1);
			  		Node* pos1;
					pos1 = head;
                    Node* pos2 ;
					pos2= head;
                    for(int i = 1; i < loc1; i++){
                    	//cout<<pos1->value;
                        pos1 = pos1->nxtnode;
                    }
                    for(int i = 0; i < loc2-1; i++){
                    	arrsize++;
                        arr[i]=pos1->value;
                        pos1= pos1->nxtnode;
                      }
                    int pos;
				        do{
			    	      cout<<"Enter position at which you want to paste values ";
			    	      cin>>pos;
			    	      if (pos < 1 || pos > size + 1) {
                            cout << "Invalid position" << endl;
                          }
                          }while(pos < 1 || pos > size + 1);
			    	      for(int i=arrsize-1;i>=0;i--){
				           Node* newnode = new Node;
                           newnode->value = arr[i];
                          
                           if (pos == 1) {
                            newnode->nxtnode = head;
                            head = newnode;
                           }
                           else{
                            previous = head;
                            for (int i = 1; i<pos-1; i++) {
                               previous = previous->nxtnode;
                            }
                            newnode->nxtnode = previous->nxtnode;
                            previous->nxtnode = newnode;
                            }
                            size++;
                     	
				            }
		            }
				    
				    break;
			  	case'c':
			  		int count=0;
            		    int array[size];
            		    current=head;
				        while(current!=NULL){
				        	array[count]=current->value;
				    	    current=current->nxtnode;
						    count++;
					    }
					    
					    for(int i=0;i<count;i++){
					    	Node* newnode=new Node;
				      newnode->value=array[i];
				      newnode->nxtnode=NULL;
					  if(head == NULL){
					   head=newnode;
				      }
				      else{
				        current =head;
				        while(current->nxtnode!=NULL){
					      current=current->nxtnode;
				        }
				        current->nxtnode=newnode;
				      }
						}
					    
			  		break;
			
		}//cswitch
	}//copy
		
		void update(){
			char choice;
    	    cout<<"\t\t === Update Value ===\n";
		    cout<<"\t a. By location\n";
		    cout<<"\t b. By value\n";
		    cout<<"\t c. Exit\n";
		    do{
		      cout<<"Enter choice (in lower case) : ";
		      cin>>choice;
		      if(choice!='a' && choice!='b' && choice!='c'){
		      	cout<<"Invalid choice!\n";
			  }//if
			}while(choice!='a' && choice!='b' && choice!='c');
			if(choice=='c'){
			  	exit(1);
			}
			switch(choice){
			  	case'a':
			  		{
					int location;
			  		int updatevalue;
			  		bool update=false;
			  		cout<<"Enter value location you want to update: ";
			  		cin>>location;
			  		cout<<"Enter updated value: ";
			  		cin>>updatevalue;
			    	if (location < 1 || location > size + 1){
                        cout<<"Invalid position"<<endl;
                    }
                    else if(location==1){
                            head->value=updatevalue;
                          }
                    else{
                            current = head;
                            for (int i = 1; i<location; i++) {
                               current = current->nxtnode;
                            }
                            current->value=updatevalue;
                    }
                }
                    break;
			  	case'b':
			  		int value;
			  		int updatevalue;
			  		bool update=false;
			  		cout<<"Enter value you want to update: ";
			  		cin>>value;
			  		cout<<"Enter updated value: ";
			  		cin>>updatevalue;
			  		current=head;
				    while(current!=NULL){
					    if(current->value==value){
					      current->value=updatevalue;
						  update==true;
						}
					    current=current->nxtnode;
					}
					if(update==false){
						cout<<"This value is not present in list"<<endl;
					}
			  		break;
			}//switch
		}//update
		
		void search(){
			int value;
			cout<<"Enter value you want to search: ";
			cin>>value;
			if (head==NULL){
            			cout<<"List is empty\n";
			}
			else{
				bool present=false;
				current=head;
			    while(current!=NULL){
				    if(current->value==value){
				      cout<<" This value "<<current->value<<" is present in list.\n";
				      present=true;
					}//if
			          current=current->nxtnode;
				}//while
				if(present==false){
					cout<<"This value is not present in list\n";
				}
			}//else
					
            	
		}//search
		
		void sizef(){
			cout<<"Size of list is : "<<size<<endl;
		}//size
		
		void deletevalues(){
			current = head; 
           while (current != NULL) { 
              next = current->nxtnode; 
              delete current; 
              current = next; 
			  size--;
            }
           head = NULL;
		}//delete values
	
};//Single Link List class
	
	



int main(){
	SLL mylist;
	int choice=0;
	do{cout<<"\nLIST:";
	   mylist.display_entire_list();
	   cout<<endl;
	   cout<<"SIZE:"<<mylist.size<<endl;
	cout<<"\t\t=== Main Menu ===\n";
	cout<<"\t 1-Create List\n";
	cout<<"\t 2-Insertion Menu\n";
	cout<<"\t 3-Deletion Menu\n";
	cout<<"\t 4-Display Menu\n";
	cout<<"\t 5-Swapping Menu\n";
	cout<<"\t 6-Copy Menu\n";
	cout<<"\t 7-Update Value\n";
	cout<<"\t 8-Search value from List\n";
	cout<<"\t 9-Size of the List\n";
	cout<<"\t 10-Delete entire list values\n";
	cout<<"\t 11-Exit\n";
	do{
	cout<<"Enter choice : ";
	cin>>choice;
	if(choice<=0 || choice>11){
		cout<<"Invalid choice !\n";
	}//if
	}while(choice<=0 || choice>11);
	switch(choice){
		case 1:
			mylist.create_empty_list();
			break;
		case 2:
			mylist.insertion();
			break;
		case 3:
			mylist.deletion();
			break;
		case 4:
			mylist.display();
			break;
		case 5:
			mylist.swapping();
			break;
		case 6:
			mylist.copy();
			break;
		case 7:
			mylist.update();
			break;
		case 8:
			mylist.search();
			break;
		case 9:
			mylist.sizef();
			break;
		case 10:
			mylist.deletevalues();
			break;
		case 11:
			exit(0);	
	}
	}while(choice!=11);
}
                                                          
