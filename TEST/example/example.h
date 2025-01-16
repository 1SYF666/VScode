#pragma once
#include"../ipp/computing_interface.h"
#include"../readwrite/readwrite.h"
#include"../fcwt/fcwt.h"
class ParameterEst
{
public:
	ParameterEst();
	//~ParameterEst();
	virtual void estimation(float* real, float* imag, int size, int nfft, int fs, int n = 2)
	{
		printf("ERROR [generate time complex]:Override this virtual class");
	};

	ComputingInterface* interfaceipp;
public:


private:



};

class PmbpEst :public ParameterEst
{
public:
	PmbpEst();
	//~PmbpEst();
	void estimation(float* real, float* imag, int size,  int nfft, int fs, int n=2);


private:
	float f0;
	float f1;
	int fn;
	int nthreads;
	int newsize;
};




