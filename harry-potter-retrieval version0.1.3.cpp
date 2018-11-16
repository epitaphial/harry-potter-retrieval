
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
	//读文件函数
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
			//找到各种字符分隔的字符串
			infile >> d;
			bool e = Ab1(d);
			if (e)
			{
				//字符串结束符
				c1[n] = '\0';
				//找到当前书
				books = file[4];
				//找到当前页面
				sprintf(strpages, "%d", pages);
				//用两个数组c1,c2装前后两个字符串
				if (strcmp(strpages, c1) == 0)
				{
					pages++;
				}
				//找到当前的章节
				if (strcmp("CHAPTER", c2) == 0)
				{
					strcpy(NowChapter, c1);
				}
				//与输入带查找人名地名相同的字符串的定位
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
	//第二次读段落函数
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
		cout << "关键词所在上下文为：" << endl << "{" << endl;
		//找到所在行
		while (!infile.eof())
		{
			infile >> d2;
			if (times3 >= a - 200)
			{
				if (times3 == a)//标记
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
	bool Ab1(char c)//判断是否为字母或连字符
	{
		bool m;
		m = (c > 122 || (c < 97 && c>90) || c < 48 || (c < 65 && c>57)) && (c != '-');
		return m;
	}

	bool ifcha = false;
	char d, NowChapter[20], strpages[10], c1[1000], c2[1000],books;
	int n = 0, NumAmount, times = 0, pages, Lineb = 0;//NumAmount 为循环次数，也是每本书长度
	//n为匹配到的每个字符串的长度，times为匹配到所搜索的词的次数
	int times3 = 0; char d2; int zf = 0;//zf为限制输入长度的计数器
};

 char Chapter[SIZE][20];
int main()
{
	char *WaitFind = new char[1000]; FileOpr fop; char select;
	char *BookName = new char[SIZE];//匹配到的每个字符串的书名
	long *Number = new long[SIZE];//匹配到的每个字符串在书中的位置
	long *LineBreak = new long[SIZE];
	int *page = new int[SIZE];
	long NUM1 = 0;
	long m = 0, m1 = 0;//m为功能型计数器,代表所匹配到的字符的位置
	int times2;		char Path[20];//times2为字符串在文中的位置
	cout << "请输入待查找的人名/地名" << endl;
	cin >> WaitFind;
	strcpy(Path, "d://0.txt");
	while (m1 < 7)
	{

		Path[4] = m1 + 48;
		m1++;
	//调用函数
	NUM1 = fop.readTxt(Path, WaitFind, Number, page, Chapter,BookName);
	}
	if (NUM1 == 0)
	{
		cout << "不存在！" << endl;
		return 0;
	}
	//输出
	else
	{
		if (NUM1 > 100)
		{
			cout << "当前搜索的词条数量太多，您确定要继续查找吗？(y确定/n取消)" << endl;
			cin >> select;
		}
		if (select == 'y'||NUM1<=100)
		{
			while (m < NUM1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << "序号 : " << m<<" ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "待查字符 : "<< WaitFind;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
				cout << " 章节 chapter : " << Chapter[m];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << " 第 " << page[m] << " 页 ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout<< " 书名: ";
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
				cout << "请输入序号进行进一步的上下文查找(若想退出，请输入-1):" << endl;
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
					cout << "不存在的序号!" << endl << endl;
			}
		}
		else if (select == 'n')
		{
			cout << "bye" << endl;
			return 0;
		}
		else
			cout << "输入错误！" << endl;

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