// rule.cpp: implementation of the rule class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FiveChess.h"
#include "rule.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

rule::rule()
{

}

rule::~rule()
{

}

int rule::WIN(int color, int _x, int _y)
{
	int x,y;
	//"-"
	for( y = 0; y < 15; y++ )
		for( x = 0; x < 11; x++ )
			if( color == m_data[x][y] && color == m_data[x+1][y] && color == m_data[x+2][y] 
				&& color == m_data[x+3][y] && color == m_data[x+4][y] )
				return _WIN;
	//"|"
	for( x = 0; x < 15; x++ )
		for( y = 0; y < 11; y++ )
			if( color == m_data[x][y] && color == m_data[x][y+1] && color == m_data[x][y+2]
				&& color == m_data[x][y+3] && color == m_data[x][y+4] )
				return _WIN;
	//"/"
	for( x = 14; x > 4; x-- )
		for( y = 0; y < 11; y++)
			if( color == m_data[x][y] && color == m_data[x-1][y+1] && color == m_data[x-2][y+2]
				&& color == m_data[x-3][y+3] && color == m_data[x-4][y+4] )
				return _WIN;
	// "\"
	for( y = 0; y <11; y++ )
		for( x = 0; x < 11; x++)
			if( color == m_data[x][y] && color == m_data[x+1][y+1] && color == m_data[x+2][y+2]
				&& color == m_data[x+3][y+3] && color == m_data[x+4][y+4] )
				return _WIN;
	return _OTHER;
}
