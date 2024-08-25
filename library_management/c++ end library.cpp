#include<iostream>

using namespace std;


class library
{
	string name,title,author;
	int pos,regno,num,limit;
	static int a;
	public:
		void register_data(library *c);
		void getdata();
		int enq(library *d,int);
		void getbook(library *c,int);
		void return_book(library *c,int n);
};
int library::a=1;

void library::register_data(library *c)
{
	cout<<"Enter your name"<<endl;
	cin>>c->name;
	cout<<"Enter registration number"<<endl;
	cin>>c->regno;
	cout<<"now you are member of our library"<<endl;
	c->limit=3;												//3 books are limited
}

void library::getdata()
{
	cout<<"Enter book details "<<a<<endl;
	cout<<"Enter book name"<<endl;
	cin>>title;
	cout<<"Enter author name"<<endl;
	cin>>author;
	cout<<"Enter number of books"<<endl;
	cin>>num;
	cout<<"Enter rack position"<<endl;
	cin>>pos;
	a++;
}

int library::enq(library *d,int n)
{
	string tit;
	int m=0;
	cout<<"Enter book name"<<endl;
	cin>>tit;
	for(int i=0;i<n;i++)
	{
		if(d->title==tit)
		{
			if(d->num!=0)
			{
				cout<<"number of books available "<<d->num<<endl;
				d->num--;
				m=1;
				break;
			}
		}
		d++;	
	}
	return m;
}

void library::getbook(library *c,int n)
{
	int reg,m=0,p;
	cout<<"Enter the registration number"<<endl;
	cin>>reg;
	library *d=c;
	
	for(int i=0;i<n;i++)
	{
		if(d->regno==reg)
		{
			m=1;
			break;
		}
		d++;
	}
	
	if(m==0)
	{
		cout<<"You entered wrong registration number or you are not a member of this library"<<endl;
	}
	else if(m==1)
	{
		p=c->enq(c,n);
		if(p==0)
		{
			cout<<"ur required book is not available"<<endl;
		}
		else if(p==1 )
		{
			if(d->limit>0)
			{
				cout<<"book should return within 15 days ,if returned late 5 rs per day will be imposed"<<endl;
				cout<<"Ur required book is available"<<endl;
				cout<<"make a sign and take ur book"<<endl;
				d->limit--;
			}
			else
			{
				cout<<"u have already taken 3 books not allowed to take!"<<endl;	
			}
		}
	}
	
}

void library::return_book(library *c,int n)
{
	int days;
	float fine;
	string tit;
	
	cout<<"Enter number of days from the book received"<<endl;
	cin>>days;
	
	if(days<=15)
	{
		cout<<"u have returned the book ontime"<<endl;
	}
	else 
	{
		cout<<"delayed in the returning the book by "<<days-15<<endl;
		cout<<"fine needed to pay is "<<5*(days-15)<<endl;
	}
	cout<<"Enter the name of book wanted to return"<<endl;
	cin>>tit;
	
	for(int i=0;i<n;i++)									//incrementing book number after returning
	{
		if(c->title==tit)
		{
			c->num++;
			break;
		}
	}
}

int main()
{
	int n,k,m,j=0;
	char ch;
	cout<<"capacity of library"<<endl;
	cin>>m;
	
	cout<<"Enter the number of books list u want to enter initially"<<endl;
	cin>>n;
	
	library *b=new library[n];
	library *c=b;
	library *d=b;
	library *e=b;
	
	for(int i=0;i<n;i++)
	{
		e->getdata();
		e++;
	}
	
	do
	{
		cout<<"Enter 1.register\n2.getbook\n3.return book\n4.enter books to library"<<endl;
		cin>>k;
		switch(k)
		{
			case 1: b->register_data(d);
					d++;
					break;	
			case 2: b->getbook(c,m);
					break;
			case 3: b->return_book(c,m);
					break;
			case 4: b->getdata();
					b++;
					break;		
			default: cout<<"invalid choice"<<endl;						
		}
		cout<<"Enter y to continue"<<endl;
		cin>>ch;
	}while(ch=='y');
	
	return 0;
}
