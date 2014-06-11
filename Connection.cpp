// Connection.cpp : implementation file
//

#include "stdafx.h"
#include "FiveChess.h"
#include "FiveChessDlg.h"
#include "Board.h"
#include "Connection.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConnection

CConnection::CConnection()
{
}

CConnection::~CConnection()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CConnection, CAsyncSocket)
	//{{AFX_MSG_MAP(CConnection)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CConnection member functions

void CConnection::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	CFiveChessDlg *dlg = (CFiveChessDlg*)AfxGetMainWnd();
	dlg->Accept();
	//CAsyncSocket::OnAccept(nErrorCode);
}

void CConnection::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	CFiveChessDlg *dlg = (CFiveChessDlg*)AfxGetMainWnd();
	dlg->MessageBox(_T("对方已经离开游戏，下次再战。"),_T("五子棋"),MB_ICONINFORMATION);
	dlg->m_board.SetWait(1);
	dlg->m_con.Close();
	dlg->m_sock.Close();
	dlg->m_is_con=0;
	//CAsyncSocket::OnClose(nErrorCode);
}

void CConnection::OnConnect(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	CFiveChessDlg *dlg = (CFiveChessDlg*)AfxGetMainWnd();
	dlg->connect();
	//CAsyncSocket::OnConnect(nErrorCode);
}

void CConnection::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	CBoard *pb = (CBoard*)AfxGetMainWnd()->GetDlgItem(IDC_BOARD);
	pb->Receive();
	//CAsyncSocket::OnReceive(nErrorCode);
}
