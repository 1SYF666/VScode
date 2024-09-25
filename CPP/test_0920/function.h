#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct complex
{
    float I;
    float Q;
};

class comfunctions
{private:
    /* data */

public:
    comfunctions(/* args */);
    ~comfunctions();

    void getErrRate(char *decode_output, int decode_len, char *basedata, int basedatalen, float *iErrRate);
    int ReadFile(const string& path ,float *outputdata,int& numFloats);
    int WriteFile(const string& path ,float* data,int sizenum);
    int ReadFile(const string& path ,complex *outputdata,int& numFloats,int& complexnum);
    int WriteFile(const string& path ,complex * data,int complexnum);
    
};

comfunctions::comfunctions(/* args */)
{
}

comfunctions::~comfunctions()
{
}


