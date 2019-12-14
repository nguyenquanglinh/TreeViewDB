#include "stdafx.h"
#include "PhongBan.h"


PhongBan::PhongBan()
{
}


PhongBan::~PhongBan()
{
}

PhongBan::PhongBan(int maPB, CString tenPb)
{
	this->MaPB = maPB;
	this->TenPB = tenPb;
}

vector<NhanVien> PhongBan::GetdsNhanVien()
{
	return vector<NhanVien>();
}

void PhongBan::SetTenPb(CString tenPb)
{
	this->TenPB = tenPb;
}

void PhongBan::SetMaPB(int maPB)
{
	this->MaPB = maPB;
}

CString PhongBan::GetTenPB()
{
	return this->TenPB;
}

int PhongBan::GetMaPB()
{
	return this->MaPB;
}

CString PhongBan::toString()
{
	return GetTenPB();
}


