#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <bitset>
using namespace std;

struct complex
{
    float I;
    float Q;
};

class Comfunctions
{
private:
    /* data */

public:
    // Comfunctions(/* args */);
    // ~Comfunctions();

    void getErrRate(char *decode_output, int decode_len, char *basedata, int basedatalen, float *iErrRate);
    int WriteFile(const string &path, float *data, int sizenum);
    int WriteFile(const string &path, complex *data, int complexnum);

    int ReadFile(const string &path, float *outputdata, int &numFloats);
    int ReadFile(const string &path, char *outputdata, int &numFloats);
    int ReadFile(const string &path, complex *outputdata, int &numFloats, int &complexnum);

    string extractLastSixBitsToString(uint8_t value, int bitnum);
    uint8_t decimalToGray(uint8_t num);
    uint8_t grayToDecimal(uint8_t gray);
    void write_bin(const string &filepath, uint8_t *input, int inum, int bitnum);
    int read_bin(const string &filepath, uint8_t *input, int* inum);

    



};

// Comfunctions::Comfunctions(/* args */)
// {
// }

// Comfunctions::~Comfunctions()
// {
// }
