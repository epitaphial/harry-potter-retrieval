
#include "stdafx.h"
#include"iostream"
#include"fstream"
#include"string"

using namespace std;
class FileOpr
{
public:
	//读文件函数
	int readTxt(string file, char* a, long *b, int *c, char f[][20])
	{
		ifstream infile;
		infile.open(file.data());
		if (!infile)
		{
			cerr << "error!" << endl;
			return -1;
		}
		//用两个数组装前后两个字符串

		infile >> noskipws;
		while (!infile.eof())
		{
			//找到各种字符分隔的字符串
			infile >> d;
			bool e = (d > 122 || (d < 97 && d>90) || d < 48 || (d < 65 && d>57)) && (d != '-');
			if (e)
			{
				c1[n] = '\0';
				//找到当前页面
				sprintf(strpages, "%d", pages);
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
	//调用函数
	NUM = fop.readTxt("d://3.txt", WaitFind, Number, page, Chapter);
	//输出
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


