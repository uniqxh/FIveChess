// Board.cpp : implementation file
//

#include "stdafx.h"
#include "FiveChess.h"
#include "Board.h"

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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CBoard message handlers

void CBoard::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
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
	//MessageBox("AA");
    Invalidate();
	//MessageBox("AAA");
	//OnPaint();
	//UpdateWindow( );
}
