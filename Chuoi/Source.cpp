#include <iostream>
using namespace std;
void NhapChuoi()
{
	char s [100];
	cout << "Nhap vao chuoi  ";
	//fflush(stdin);
	gets_s(s);
}
//void XuatChuoi()
//{
//	cout << chuoi;
//}


void ChuyenHoa(char *s)
{
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] -= 32;
		}
	}
}
int main()
{
	char s[100];
	NhapChuoi();
	ChuyenHoa(s);
	system("pause");
}