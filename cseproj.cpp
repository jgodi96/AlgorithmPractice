#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef struct Students{ //create structure for student
string first;
string last;
double gpa;
Students *next;
} *NodePtr;

NodePtr& addNode(NodePtr& head, string firstName, string lastName); //function inputs the list
void writeToFile(NodePtr& head); // function to printts out whats inputted

int main(){
string firstName;
string lastName;
ifstream in;
NodePtr head = NULL;

in.open("students.txt"); //open file
while(in>>firstName && in>>lastName) addNode(head,firstName,lastName); //gather information, first and last and pass it through addHeadNode

in.close(); //close file

cout<< "Final averages added to .txt file!" << endl<<endl;


writeToFile(head); //print linked list to file

return 0;
}

NodePtr &addNode(NodePtr &head, string firstName,string lastName) 
{
NodePtr n = new Students();
n->first = firstName;
n->last= lastName;
cout<<"Enter the final average for "<<n->first<<" "<<n->last<<endl;
cin>> n->gpa;

n->next = NULL;
NodePtr p = head;

if(p == NULL) 
	head = n;
else
{
while(p->next != NULL) p = p->next;
p->next = n;
}
return head;
}

void writeToFile(NodePtr &head) //writes data into .txt file
{
NodePtr p = head;
ofstream out;
while(p != NULL)
{

  out.open ("output.txt");
  out.setf(ios::fixed);
  out.setf(ios::showpoint);
  out.precision(2);
  out << p->first <<" "<< p->last <<" " <<p->gpa<<endl; //write first list
  p = p->next;
   
  out.setf(ios::fixed);
  out.setf(ios::showpoint);
  out.precision(2);
  out << p->first <<" "<< p->last <<" " <<p->gpa<<endl; //write second list
  p = p->next;
 
  out.setf(ios::fixed);
  out.setf(ios::showpoint);
  out.precision(2);
  out << p->first <<" "<< p->last <<" " <<p->gpa<<endl; //write third list
  p = p->next;
}
out.close(); //close file
}
