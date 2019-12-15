#include "stdafx.h"
#include "ADOConnection.h"


ADOConnection::ADOConnection()
{
}


ADOConnection::~ADOConnection()
{
}

bool ADOConnection::Connect()
{
	CoInitialize(NULL);
	//strConnect = _T("Provider=sqloledb;Data Source=MyServerName;Initial Catalog=MyDatabaseName;Integrated Security=SSPI;")
	try
	{
		//Create the Connection pointer
		if (!FAILED(this->conn.CreateInstance((__uuidof(Connection))))) {
			if (!FAILED(this->conn->Open(strCon, "", "", 0)))//open con nect
				if (!FAILED(this->Cmd1.CreateInstance(__uuidof(Command))))//tao cmd
					return true;
		}
		return false;
	}
	catch (_com_error & ce)
	{
		return false;
	}
}

bool ADOConnection::InsertIntoNhanVien(NhanVien nv)
{
	try
	{

		_bstr_t ma = "'" + _bstr_t(nv.GetMaNV()) + "'";
		_bstr_t ten = ",'" + _bstr_t(nv.GetTenNV()) + "'";
		_bstr_t strsql;
		if (nv.GetMaPb() != NULL) {
			_bstr_t mapb = ",'" + _bstr_t(nv.GetMaPb()) + "'";
			strsql = "Insert into NhanVien(MaNV,TenNV,MaPb) Values(" + ma + ten + mapb + ")";
		}
		else
			strsql = "Insert into NhanVien(MaNV,TenNV) Values(" + ma + ten + ")";
		Cmd1->ActiveConnection = this->conn;
		Cmd1->CommandText = strsql;
		Cmd1->CommandType = adCmdText;

		if (FAILED(Cmd1->Execute(NULL, NULL, adCmdText)))
		{
			return false;
			//id1.SetWindowTextW(_T("Error creating command instance!!"));
		}
		else
		{
			return true;
		}


	}
	catch (const std::exception&)
	{
		return false;
	}

}

bool ADOConnection::UpdateNhanvVien(NhanVien nv1, NhanVien nv2)
{
	try
	{
		_bstr_t ma2 = "'" + _bstr_t(nv2.GetMaNV()) + "'";
		_bstr_t ma = "'" + _bstr_t(nv1.GetMaNV()) + "'";
		_bstr_t ten2 = "'" + _bstr_t(nv2.GetTenNV()) + "'";
		//update NhanVien set TenNV = 'a', MaNV = '2'where MaNV = '1'
		_bstr_t strsql("update NhanVien set TenNV=" + ten2 + ",MaNV=" + ma2 + "where MaNV=" + ma);
		Cmd1->ActiveConnection = conn;
		Cmd1->CommandText = strsql;
		Cmd1->CommandType = adCmdText;

		if (FAILED(Cmd1->Execute(NULL, NULL, adCmdText)))
		{
			return false;
			//id1.SetWindowTextW(_T("Error creating command instance!!"));
		}
		else
		{
			return true;
		}
	}
	catch (const std::exception&)
	{
		return false;
	}

}

bool ADOConnection::DeleteNhanVien(NhanVien nv)
{
	try
	{
		//_bstr_t ma = "'" + _bstr_t(nv1.GetMaNV()) + "'";
		_bstr_t ma = "'" + _bstr_t(nv.GetMaNV()) + "'";
		_bstr_t strsql("delete NhanVien where MaNV=" + ma);
		Cmd1->ActiveConnection = conn;
		Cmd1->CommandText = strsql;
		Cmd1->CommandType = adCmdText;
		if (FAILED(Cmd1->Execute(NULL, NULL, adCmdText)))
		{
			return false;
			//id1.SetWindowTextW(_T("Error creating command instance!!"));
		}
		else
		{
			return true;
		}
	}
	catch (const std::exception&)
	{
		return false;
	}
}

bool ADOConnection::InsertIntoPhongBan(PhongBan pb)
{
	try
	{
		_bstr_t ten = "'" + _bstr_t(pb.GetTenPB()) + "'";
		_bstr_t ma = "'" + _bstr_t(pb.GetMaPB()) + "'";
		_bstr_t strsql("Insert into PhongBan(MaPb,TenPB) Values(" + ma + _bstr_t(",") + ten + ")");
		Cmd1->ActiveConnection = this->conn;
		Cmd1->CommandText = strsql;
		Cmd1->CommandType = adCmdText;

		if (FAILED(Cmd1->Execute(NULL, NULL, adCmdText)))
		{
			return false;
			//id1.SetWindowTextW(_T("Error creating command instance!!"));
		}
		else
		{
			return true;
		}


	}
	catch (const std::exception&)
	{
		return false;
	}

}

bool ADOConnection::UpdatePhongBan(PhongBan pb1, PhongBan pb2)
{
	try
	{
		_bstr_t ma2 = "'" + _bstr_t(pb2.GetMaPB()) + "'";
		_bstr_t ma = "'" + _bstr_t(pb1.GetMaPB()) + "'";
		_bstr_t ten2 = "'" + _bstr_t(pb2.GetTenPB()) + "'";
		//update NhanVien set TenNV = 'a', MaNV = '2'where MaNV = '1'
		_bstr_t strsql("update PhongBan set TenPB=" + ten2 + ",MaPb=" + ma2 + "where MaPb=" + ma);
		Cmd1->ActiveConnection = conn;
		Cmd1->CommandText = strsql;
		Cmd1->CommandType = adCmdText;

		if (FAILED(Cmd1->Execute(NULL, NULL, adCmdText)))
		{
			return false;
			//id1.SetWindowTextW(_T("Error creating command instance!!"));
		}
		else
		{
			return true;
		}
	}
	catch (const std::exception&)
	{
		return false;
	}
}

bool ADOConnection::DeletePhongBan(PhongBan pb)
{
	try
	{
		//_bstr_t ma = "'" + _bstr_t(nv1.GetMaNV()) + "'";
		_bstr_t ma = "'" + _bstr_t(pb.GetMaPB()) + "'";
		_bstr_t strsql("delete NhanVien where MaPb=" + ma);
		Cmd1->ActiveConnection = conn;
		Cmd1->CommandText = strsql;
		Cmd1->CommandType = adCmdText;
		if (FAILED(Cmd1->Execute(NULL, NULL, adCmdText)))
		{
			return false;
			//id1.SetWindowTextW(_T("Error creating command instance!!"));
		}
		else
		{
			return true;
		}
	}
	catch (const std::exception&)
	{
		return false;
	}
}

vector<PhongBan> ADOConnection::GetDsPhongBan()
{
	_RecordsetPtr ret;
	_bstr_t strsql("select * from PhongBan");
	vector<PhongBan> t;
	if (!FAILED(ret.CreateInstance(__uuidof(Recordset))))
	{
		ret->Open(strsql, strCon, adOpenStatic, adLockReadOnly, adCmdText);
		//Loop through the Record set
		if (!ret->EndOfFile)
		{
			_bstr_t ten;
			int ma;
			ret->MoveFirst();
			while (!ret->EndOfFile)
			{
				ma = ret->Fields->GetItem("MaPb")->Value;
				ten = ret->Fields->GetItem("TenPB")->Value;
				t.push_back(PhongBan(ma, (LPCTSTR)ten));
				ret->MoveNext();
			}
			//return false;
			//id1.SetWindowTextW(_T("Error creating command instance!!"));
		}
		else
		{
			//return true;
		}

		return t;
	}
}

vector<NhanVien> ADOConnection::GetDsNhanVienFromPhongBan(PhongBan pb)
{
	vector<NhanVien> t;
	if (pb.GetMaPB() != NULL) {
		_RecordsetPtr ret;
		_bstr_t ma = "'" + _bstr_t(pb.GetMaPB()) + "'";
		_bstr_t strsql("select * from NhanVien where MaPb=" + ma);
		if (!FAILED(ret.CreateInstance(__uuidof(Recordset))))
		{
			ret->Open(strsql, strCon, adOpenStatic, adLockReadOnly, adCmdText);
			//Loop through the Record set
			if (!ret->EndOfFile)
			{
				ret->MoveFirst();
				_bstr_t ten;
				int mapb;
				int manv;
				while (!ret->EndOfFile)
				{

					ten = ret->Fields->GetItem("TenNV")->Value;
					manv = ret->Fields->GetItem("MaNV")->Value;
					mapb = ret->Fields->GetItem("MaPb")->Value;
					if (mapb != NULL)
						t.push_back(NhanVien(manv, (LPCTSTR)ten));
					else
					{
						t.push_back(NhanVien(manv, (LPCTSTR)ten, mapb));
					}
					ret->MoveNext();
				}
				//return false;
				//id1.SetWindowTextW(_T("Error creating command instance!!"));
			}
			else
			{
				//return true;
			}
		}
	}

	return t;
}
