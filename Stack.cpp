#include <iostream>
#include <conio.h>

using namespace std;

typedef struct node
{
	int data;
	node*next;
}data;

node*head;

void init()
{
	head=NULL;
}

int IsEmpty()
{
	if(head==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(int value)
{
	node *baru;
	baru=new node;
	baru->data=value;
	baru->next=NULL;
	if(IsEmpty()==1)
	{
		head=baru;
		head->next=NULL;
	}
	else
	{
		baru->next=head;
		head=baru;
	}
	cout<<"\n";
	system ("cls");
}

void pop(int value)
{
	node *hapus;
	int d;
	if(IsEmpty()==0)
	{
		if(head!=NULL)
		{
			hapus=head;
			d=hapus->data;
			head=hapus->next;
			delete hapus;
		}
		system ("cls");
		cout<<"Data "<<d<<" berhasil di POP\n";
	}
	else
	{
		system ("cls");
		cout<<"\nTidak ada data yang di POP, silahkan PUSH !\n";
	 }
}

void tampil()
{
	node *bantu;
	bantu=head;
	if(IsEmpty()==0)
	{
		system("cls");
		cout<<"=== Menampilkan Data ===\n";
		while(bantu!=NULL)
		{
			
			cout<<bantu->data<<endl;
			bantu=bantu->next;
			cout<<"\n";
		}
	}
	else
	{
	system ("cls");
	cout<<"\nTidak ada data, silahkan push !\n";
	}
}

void hapus()
{
	if(head!=NULL)
	{
	system ("cls");
	head=NULL;
	cout<<"Semua data berhasil di hapus \n";
	}
	else
	{
	system ("cls");
	cout<<"\nTidak ada data yang dihapus, silahkan push !\n";
	}	
}

void exit()
{
	cout<<"-------------------\n";
	cout<<"| Sampai Jumpa :) |\n";
	cout<<"-------------------\n";
}

int main()
{	
	int pil,value;
	char n;
	do{
	menu:	
	cout<<"	~STACK~\n";
	cout<<"-----------------\n";
	cout<<"| 1. PUSH	|\n";
	cout<<"| 2. POP	|\n";
	cout<<"| 3. CLEAR	|\n";
	cout<<"| 4. VIEW STACK	|\n";
	cout<<"| 5. EXIT	|\n";
	cout<<"-----------------\n";
	cout<<"\n";
	cout<<"Masukan pilihan anda (1-5) : ";
	cin>>pil;
	cout<<"\n";
	
	switch(pil)
	{
		case 1:
			cout<<"Masukan Data = ";
			cin>>value;
			push(value);
		break;
		
		case 2:
		pop(value);
		cout<<"\n";
		cout<<"Ingin kembali ke menu lagi [y/t]? = ";
		cin>>n;
		if(n=='y'||n=='Y')
		{
			system ("cls");
			goto menu;
		}
		else
		{
			system ("cls");
			exit();
			exit(0);
		}
		break;
		
		case 3:
		hapus();
		cout<<"\n";
		cout<<"Ingin kembali ke menu lagi [y/t]? = ";
		cin>>n;
		if(n=='y'||n=='Y')
		{
			system ("cls");
			goto menu;
		}
		else
		{
			system ("cls");
			exit();
			exit(0);
		}
		break;
		
		case 4:
		tampil();
		cout<<"\n";
		cout<<"Ingin kembali ke menu lagi [y/t]? = ";
		cin>>n;
		if(n=='y'||n=='Y')
		{
			system ("cls");
			goto menu;
		}
		else
		{
			system ("cls");
			exit();
			exit(0);
		}
	}
}while(pil !=5);
{
	system ("cls");
	exit();
	exit(0);
}
}
