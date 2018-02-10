#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>

using namespace std;

typedef struct node_antri
{
	int no;
	string nama;
	node_antri *next;
}data_antri;

typedef struct node_pesan
{
	string nama;
	string pesan;
	int jumlah;
	node_pesan *next;
}data_pesan;

node_antri *Antrian;
node_pesan *Pesan;

void insert(string nm,int n)
{
	node_antri *baru;
	baru = new node_antri;
	
	baru->no=1;
	baru->nama=nm;
	baru->next=NULL;
	
	if (Antrian==NULL)
	{
		Antrian=baru;
		Antrian->next=NULL;
	}
	else
	{
		node_antri *temp;
		temp=Antrian;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		baru->no=(temp->no+1);
		temp->next=baru;
	}
}

void view()
{
	if(Antrian!=NULL)
	{
		cout<<"List antrian : \n";
		node_antri *tampil;
		tampil = Antrian;
		
		while(tampil!=NULL)
		{
			cout<<tampil->no<<". ";
			cout<<tampil->nama<<"	\n";
			tampil=tampil->next;
		}
	}
	else
	{
		cout<<"Antrian Kosong";
	}
}

void panggil()
{
	if(Antrian!=NULL)
	{
		int no = Antrian->no;
		string nama = Antrian->nama;
		string pesan;
		int jml;
		cout<<"\n";
		cout<<"Pesanan untuk antrian ke "<<no<<"\n";
		cout<<"Nama Pesanan "<<no<< " : "<<nama<<"\n";
		cout<<"Masukan nama pesanan : ";
		cin>>pesan;
		cout<<"Masukan jumlah pesanan : ";
		cin>>jml;
		
		node_pesan*baru_pesan;
		baru_pesan = new node_pesan;
		
		baru_pesan->nama=nama;
		baru_pesan->pesan=pesan;
		baru_pesan->jumlah=jml;
		baru_pesan->next=NULL;
		
		if (Pesan==NULL)
		{
			Pesan=baru_pesan;
			Pesan->next=NULL;
		}
		else
		{
			node_pesan *temp;
			temp=Pesan;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
		temp->next=baru_pesan;
		}
		Antrian=Antrian->next;
	}
	else
	{
		cout<<"Antrian Kosong";
	}
}

void viewpesan()
{
	int no=1;
	if(Pesan!=NULL)
	{
		node_pesan *tampil_pesan;
		tampil_pesan=Pesan;
		
		cout<<"\n";
		cout<<"Daftar pesanan yang masuk\n";
		cout<<"No"<<"\t Nama"<<"\t Pesanan"<<"\t Jumlah\n";
		
		while(tampil_pesan!=NULL)
		{
			cout<<setiosflags(ios::left)<<setw(8)<<no;
			cout<<setiosflags(ios::left)<<setw(16)<<tampil_pesan->nama;
			cout<<setiosflags(ios::left)<<setw(7)<<tampil_pesan->pesan;
			cout<<setiosflags(ios::right)<<setw(5)<<tampil_pesan->jumlah;
			tampil_pesan=tampil_pesan->next;
			no++;
			cout<<"\n";
		}
	}
	else
	{
		cout<<"Data masih kosong\n";
	}
}

int main()
{
	int  pil;
	int n=1;
	string nama;
	char p;
	do
	{
		cout<<"Menu\n";
		cout<<"1. Masukan Antrian\n";
		cout<<"2. Tampil Antrian\n";
		cout<<"3. Panggil Antrian\n";
		cout<<"4. Tampil pesan yang masuk\n";
		cout<<"0. Exit\n";
		
		cout<<"Masukan pilihan : ";
		cin>>pil;
		switch(pil)
		{
			case 1:
				cout<<"\n";
				cout<<"Masukan Nama ke dalam antrian ke "<<n<<" : ";
				cin>>nama;
				insert(nama,n);
				n++;
				getch();
				break;
			case 2:
				cout<<"\n";
				view();
				getch();
				break;
			case 3:
				panggil();
				getch();
				break;
			case 4:
				viewpesan();
				getch();
				break;
		}
		system("cls");
	}while(pil!=0);
	return 0;
}
