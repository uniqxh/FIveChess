#if !defined(AFX_CONNECTION_H__3557AEF2_726D_437C_8D85_9DBBA54D123E__INCLUDED_)
#define AFX_CONNECTION_H__3557AEF2_726D_437C_8D85_9DBBA54D123E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Connection.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CConnection command target

class CConnection : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	CConnection();
	virtual ~CConnection();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConnection)
	public:
	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CConnection)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONNECTION_H__3557AEF2_726D_437C_8D85_9DBBA54D123E__INCLUDED_)
