
#include "stdafx.h"
#include"iostream"
#include"fstream"
#include"string"
#include"windows.h"

using namespace std;
#define SIZE 1000000
class FileOpr
{
public:
	//���ļ�����
	int readTxt(string file, char* a, long *b, int *c, char f[][20],char *v)
	{
		pages = 1;
		NumAmount = 0;
		ifstream infile;
		infile.open(file.data());
		if (!infile)
		{
			cerr << "error!" << endl;
			return 0;
		}

		infile >> noskipws;
		while (!infile.eof())
		{
			//�ҵ������ַ��ָ����ַ���
			infile >> d;
			bool e = Ab1(d);
			if (e)
			{
				//�ַ���������
				c1[n] = '\0';
				//�ҵ���ǰ��
				books = file[4];
				//�ҵ���ǰҳ��
				sprintf(strpages, "%d", pages);
				//����������c1,c2װǰ�������ַ���
				if (strcmp(strpages, c1) == 0)
				{
					pages++;
				}
				//�ҵ���ǰ���½�
				if (strcmp("CHAPTER", c2) == 0)
				{
					strcpy(NowChapter, c1);
				}
				//���������������������ͬ���ַ����Ķ�λ
				if (strcmp(c1, a) == 0)
				{
					strcpy(f[times], NowChapter);
					b[times] = NumAmount;
					c[times] = pages;
					v[times] = books;
					times++;
				}
				n = 0;
				strcpy(c2, c1);
			}
			else
			{
				c1[n] = d;
				n++;
			}
			NumAmount++;
		}
		infile.close();
		return times;
	}
	//�ڶ��ζ����亯��
	int readTxt2(string file, int a)
	{
		ifstream infile;
		infile.open(file.data());
		if (!infile)
		{
			cerr << "error!" << endl;
			return -1;
		}
		infile >> noskipws;
		cout << "�ؼ�������������Ϊ��" << endl << "{" << endl;
		//�ҵ�������
		while (!infile.eof())
		{
			infile >> d2;
			if (times3 >= a - 200)
			{
				if (times3 == a)//���
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
					cout << "<---";
				}

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				if (d2 == '\n' || d2 == 32)
					ifcha = true;
				if (ifcha)
					cout << d2;
				zf++;
				if (zf > 200 && d2 == '\n')
					break;
			}
			times3++;
		}
		cout << endl << "}" << endl;
		infile.close();
		return 0;
	}
private:
	bool Ab1(char c)//�ж��Ƿ�Ϊ��ĸ�����ַ�
	{
		bool m;
		m = (c > 122 || (c < 97 && c>90) || c < 48 || (c < 65 && c>57)) && (c != '-');
		return m;
	}

	bool ifcha = false;
	char d, NowChapter[20], strpages[10], c1[1000], c2[1000],books;
	int n = 0, NumAmount, times = 0, pages, Lineb = 0;//NumAmount Ϊѭ��������Ҳ��ÿ���鳤��
	//nΪƥ�䵽��ÿ���ַ����ĳ��ȣ�timesΪƥ�䵽�������ĴʵĴ���
	int times3 = 0; char d2; int zf = 0;//zfΪ�������볤�ȵļ�����
};

 char Chapter[SIZE][20];
int main()
{
	char *WaitFind = new char[1000]; FileOpr fop; char select;
	char *BookName = new char[SIZE];//ƥ�䵽��ÿ���ַ���������
	long *Number = new long[SIZE];//ƥ�䵽��ÿ���ַ��������е�λ��
	long *LineBreak = new long[SIZE];
	int *page = new int[SIZE];
	long NUM1 = 0;
	long m = 0, m1 = 0;//mΪ�����ͼ�����,������ƥ�䵽���ַ���λ��
	int times2;		char Path[20];//times2Ϊ�ַ��������е�λ��
	cout << "����������ҵ�����/����" << endl;
	cin >> WaitFind;
	strcpy(Path, "d://0.txt");
	while (m1 < 7)
	{

		Path[4] = m1 + 48;
		m1++;
	//���ú���
	NUM1 = fop.readTxt(Path, WaitFind, Number, page, Chapter,BookName);
	}
	if (NUM1 == 0)
	{
		cout << "�����ڣ�" << endl;
		return 0;
	}
	//���
	else
	{
		if (NUM1 > 100)
		{
			cout << "��ǰ�����Ĵ�������̫�࣬��ȷ��Ҫ����������(yȷ��/nȡ��)" << endl;
			cin >> select;
		}
		if (select == 'y'||NUM1<=100)
		{
			while (m < NUM1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << "��� : " << m<<" ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "�����ַ� : "<< WaitFind;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
				cout << " �½� chapter : " << Chapter[m];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << " �� " << page[m] << " ҳ ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout<< " ����: ";
				switch (BookName[m])
				{
				case '0':
					cout << "J.K. Rowling - HP 0 - Harry Potter Prequel";
					break;
				case '1':
					cout << "J.K. Rowling - HP 1 - Harry Potter and the Sorcerers Stone";
					break;
				case '2':
					cout << "J.K. Rowling - HP 2- Harry Potter and Chamber of Secrets";
					break;
				case '3':
					cout << "J.K. Rowling - HP 3 - Harry Potter and the Prisoner of Azkaban";
					break;
				case '4':
					cout << "J.K. Rowling - HP 4 - Harry Potter and the Goblet of Fire";
					break;
				case '5':
					cout << "J.K. Rowling - HP 6 - Harry Potter and the Half-Blood Prince";
					break;
				case '6':
					cout << "J.K. Rowling - HP 7 - Harry Potter and the Deathly Hallows Book";
					break;
				}
				cout << endl<<endl;
				m++;
			}
			while (1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				int no; FileOpr newed;
				cout << "��������Ž��н�һ���������Ĳ���(�����˳���������-1):" << endl;
				cin >> no;
				Path[4] = BookName[no];
				if (no == -1)
				{
					cout << "bye" << endl;
					break;
				}
				else if (no <= m - 1)
				{
					times2 = Number[no];
					newed.readTxt2(Path, times2);
				}
				else
					cout << "�����ڵ����!" << endl << endl;
			}
		}
		else if (select == 'n')
		{
			cout << "bye" << endl;
			return 0;
		}
		else
			cout << "�������" << endl;

	}
	delete[]WaitFind;
	delete[]Number;
	delete[]LineBreak;
	delete[]BookName;
	WaitFind = NULL;
	Number = NULL;
	LineBreak = NULL;
	BookName = NULL;
	return 0;
}