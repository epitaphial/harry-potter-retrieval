
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
private:
	char d, NowChapter[20], strpages[10], c1[1000], c2[1000];
	int n = 0, NumAmount = 0, times = 0, pages = 1;
};


int main()
{
	char *WaitFind = new char[100]; FileOpr fop;
	long *Number = new long[10000]; int page[10000]; char Chapter[10000][20]; int NUM; int m = 0;
	cin >> WaitFind;
	//���ú���
	NUM = fop.readTxt("d://3.txt", WaitFind, Number, page, Chapter);
	//���
	while (m < NUM)
	{
		cout << "NO." << m << ":" << WaitFind << " chapter:" << Chapter[m] << " place:" << Number[m] << " pages:" << page[m] << endl;
		m++;
	}
	delete[]WaitFind;
	delete[]Number;
	WaitFind = NULL;
	Number = NULL;
	return 0;
}


