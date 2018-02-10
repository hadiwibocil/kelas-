#include <iostream>
#include <conio.h>

using namespace std;

typedef struct node
{
	int data;
	node *next;
};

node *head;

void insert(int n)
{
	node *baru;
	baru = new node;
	
	baru->data=n;
	baru->next=NULL;
	
	if (head==NULL)
	{
		head=baru;
		head->next=NULL;
	}
	else
	{
		node *temp;
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=baru;
	}
}

void hapus()
{
	if(head!=NULL)
	{
		cout<<head->data<<" berhasil dihapus"<<endl;
		head=head->next;
	}
}

void clear()
{
	if(head!=NULL)
	{
//system ("cls");
	head=NULL;
	cout<<"Semua data berhasil di format \n";
	}
	else
	{
//	system ("cls");
	cout<<"\nTidak ada data yang dihapus, silahkan insert !\n";
	}	
}

void view()
{
	if(head!=NULL)
	{
		node *tampil;
		tampil = head;
		
		while(tampil!=NULL)
		{
			cout<<tampil->data<<"	";
			tampil=tampil->next;
		}
	}
	else
	{
		cout<<"Stack Kosong";
	}
}

int main()
{
	int n, pil;
	char p;
	do
	{
		cout<<"Queue\n";
		cout<<"1. Insert\n";
		cout<<"2. Delete\n";
		cout<<"3. Format Queue\n";
		cout<<"4. View Queue\n";
		cout<<"0. Exit\n";
		
		cout<<"Masukan pilihan : ";
		cin>>pil;
		switch(pil)
		{
			case 1:
				cout<<"Masukan data : ";
				cin>>n;
				insert(n);
				getch();
				break;
			case 2:
				hapus();
				getch();
				break;
			case 3:
				clear();
				getch();
				break;
			case 4:
				view();
				getch();
				break;
		}
		system("cls");
	}while(pil!=0);
	return 0;
}
