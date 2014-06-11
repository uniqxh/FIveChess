// Board.cpp : implementation file
//

#include "stdafx.h"
#include "FiveChess.h"
#include "FiveChessDlg.h"
#include "sockdata.h"
#include "Board.h"
#include "rule.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBoard

CBoard::CBoard()
{
	// 初始化图像列表
    m_iml.Create( 24, 24, ILC_COLOR24 | ILC_MASK, 0, 2 );
    // 载入黑、白棋子掩码位图
    CBitmap bmpBlack, bmpWhite;
    bmpBlack.LoadBitmap( IDB_BLACK );
    m_iml.Add( &bmpBlack, 0xff00ff );
    bmpWhite.LoadBitmap( IDB_WHITE );
    m_iml.Add( &bmpWhite, 0xff00ff );
}

CBoard::~CBoard()
{
}


BEGIN_MESSAGE_MAP(CBoard, CWnd)
	//{{AFX_MSG_MAP(CBoard)
	ON_WM_LBUTTONUP()
	ON_WM_PAINT()
	ON_COMMAND(ID_RESTART, OnRestart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CBoard message handlers

void CBoard::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CFiveChessDlg *dlg = (CFiveChessDlg*)AfxGetMainWnd();
	msg_data msg;

	if(m_Wait)
	{
		MessageBeep(MB_OK);
		return ;
	}
	if(dlg->m_is_con)
	{
		int x,y;
		x = ( point.x - 12 ) / 25;
		y = ( point.y - 84 ) / 25;

		if( x < 0 || x >14 || y < 0 || y > 14 || m_data[x][y] != -1)
		{
			MessageBeep(MB_OK);
			return ;
		}
		else{
			SetData( x, y, m_color );
			msg.x = x;
			msg.y = y;
			msg.color = m_color;
		}
		m_Wait = 1;
		msg.msg_type = msg_down;
		dlg->send(&msg);

		rule rule;
		if ( rule.WIN( m_color, x, y ) == _WIN )
			dlg->MessageBox(_T("恭喜，你获得了胜利！！"),_T("胜利"),MB_ICONINFORMATION);
		else if ( rule.WIN( 1 - m_color, x, y ) != _OTHER )
			dlg->MessageBox(_T("很遗憾，你输了！！"),_T("失败"),MB_ICONINFORMATION);
	}

	CWnd::OnLButtonUp(nFlags, point);
}

void CBoard::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CDC MemDC;
    MemDC.CreateCompatibleDC( &dc );
    // 装载棋盘
    CBitmap bmp;
    CPen pen;
    bmp.LoadBitmap( IDB_TABLE );
    pen.CreatePen( PS_SOLID, 1, 0xff );
    MemDC.SelectObject( &bmp );
    MemDC.SelectObject( &pen );
    MemDC.SetROP2( R2_NOTXORPEN );
    // 根据棋盘数据绘制棋子
    int x, y;
    POINT pt;
    for ( y = 0; y < 15; y++ )
    {
        for ( x = 0; x < 15; x++ )
        {
            if ( -1 != m_data[x][y] )
            {
                pt.x = 12 + 25 * x;
                pt.y = 84 + 25 * y;
                m_iml.Draw( &MemDC, m_data[x][y], pt, ILD_TRANSPARENT );
            }
        }
    }
	// 完成绘制
    dc.BitBlt( 0, 0, 395, 472, &MemDC,0, 0, SRCCOPY );
	
	// Do not call CWnd::OnPaint() for painting messages
}

void CBoard::Clear(BOOL bWait)
{
	int x, y;
    for ( y = 0; y < 15; y++ )
    {
        for ( x = 0; x < 15; x++ )
        {
            m_data[x][y] = -1;
        }
    }
    // 设置等待标志
    m_Wait = bWait;
    Invalidate();  //使窗口无效
}

void CBoard::SetColor(int Color)
{
	m_color = Color;
}

int CBoard::GetColor() const
{
	return m_color;
}

void CBoard::SetWait(BOOL Wait)
{
	m_OldWait = m_Wait;
	m_Wait = Wait;
}

void CBoard::SetData(int x, int y, int color)
{
	m_data[x][y] = color;
	Draw(x,y,color);
}

void CBoard::Draw(int x, int y, int color)
{
	CPoint pt;
	pt.x = 12 + 25*x;
	pt.y = 84 + 25*y;
	CDC *dc = GetDC();
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, 0xff);
	dc->SelectObject(&pen);
	dc->SetROP2(R2_NOTXORPEN);

	m_iml.Draw(dc, color, pt, ILD_TRANSPARENT);

	ReleaseDC(dc);
}

void CBoard::Receive()
{
	CFiveChessDlg *dlg = (CFiveChessDlg*)AfxGetMainWnd();
	msg_data msg;
	if(dlg->m_sock.Receive((LPVOID)&msg,sizeof(msg_data)) == SOCKET_ERROR)
	{
		dlg->MessageBox(_T("接收数据时发生错误，请检查网络连接。"),_T("错误"),MB_ICONSTOP);
		return ;
	}
	switch(msg.msg_type)
	{
	case msg_down:
		SetData( msg.x, msg.y, msg.color );
		m_Wait = 0;
		Over(msg.x, msg.y );
		break;
	case msg_draw:
		if(IDYES == dlg->MessageBox(_T("对方请求和棋，接受这个请求吗？"),_T("和棋"),MB_ICONQUESTION |MB_YESNO))
		{
			msg_data msg2;
			msg2.msg_type = msg_ok_draw;
			dlg->send(&msg2);
			SetWait(1);
		}
		else{
			msg_data msg2;
			msg2.msg_type = msg_no_draw;
			dlg->send(&msg2);
		}
		break;
	case msg_ok_draw:
		dlg->MessageBox(_T("看来是棋逢对手，对方接受了你的和棋请求。"),_T("和棋"),MB_ICONINFORMATION);
		break;
	case msg_no_draw:
		dlg->MessageBox(_T("看来对方很有信心取得胜利，所以拒绝了你的和棋请求。"),_T("和棋"),MB_ICONINFORMATION);
		RestoreWait();
		break;
	case msg_other:
		break;
	default:
		break;
	}
}

void CBoard::Over( int x, int y )
{
	rule rule;
	CFiveChessDlg *dlg = (CFiveChessDlg*)AfxGetMainWnd();
	if ( rule.WIN( 1 - m_color, x, y ) == _WIN )
		dlg->MessageBox(_T("您输了，不过不要灰心，失败乃成功之母哦！"),_T("失败"),MB_ICONINFORMATION);
	else if ( rule.WIN( 1 - m_color, x, y ) != _OTHER )
		dlg->MessageBox(_T("恭喜您，获得了胜利！！"),_T("胜利"),MB_ICONINFORMATION);
}

void CBoard::RestoreWait()
{
	SetWait(m_OldWait);
}

void CBoard::DrawGame()
{
	CFiveChessDlg *dlg = (CFiveChessDlg*)AfxGetMainWnd();
	SetWait(1);
	msg_data msg;
	msg.msg_type = msg_draw;
	dlg->send(&msg);
}

void CBoard::OnRestart() 
{
	// TODO: Add your command handler code here
	CFiveChessDlg *dlg = (CFiveChessDlg*)AfxGetMainWnd();
	if ( dlg->m_is_con )
	{
		Clear(1);
		OnPaint();
	}
}
