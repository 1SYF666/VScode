#define _CRT_SECURE_NO_WARNINGS 1
#include"example.h"

ParameterEst::ParameterEst()
{
	interfaceipp = new ComputingInterface();

}

PmbpEst::PmbpEst()
{
	f0 = 0;
	f1 = 0;
	fn = 0;
	nthreads = 8;
	newsize = 0;

}


void PmbpEst::estimation(float* real, float* imag, int size,int nfft, int fs, int n)
{
	Comfunctions h;
	float valuetemp[10] = { 0 };
	int indextemp[10] = { 0 };
	// nomoralization
	interfaceipp->LhtNormInfFloat(real, size, valuetemp, 1);
	interfaceipp->LhtNormalizeFloat(real, size, real, 0, valuetemp[0]);
	interfaceipp->LhtNormInfFloat(imag, size, valuetemp, 1);
	interfaceipp->LhtNormalizeFloat(imag, size, imag, 0, valuetemp[0]);

	string path = "C:\\Users\\PC/Desktop\\cwt\\re.dat";
	h.WriteFile(path, real, size);

	path = "C:\\Users\\PC/Desktop\\cwt\\im.dat";
	h.WriteFile(path, imag, size);


	// fft
	if (size < nfft)
	{
		//find nearest power of 2
		const int nt = find2power(size);
		nfft = 1 << nt;
	}


	vector<float> fftre(nfft);
	vector<float> fftim(nfft);
	vector<float> fftout(nfft);

	memcpy(fftre.data(), real, sizeof(float) * nfft);
	memcpy(fftim.data(), imag, sizeof(float) * nfft);

	interfaceipp->LhtFftInitFloat(nfft);   // fft��ʼ��
	interfaceipp->LhtFftFloat(fftre.data(), fftim.data(), nfft, fftout.data());  // fftshift �� Ϊģֵ
	interfaceipp->LhtFftFreeFloat();  // �ڴ��ͷ�

	path = "C:\\Users\\PC/Desktop\\cwt\\fftout.dat";
	h.WriteFile(path, fftout.data(), size);

	// find max value and corresponding index 
	ippsMaxIndx_32f(fftout.data(), nfft, valuetemp, indextemp);

	valuetemp[0] = (indextemp[0] - nfft / 2) * ((float)fs / (float)nfft);  // ���ز�

	// downfrequence
	interfaceipp->LhtdownOrthConversion(real, imag, size, -(int)valuetemp[0], fs, real, imag);
	
	path = "C:\\Users\\PC/Desktop\\cwt\\downre.dat";
	h.WriteFile(path, real, size);
	path = "C:\\Users\\PC/Desktop\\cwt\\downim.dat";
	h.WriteFile(path, imag, size);


	// ����Ƶfft
	vector<float> realPart(size);
	vector<float> imagPart(size);

	// ��ʱ�������ڴ洢�м���
	vector<float> tempReal(size);
	vector<float> tempImag(size);
	memcpy(tempReal.data(), real, sizeof(float) * size);
	memcpy(tempImag.data(), imag, sizeof(float) * size);
	for (int i = 0; i < n/2; i++)
	{
		// ����ʵ��ƽ�����: real^2 - imag^2
		ippsSqr_32f(tempReal.data(), realPart.data(), size); // ʵ��ƽ�� real^2
		ippsSqr_32f(tempImag.data(), imagPart.data(), size); // �鲿ƽ�� imag^2
		ippsSub_32f_I(imagPart.data(), realPart.data(), size); // ʵ����� real^2 - imag^2

		// �����鲿���: 2 * real * imag
		ippsMul_32f(tempReal.data(), tempImag.data(), imagPart.data(), size); // real * imag
		ippsMulC_32f_I(2.0f, imagPart.data(), size); // 2 * real * imag
		
		tempReal = realPart;
		tempImag = imagPart;

	}

	memcpy(fftre.data(), realPart.data(), sizeof(float) * nfft);
	memcpy(fftim.data(), imagPart.data(), sizeof(float) * nfft);

	interfaceipp->LhtFftInitFloat(nfft);   // fft��ʼ��
	interfaceipp->LhtFftFloat(fftre.data(), fftim.data(), nfft, fftout.data());
	interfaceipp->LhtFftFreeFloat();  // �ڴ��ͷ�

	fftout[nfft / 2] = 0;  //����ֱ������

	path = "C:\\Users\\PC/Desktop\\cwt\\fftout2.dat";
	h.WriteFile(path, fftout.data(), size);

	ippsMaxIndx_32f(fftout.data(), nfft, valuetemp, indextemp);
	valuetemp[1] = 0.5*(indextemp[0] - nfft / 2) * ((float)fs / (float)nfft);  // ���ز�

	vector<complex<float>>compdata(size);

	interfaceipp->LhtCopyRealAndimag2Complex((Ipp32fc*)compdata.data(), real, imag, size);

	// fcwt
	Wavelet* wavelet;
	Morlet morl(1.0f);
	wavelet = &morl;

	f0 = 1.f * fs / size;
	f1 = fs / 2.f;
	fn = 132;
	nthreads = 8;

	interfaceipp->LhtFCwtInit(wavelet, FCWT_LOGSCALES, fs, f0, f1, fn, nthreads, 1, 1);

	vector<complex<float>> sigc(size);
	vector<complex<float>> tfm(size * fn);
	vector<float> freq(fn);
	vector<float> diff(fn);
	vector<float> absdiff(fn);

	memcpy(sigc.data(), compdata.data(), sizeof(complex<float>) * size);
	interfaceipp->LhtFCwt(sigc.data(), sigc.size(), tfm.data(), freq.data(), fn);

	newsize = nfft;
	vector<complex<float>> waveletcoefficients(newsize);
	vector<float> fcwtout(newsize);
	// substrct corresponding wavelet coefficients
	ippsSubC_32f(freq.data(), valuetemp[1], diff.data(), fn);
	ippsAbs_32f(diff.data(), absdiff.data(), fn);
	ippsMinIndx_32f(absdiff.data(), fn, valuetemp + 2, indextemp);

	copy(tfm.begin() + indextemp[0] * newsize, tfm.begin() + indextemp[0] * newsize + newsize, waveletcoefficients.begin());

	interfaceipp->LhtCalculateRootOfSumOfSquaresFloat2((Ipp32fc*)(waveletcoefficients.data()), newsize, (float*)(fcwtout.data()));

	path = "C:\\Users\\PC/Desktop\\cwt\\fcwtout.dat";
	h.WriteFile(path, (float*)(fcwtout.data()), newsize);


	// �����������
	float meanvalue = 0;
	interfaceipp->LhtMeanFloat(fcwtout.data(), newsize, &meanvalue);   // �����ֵ
	ippsSubC_32f(fcwtout.data(), meanvalue, fcwtout.data(), newsize);  // ������ÿ��Ԫ�ؼ�ȥ����
	ippsAbs_32f(fcwtout.data(), fcwtout.data(), newsize);			   // �Խ��ȡ����ֵ

	path = "C:\\Users\\PC/Desktop\\cwt\\fcwtoutabs.dat";
	h.WriteFile(path, (float*)(fcwtout.data()), newsize);

	// ��С������
	bool flag = true;
	vector<int> peakindex;
	ippsMaxIndx_32f(fcwtout.data(), newsize, valuetemp+3, indextemp);
	float th = 0.6 * valuetemp[3];
	for (int i = 0; i < newsize -1; i++)
	{
		if (flag&&fcwtout[i]>th&& fcwtout[i] > fcwtout[i+1])
		{
			flag = false;    // �ҵ��嶥
			peakindex.push_back(i);
		}

		if (!flag&& fcwtout[i] < fcwtout[i + 1])
		{
			flag = true;    // �ҵ����
		}

	}

	int intervallen = newsize;
	int temp = 0;
	for (int i = 0; i < peakindex.size()-1; i++)
	{
		temp = peakindex[i + 1] - peakindex[i];
		if (temp < intervallen)
		{
			intervallen = temp;
		}

	}

	valuetemp[2] = (float)fs/(float)intervallen ;    // ��������


}

