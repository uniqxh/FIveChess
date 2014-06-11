// set_dlg.cpp : implementation file
//

#include "stdafx.h"
#include "FiveChess.h"
#include "set_dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// set_dlg dialog


set_dlg::set_dlg(CWnd* pParent /*=NULL*/)
	: CDialog(set_dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(set_dlg)
	m_port = _T("");
	//}}AFX_DATA_INIT
}


void set_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(set_dlg)
	DDX_Control(pDX, IDC_ip, m_ip);
	DDX_Text(pDX, IDC_port, m_port);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(set_dlg, CDialog)
	//{{AFX_MSG_MAP(set_dlg)
	ON_BN_CLICKED(IDC_host, Onhost)
	ON_BN_CLICKED(IDC_client, Onclient)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// set_dlg message handlers

BOOL set_dlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CButton*)GetDlgItem(IDC_host))->SetCheck(1);
	Onhost();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void set_dlg::Onhost() 
{
	// TODO: Add your control notification handler code here
	char str[128] = {0};
	m_is_host = 1;
	::GetPrivateProfileString("HOST","IP","",str,127,".\\config.ini");
	m_ip.SetWindowText(str);
	memset(str,0,127);
	::GetPrivateProfileString("HOST","PORT","1314",str,127,".\\config.ini");
	m_port=str;
	UpdateData(false);
}

void set_dlg::Onclient() 
{
	// TODO: Add your control notification handler code here
	char str[128] = {0};
	m_is_host = 0;
	::GetPrivateProfileString("CLIENT","IP","",str,127,".\\config.ini");
	m_ip.SetWindowText(str);
	memset(str,0,127);
	::GetPrivateProfileString("CLIENT","PORT","1314",str,127,".\\config.ini");
	m_port=str;
	UpdateData(false);
}

void set_dlg::OnOK() 
{
	// TODO: Add extra validation here
	CString ip,port;
	UpdateData(1);
	m_ip.GetWindowText(ip);
	port=m_port;
	if(m_is_host)
	{
		::WritePrivateProfileString("HOST","IP",ip,".\\config.ini");
		::WritePrivateProfileString("HOST","PORT",port,".\\config.ini");
	}
	else{
		m_host_ip=ip;
		::WritePrivateProfileString("CLIENT","IP",ip,".\\config.ini");
		::WritePrivateProfileString("CLIENT","PORT",port,".\\config.ini");
	}
	CDialog::OnOK();
}

void set_dlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
