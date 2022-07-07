#include<iostream>
using namespace std;
#define size 5
class stack
{
int stck[size];
int tos;
public:
void init();
void push();
int pop();
void display();
};
void stack::init()
{
tos=0;
}
void stack::push()
{
int i;
if(tos==size)
{
cout<<"stack overflow \n";
return;
}
cout<<"enter element \n";
cin>>i;
stck[tos]=i;
tos++;
}
int stack::pop()
{
if(tos==0)
{
cout<<"stack underflow \n";
return 1;
}
tos--;
cout<<"popped element is"<<stck[tos];
return 0;
}
void stack::display()
{
if(tos==0)
{
cout<<"stack empty \n";
return;
}
for(int i=0;i<tos;i++)
{
cout<<stck[i]<<"\n";
}
}
int main()
{
int ch,i;
stack s;
s.init();
while(1)
{
cout<<"\n1.push 2.pop 3.display \n";
cin>>ch;
switch(ch)
{
case 1:s.push();
break;
case 2:s.pop();
break;
case 3:s.display();
break;
default: return 0;
}
}
}
2(a)Write a C++ program to read the data of n employee and compute net
salary of each employee using pointer. Given that an employee class
contains following :-
Data members: Employee no, Employee name, Basic salary, DA, IT,
Net salary, gross salary
Member functions: To read data, to calculate net salary and to print
data
[DA = 52% of basic salary, IT = 30% of gross salary,
 Gross salary = DA + Basic, Net salary = DA + Basic – IT].
#include<iostream>
using namespace std;
class employee
{
int num, basic;
long da,it,netsal,gsal;
char name[20];
public:
void read();
void disp();
void calc();
};
void employee::read()
{
cout<<"enter employee id,name & basic salary \n";
cin>>num>>name>>basic;
}
void employee::calc()
{
da=(0.52)*basic;
gsal=da+basic;
it=(0.3)*gsal;
netsal=basic+da-it;
}
void employee::disp()
{
cout<<num<<"\t"<<name<<"\t\t\t"<<basic<<"\t\t"<<da<<"\t\t"<<it<<"\t\t"
<<gsal<<"\t"<<netsal<<"\n";
}
int main()
{
int n;
cout<<"enter no. of employee \n";
cin>>n;
employee e[n],*p;
for(int i=0;i<n;i++)
{
p=&e[i];
p->read();
p->calc();
}
cout<<"sl no. eid\t name \t\t basic salary\t \t DA\t\tgross salary\t
income tax\t Net salary\n";
for(int i=0;i<n;i++)
{
p=&e[i];
p->disp();
}
return 0;
}
2) (b) Write a c++ program to find the largest of three numbers using
inline function and defaullt argument concept.
#include<iostream>
using namespace std;
inline float lar(float a, float b ,float c=50 )
{
return ((a>b&&a>c)?a:b>c?b:c);
}
int main()
{
float x,y,z;
cout<<"\nEnter three numbers:\n";
cin>>x>>y>>z;
cout<<"Largest= "<<lar(x,y,z);
cout<<"\nTaking 3rd number as 50\n";
cout<<"\nEnter two numbers:\n";
cin>>x>>y;
cout<<"\nLargest using default value= "<<lar(x,y)<<"\n";
return 0;
}
3.) Write a C++ program to define a student class with data members usn,
name and marks of 3 subjects. And member functions to read, display,
and to calculate average of best 2 marks. Also find who is the topper
among “n” no. of students.
#include<iostream>
using namespace std;
class stud
{
char usn[20],name[30];
float marks[3];
int i;
public:
float avg;
void read();
void calc(int);
void disp();
};
void stud::read()
{
cout<<"\nEnter USN no.: ";
cin>>usn;
cout<<"\nEnter name: ";
cin>>name;
for(i=0;i<3;i++)
{
cout<<"\nEnter the marks of subject "<<i+1<<": ";
cin>>marks[i];
}
}
void stud::calc(int n)
{
int sum=0,min=marks[0];
for(i=0;i<n;i++)
{
sum+=marks[i];
if(min>=marks[i])
min=marks[i];
}
avg=float(sum-min)/2;
}
void stud::disp()
{
cout<<usn<<"\t"<<name<<"\t";
for(i=0;i<3;i++)
cout<<marks[i]<<"\t";
cout<<avg<<"\n";
}
int main()
{
int n,topper,i,z;
float max=0;
cout<<"\nEnter the number of students: ";
cin>>n;
stud s[n];
for(i=0;i<n;i++)
{
s[i].read();
s[i].calc(n);
}
cout<<"USN\tName\t";
for(i=0;i<3;i++)
{
cout<<"Marks "<<i+1<<"\t";
}
cout<<"Avg.\n";
for(i=0;i<n;i++)
s[i].disp();
for(i=0;i<n;i++)
{
if(max<s[i].avg)
{
max=s[i].avg;
topper=i;
}
}
for(i=0;i<n;i++)
{
if(s[topper].avg==s[i].avg)
{
cout<<"\nThe toppers is student "<<i+1<<": ";
cout<<"\nDetails:-\n";
s[i].disp();
}
}
}
4.a) Design a C++ program to implement access control to some
shared resource used by all objects of a class using a static
variable
#include<iostream>
using namespace std;
class resource
{
static int res;
public:
static int getr();
void free_res()
{
res=0;
}
};
int resource::res;
int resource::getr()
{
if(res)
return 0;
else
{
res=1;
return 1;
}
}
int main()
{
resource a,b;
if(resource::getr())
cout<<"Resource under use, object a is using \n";
if(!resource::getr())
cout<<"Resource busy, object b access denied \n";
a.free_res();
if(resource::getr())
cout<<"Resource can now be used by Object b \n";
return 0;
}
4.b) Design a C++ program to keep the track of the number of objects
of a particular class type that are inexistence using a static
variable.
#include <iostream>
using namespace std;
class Counter
{
public:
static int count;
Counter() { count++; }
~Counter() { count--; }
};
int Counter::count;
void f();
int main(void)
{
Counter o1;
cout << "Objects in existence: ";
cout << Counter::count << "\n";
Counter o2;
cout << "Objects in existence: ";
cout << Counter::count << "\n";
f();
cout << "Objects in existence: ";
cout << Counter::count << "\n";
return 0;
}
void f()
{
Counter temp;
cout << "Objects in existence: ";
cout << Counter::count << "\n";
// temp is destroyed when f() returns
}
5) Design a C++ program to implement a class which accepts date
in different formats (using constructor overloading).
#include <iostream>
#include <cstdio>
using namespace std;
class date
{
int day, month, year;
public:
date(char *d);
date(int m, int d, int y);
void show_date();
};
// Initialize using string.
date::date(char *d)
{
sscanf(d, "%d%*c%d%*c%d", &month, &day, &year);
}
// Initialize using integers.
date::date(int m, int d, int y)
{
day = d;
month = m;
year = y;
}
void date::show_date()
{
cout << month << "/" << day;
cout << "/" << year << "\n";
}
int main()
{
date ob1(12, 4, 2003), ob2("10/22/2003");
ob1.show_date();
ob2.show_date();
return 0;
}
6. Design a C++ program to create class called list with member
functions to insert an element from front as well as to delete
element from front of list. Demonstrate all functions by
creating list object.
#include<iostream>
#include<new>
using namespace std;
struct nod
{
int info;
struct nod*next;
};
typedef struct nod node;
class list
{
node *f;
public:
list()
{
f=NULL;
}
void ins(int num)
{
node *p=new node;
p->info=num;
p->next=f;
f=p;
}
void del()
{
node *temp=f;
if(f==NULL)
cout<<"\nNo elements to delete.\n";
else
{
cout<<"\n The deleted elements is :\n"<<f->info;
f=f->next;
delete temp;
cout<<"\n Deletion successfull \n";
}
return;
}
void disp()
{
node *temp=f;
if(f==NULL)
cout<<"\n List is empty \n";
else
{
cout<<"\n Elements in the list are: ";
while(temp!=NULL)
{
cout<<" "<<temp->info;
temp=temp->next;
}
}
}
};
int main()
{
int num,ch=1;
list ob;
cout<<"\n!!!!!!!!!!! LINEAR LINK LIST !!!!!!!!!!!!!!!!\n";
cout<<"\n1] Insert\n2] Delete\n3] Exit";
while(ch)
{
cout<<"\nEnter your choice \n";
cin>>ch;
switch(ch)
{
case 1: cout<<"\n Enter no. to be insrted\n";
cin>>num;
ob.ins(num);
ob.disp();
break;
case 2: ob.del();
ob.disp();
break;
case 3: return 0;
default:cout<<"Invalid choice \n";
break;
}
}
}
7. Design a C++ program for a hospital to create a database
regarding its indoor patients. (Identify the member function).
create a base class to store above information, member function
should include functions to enter information and display list of
all the patients in the database. Create a derived class to store
the information about paediatric patients (less than 12yrs age).
#include <iostream>
using namespace std;
struct date
{
int d;
int m;
int y;
};
class hospital
{
char name[100];
struct date d_adm;
struct date d_dis;
protected:int age;
public:
void getdata()
{
cout<<"Enter name of the patient: ";
cin>>name;
cout<<"Enter age: ";
cin>>age;
cout<<"Enter date of admission: ";
cin>>d_adm.d>>d_adm.m>>d_adm.y;
cout<<"Enter date of discharge: ";
cin>>d_dis.d>>d_dis.m>>d_dis.y;
}
void display()
{
cout<<name<<"\t";
cout<<age<<"\t";
cout<<d_adm.d<<'-'<<d_adm.m<<'-'<<d_adm.y<<"\t \t";
cout<<d_dis.d<<'-'<<d_dis.m<<'-'<<d_dis.y;
}
};
class pediatric_patient:public hospital
{
char vaccine[20];
public:
void get()
{
getdata();
cout<<"enter the name of vaccine to be given \n";
cin>>vaccine;
}
void put()
{
if(age<12)
{
display();
cout<<"\t"<<"\t";
cout<<vaccine;
cout<<"\n";
}
else
cout<<"age greater than 12 not a pediatric patient";
}
};
int main()
{
hospital h[5];
int n;
cout<<"Enter the number of patients \n";
cin>>n;
for(int i=0;i<n;i++)
{
h[i].getdata();
}
cout<<"Patient database \n";
cout<<"NAME" <<"\t" <<"AGE" <<"\t" <<"DATE_OF_ADMISSION "<<"\t"
 <<"DATE_OF_DISCHARGE \n";
for(int i=0;i<n;i++)
{
h[i].display();
cout<<"\n";
}
pediatric_patient a1[5];
cout<<"Enter the number of pediatric patients \n";
cin>>n;
for(int i=0;i<n;i++)
{
a1[i].get();
}
 cout<<"pediatric Patient database \n";
cout<<"NAME" <<"\t" <<"AGE" <<"\t" <<"DATE_OF_ADMISSION "<<"\t"
 <<"DATE_OF_DISCHARGE"<<"\t"<<"VACCINE \n";
for(int i=0;i<n;i++)
{
a1[i].put();
}
return 0;
}