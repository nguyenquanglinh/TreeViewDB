#include "stdafx.h"
#include "NhanVien.h"


NhanVien::NhanVien()
{
}


NhanVien::~NhanVien()
{
}

NhanVien::NhanVien(int maNV, CString tenNV,int maPb)
{
	this->maNV = maNV;
	this->tenNV = tenNV;
	this->maPb = maPb;
}

NhanVien::NhanVien(int maNV, CString tenNV)
{
	this->maNV = maNV;
	this->tenNV = tenNV;
	this->maPb = NULL;
}

void NhanVien::SetTenNV(CString tenNV)
{
	this->tenNV = tenNV;
}

void NhanVien::SetMaNV(int maNV)
{
	this->maNV = maNV;
}

CString NhanVien::GetTenNV()
{
	return this->tenNV;
}

int NhanVien::GetMaNV()
{
	return this->maNV;
}

CString NhanVien::toString()
{
	return GetTenNV();
}
