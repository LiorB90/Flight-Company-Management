#pragma once
#include <iostream>
using namespace std;

class CPlane
{
protected:
	virtual void		print(ostream& out) const;

public:

	const static int START_NUM= 100;

	CPlane(int seats,const char* degem);
	CPlane(const CPlane& other);
	virtual ~CPlane();
		

	int							GetNum()   const {return m_iNum;}
	int							GetSeats() const {return m_iSeats;}
	const char*					GetDegem() const {return m_pDegem;}
		
	//void		Print(ostream& out) const;
	friend ostream&				operator << (ostream& out, const CPlane& plane) ;
	const	CPlane&				operator ++ ();
	CPlane						operator ++ (int);
	virtual const	CPlane&		operator =  (const CPlane& plane);
	bool						operator == (const CPlane& plane);
	virtual CPlane*				clone()		const { return new CPlane(*this); }

	//bool		IsEqual(const CPlane& other) const;


private:
	static int m_siLastNum;
	int		m_iNum;
	int 	m_iSeats;
	char* 	m_pDegem;	
	
	void		SetDegem(const char* degem);

};

