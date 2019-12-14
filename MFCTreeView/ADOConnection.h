#pragma once
#import "C:\Program Files\Common Files\System\ADO\msado15.dll" \
no_namespace rename("EOF", "EndOfFile")
#include"NhanVien.h"
#include"PhongBan.h"


//#import "C:/Program Files/Common Files/System/ado/msado15.dll" rename("EOF", "adoEOF") rename("BOF", "adoBOF")

class ADOConnection
{
private:
	_ConnectionPtr conn = NULL;
	_CommandPtr Cmd1 = NULL;
	_bstr_t strCon = ("thang");
public:
	ADOConnection();
	~ADOConnection();
	bool Connect();
	bool InsertIntoNhanVien(NhanVien nv);
	bool UpdateNhanvVien(NhanVien nv1, NhanVien nv2);
	bool DeleteNhanVien(NhanVien nv);
	bool InsertIntoPhongBan(PhongBan pb);
	bool UpdatePhongBan(PhongBan pb1, PhongBan pb2);
	bool DeletePhongBan(PhongBan pb);
	vector<PhongBan>GetDsPhongBan();
	vector<NhanVien>GetDsNhanVienFromPhongBan(PhongBan pb);
};

