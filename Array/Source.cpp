#include <iostream>
using namespace std;
#define MAX 100
void NhapMang(int a[], int &n);
void XuatMang(int a[], int n);
int DemChan(int a[], int n);
int DemLe(int a[], int n);
void InChanLe(int a[], int n);
void LocSNT(int a[], int n);
void SoChinhPhuong(int a[], int n);
void LocDX(int a[], int n);
int TongSoTrongDay(int a[], int n);
int TongSoNTTrongDay(int a[], int n);
int TongCP(int a[], int n);
int TongCacSoTanCungLa3(int a[], int n);
//int DemX(int a[], int n, int x);

void NhapMang(int a[], int &n)
{
	do
	{
		cout << "Nhap vao do dai mang = ";
		cin >> n;
	} while (n <= 0 || n > MAX);
	for (int i = 0; i < n; i++)
	{
		cout << "Phan tu thu a[" << i << "] = ";
		cin >> a[i];
	}
}

void XuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\t" << a[i];
	}
}

// Đếm các chữ số chẵn trong dãy
int DemChan(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			dem++;
		}
	}
	return dem;
}

// Đếm các chữ số lẽ trong dãy
int DemLe(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
		{
			dem++;
		}
	}
	return dem;
}
// In ra 2 dòng chẵn, lẽ
void InChanLe(int a[], int n)
{
	cout << "\nCac so chan";
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			cout << "\t" << a[i];
		}
	}
	cout << "\nCac so le";
	for (int i = n; i >= 0; i--) // Khởi tạo i = n, nếu i >= 0 thì i -1;
	{
		if (a[i] % 2 != 0)
		{
			cout << "\t" << a[i];
		}
	}
}

// Lọc các SNT trong dãy
bool KTSNT(int a)
{
	if (a < 2)
	{
		return false;
	}
	for (int i = 2; i < (a-1); i++)
	{
		if (a % i == 0)
		{
			return false;
		}
	}
	return true;
}
void LocSNT(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (KTSNT(a[i]) == 1)
		{
			cout << "\t" << a[i];
		}
	}
}
// Đếm các chữ số chính phương trong dãy
bool KiemTraCP(int a)
{
	for (int i = 1; i <= a; i++)
	{
		if (i*i == a)
		{
			return true;
		}
	}
	return false;
}
void SoChinhPhuong(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (KiemTraCP(a[i]) == 1)
		{
			cout << "\t" << a[i];
		}
	}
}
// Lọc các số đối xứng trong dãy
int KTDX(int a)
{
	int b = 0, i, m = a;
	while (a > 0)
	{
		i = a % 10;
		b = b * 10 + i;
		a /= 10;
	}
	if (m == b)
	{
		return 1; 
	}
	return 0;
}
void LocDX(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 9 && KTDX(a[i]) == 1)
		{
			cout << "\t" << a[i];
		}
	}
	cout << "Khong co so doi xung";
}
// Tính tổng dãy
int TongSoTrongDay(int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	return sum;
}
// Tính tổng các SNT trong dãy
int TongSoNTTrongDay(int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (KTSNT(a[i]))
		{
			sum += a[i];
		}
	}
	return sum;
}
// Tính tổng các số chính phương trong dãy
int TongCP(int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (KiemTraCP(a[i]))
		{
			sum += a[i];
		}
	}
	return sum;
}
// Tính tổng các số tận cùng là 3 trong dãy
int TongCacSoTanCungLa3(int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 10 == 3 || a[i] % 10 == -3)
		{
			sum += a[i];
		}
	}
	return sum;
}
// Nhập X đếm số lần xuất hiện của x trong dãy. Nếu không có thì xuất không có phần tử.
//int DemX(int a[], int n, int x)
//{
//	int dem = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] == x)
//		{
//			dem++;
//		}
//	}
//	return dem;
//}
int main()
{
	int a[MAX], n, x;
	NhapMang(a, n);
	cout << "Mang vua nhap la\n";
	XuatMang(a, n);
	cout << "\nTrong day co " << DemChan(a, n) << " so la so chan";
	cout << "\nTrong day co " << DemLe(a, n) << " so la so le";
	InChanLe(a, n);
	cout << "\nCac so nguyen to ";
	LocSNT(a, n);
	cout << "\nCac so chinh phuong ";
	SoChinhPhuong(a, n);
	cout << endl;
	LocDX(a, n);
	cout << "\nTong cac so trong day " << TongSoTrongDay(a, n);
	cout << "\nTong cac so nguyen to trong day " << TongSoNTTrongDay(a, n);
	cout << "\nTong cac so chinh phuong trong day " << TongCP(a, n);
	cout << "\nTong cac so tan cung la 3 la " << TongCacSoTanCungLa3(a, n);
	//cout << "\nSo lan xuat hien cua X " << DemX(a, n, x);
	cout << endl;
	system("pause");
}