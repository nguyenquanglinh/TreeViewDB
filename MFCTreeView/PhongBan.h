#pragma once
#include <vector>
#include<iostream>
#include"NhanVien.h"
using namespace std;
class PhongBan
{
private:
	int MaPB;
	CString TenPB;

public:
	PhongBan();
	~PhongBan();
	PhongBan(int maPB, CString tenPb);
	vector<NhanVien>GetdsNhanVien();
	void SetTenPb(CString tenPB);
	void SetMaPB(int maPB);
	CString GetTenPB();
	int GetMaPB();
	CString toString();
};

