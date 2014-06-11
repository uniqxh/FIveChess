// FiveChessDlg.h : header file
//

#if !defined(AFX_FIVECHESSDLG_H__F22C4F37_030D_473C_BEE5_A5BED0B3E80A__INCLUDED_)
#define AFX_FIVECHESSDLG_H__F22C4F37_030D_473C_BEE5_A5BED0B3E80A__INCLUDED_

#include "Board.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFiveChessDlg dialog

class CFiveChessDlg : public CDialog
{
// Construction
public:
	CBoard m_board;
	CFiveChessDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFiveChessDlg)
	enum { IDD = IDD_FIVECHESS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFiveChessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFiveChessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIVECHESSDLG_H__F22C4F37_030D_473C_BEE5_A5BED0B3E80A__INCLUDED_)
