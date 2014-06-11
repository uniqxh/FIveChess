#if !defined(AFX_BOARD_H__C97CA127_902C_4C66_B39B_F41E12A1D04A__INCLUDED_)
#define AFX_BOARD_H__C97CA127_902C_4C66_B39B_F41E12A1D04A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Board.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBoard window

class CBoard : public CWnd
{
// Construction
public:
	CBoard();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBoard)
	//}}AFX_VIRTUAL

// Implementation
public:
	void Clear( BOOL bWait );
	virtual ~CBoard();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBoard)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_color;
	CImageList m_iml;
	BOOL m_OldWait;
	BOOL m_Wait;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOARD_H__C97CA127_902C_4C66_B39B_F41E12A1D04A__INCLUDED_)
