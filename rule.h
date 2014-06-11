// rule.h: interface for the rule class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RULE_H__54B4B45B_1C75_447B_BA7B_0C36C3F1B529__INCLUDED_)
#define AFX_RULE_H__54B4B45B_1C75_447B_BA7B_0C36C3F1B529__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define _WIN 0
#define _LOST 1
#define _OTHER 2

class rule  
{
public:
	int WIN(int color,int _x,int _y);
	rule();
	virtual ~rule();

};

#endif // !defined(AFX_RULE_H__54B4B45B_1C75_447B_BA7B_0C36C3F1B529__INCLUDED_)
