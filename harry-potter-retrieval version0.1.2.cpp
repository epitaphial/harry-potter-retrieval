
#include "stdafx.h"
#include"iostream"
#include"fstream"
#include"string"

using namespace std;
class FileOpr
{
public:
	//���ļ�����
	int readTxt(string file, char* a, long *b, int *c, char f[][20])
	{
		ifstream infile;
		infile.open(file.data());
		if (!infile)
		{
			cerr << "error!" << endl;
			return -1;
		}
		//����������װǰ�������ַ���

		infile >> noskipws;
		while (!infile.eof())
		{
			//�ҵ������ַ��ָ����ַ���
			infile >> d;
			bool e = (d > 122 || (d < 97 && d>90) || d < 48 || (d < 65 && d>57)) && (d != '-');
			if (e)
			{
				//�ַ���������
				c1[n] = '\0';
				//�ҵ���ǰҳ��
				sprintf(strpages, "%d", pages);
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
		//�ҵ�������
		while (!infile.eof())
		{
			infile >> d2;
			if (times3 >= a)
			{
				cout << d2;
					zf++;
			}
		
			if (zf > 120)
			break;
			times3++;
		}
		infile.close();
		return 0;
	}
private:
	char d, NowChapter[20], strpages[10], c1[1000], c2[1000];
	int n = 0, NumAmount = 0, times = 0, pages = 1, Lineb = 0;
	int times3 = 0; char d2; int zf = 0;
};


int main()
{
	char *WaitFind = new char[100]; FileOpr fop;
	long *Number = new long[10000];
	long * LineBreak = new long[10000];
	int page[10000]; char Chapter[10000][20]; int NUM; int m = 0;
	int no, times2;
	cin >> WaitFind;
	//���ú���
	NUM = fop.readTxt("d://3.txt", WaitFind, Number, page, Chapter);
	//���
	while (m < NUM)
	{
		cout << "NO." << m << ":" << WaitFind << " chapter:" << Chapter[m] << " place:" << Number[m] << " pages:" << page[m] << endl;
		m++;
	}
	cin >> no;
	times2 = Number[no]-50;
	fop.readTxt2("d://3.txt", times2);
	delete[]WaitFind;
	delete[]Number;
	delete[]LineBreak;
	WaitFind = NULL;
	Number = NULL;
	LineBreak = NULL;
	return 0;
}