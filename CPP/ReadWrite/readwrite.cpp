#include"readwrite.h"

void Comfunctions::getErrRate(char *decode_output, int decode_len, char *basedata, int basedatalen, float *iErrRate)
{
    int iErrNum = basedatalen * 0.1; // 误码容限
    float rate_each = 0;
    int compare_time = 0;
    int err_relay = 0;
    int correctbit = 0;
    bool statistics = true;

    for (int j = 0; j < decode_len - basedatalen; j++)
    {
        correctbit = 0;
        err_relay = 0;

        for (int m = 0; m < basedatalen; m++)
        {
            if (basedata[m] != decode_output[j + m])
            {
                err_relay++;
            }
            else
            {
                correctbit++;
            }

            if (err_relay > iErrNum)
            {
                statistics = false;
                break;
            }
        }

        // 大于错误容限，直接进行下一次比较
        if (statistics)
        {
            if ((basedatalen - correctbit) > iErrNum)
            {
                continue;
            }
            else
            {
                rate_each += (basedatalen - correctbit) / basedatalen;
                compare_time++;
            }
        }
    }

    *iErrRate = rate_each / compare_time;
}

// 按字节流读取float型文件
int Comfunctions::ReadFile(const string &path, float *outputdata, int &numFloats)
{
    // 打开文件，使用二进制模式读取
    ifstream file(path, ios::binary);

    // 检查文件是否成功打开
    if (!file.is_open())
    {
        cerr << "无法打开文件！" << endl;
        return -1;
    }

    // 移动文件指针到文件末尾以计算文件的大小
    file.seekg(0, ios::end);
    size_t fileSize = file.tellg(); // 获取文件的大小
    file.seekg(0, ios::beg);        // 将文件指针移回开头

    // 分配缓冲区来存储文件内容
    char *buffer = new char[fileSize];

    // 读取文件内容到缓冲区中
    file.read(buffer, fileSize);
    if (fileSize % sizeof(float) != 0)
    {
        cerr << "文件大小不是float 大小的整数倍！" << endl;
    }

    numFloats = fileSize / sizeof(float); // 计算有多少个 float 数据

    // 关闭文件
    file.close();

    memcpy(outputdata, buffer, fileSize);

    delete[] buffer;

    return 0;
}

/*
    在 C++ 中读取 .txt 文件时，文件内容通常是以字符形式存储的，
    因此直接读取文本文件中的 0 和 1 时，会默认读取到字符 '0' 和 '1'。
    这是因为文本文件是以字符流形式存储的。
*/
int Comfunctions::ReadFile(const string &path, char *outputdata, int &numchars)
{
    // 打开文件，使用二进制模式读取
    ifstream file(path, ios::binary);

    // 检查文件是否成功打开
    if (!file.is_open())
    {
        cerr << "无法打开文件！" << endl;
        return -1;
    }

    // 移动文件指针到文件末尾以计算文件的大小
    file.seekg(0, ios::end);
    size_t fileSize = file.tellg(); // 获取文件的大小
    file.seekg(0, ios::beg);        // 将文件指针移回开头

    // 分配缓冲区来存储文件内容
    char *buffer = new char[fileSize];

    // 读取文件内容到缓冲区中
    file.read(buffer, fileSize);

    // 关闭文件
    file.close();

    numchars = fileSize;
    memcpy(outputdata, buffer, fileSize);

    return 0;

}

int Comfunctions::ReadFile(const string &path, complex<float> *outputdata, int &floatnum, int &complexnum)
{
    // 打开文件，使用二进制模式读取
    ifstream file(path, ios::binary);

    // 检查文件是否成功打开
    if (!file.is_open())
    {
        cerr << "无法打开文件！" << endl;
        return -1;
    }

    // 移动文件指针到文件末尾以计算文件的大小
    file.seekg(0, ios::end);
    size_t fileSize = file.tellg(); // 获取文件的大小
    file.seekg(0, ios::beg);        // 将文件指针移回开头

    // 分配缓冲区来存储文件内容
    char *buffer = new char[fileSize];

    // 读取文件内容到缓冲区中
    file.read(buffer, fileSize);
    if (fileSize % sizeof(float) != 0)
    {
        cerr << "文件大小不是float 大小的整数倍！" << endl;
    }

    floatnum = fileSize / sizeof(float); // 计算有多少个 float 数据
    complexnum = floatnum / 2;

    // 关闭文件
    file.close();

    memcpy(outputdata, buffer, fileSize);

    delete[] buffer;

    return 0;
}

// 按float型数组按字节流写入文件
// path:写入文件路径
// data:需要写入的float型数组
// sizenum:需要写入的float型数组长度
int Comfunctions::WriteFile(const string &path, float *data, int sizenum)
{
    // 以二进制模式打开文件
    ofstream file(path, ios::binary|ios::app);

    if (!file.is_open())
    {
        cerr << "文件无法打开！" << endl;
        return -1;
    }

    // 将float 数组转换为字节流并写入文件
    file.write(reinterpret_cast<const char *>(data), sizeof(float) * sizenum);

    // 关闭文件
    file.close();

    return 0;
}

int Comfunctions::WriteFile(const string &path, complex<float> *data, int complexnum)
{
    // 以二进制模式打开文件
    ofstream file(path, ios::binary);

    if (!file.is_open())
    {
        cerr << "文件无法打开！" << endl;
        return -1;
    }

    // 将float 数组转换为字节流并写入文件
    file.write(reinterpret_cast<const char *>(data), sizeof(float) * complexnum * 2);

    // 关闭文件
    file.close();

    return 0;
}

/*
    input: num整数(十进制)，类型uint8_t
    return value: num-->格雷码-->格雷码对应整数(十进制)
*/
uint8_t Comfunctions::decimalToGray(uint8_t num)
{
    return num ^ (num >> 1); // num >> 1右移后左边补零，^为按位异或操作
}

/*
    input: num整数(十进制)，类型uint8_t
    return value: num-->格雷译码-->格雷译码码对应整数(十进制)
*/
uint8_t Comfunctions::grayToDecimal(uint8_t gray) {
    uint8_t binary = gray;  // 初始化解码结果
    while (gray >>= 1) {
        binary ^= gray;  // 逐位异或，解码格雷码
    }
    return binary;
}


/*
    input:
        parameter1: value整数(十进制)，类型uint8_t,
        parameter2: bitnum为value转化为二进制的最长位数
    return value:  value转化为二进制，类型 string
*/
string Comfunctions::extractLastSixBitsToString(uint8_t value, int bitnum)
{
    string binaryString;
    if (bitnum == 1)
    {
        value = value & 0b1;
        binaryString = bitset<1>(value).to_string();
    }
    else if (bitnum == 2)
    {
        value = value & 0b11;
        binaryString = bitset<2>(value).to_string();
    }
    else if (bitnum == 3)
    {
        value = value & 0b111;
        binaryString = bitset<3>(value).to_string();
    }
    else if (bitnum == 4)
    {
        value = value & 0b1111;
        binaryString = bitset<4>(value).to_string(); // bitset 是 C++ 标准库中的一个模板类，用于表示固定大小的位集合。
    }
    else if (bitnum == 5)
    {
        value = value & 0b11111;
        binaryString = bitset<5>(value).to_string();
    }
    else if (bitnum == 6)
    {
        value = value & 0b111111; // 按位与，保证低6位的值
        // 将提取后的值转换为6位的二进制字符串，这里的 <6> 指定了位集合的大小为6位。
        binaryString = bitset<6>(value).to_string(); // to_string() 成员函数将 bitset 对象转换为一个字符串
    }
    else if (bitnum == 7)
    {
        value = value & 0b1111111; // 按位与，保证低7位的值
        binaryString = bitset<7>(value).to_string();
    }
    else if (bitnum == 8)
    {
        value = value & 0b11111111;
        binaryString = bitset<8>(value).to_string();
    }
    return binaryString;
}

/*
    function: 将char类型元素写出bin文件
    input:
        parameter1: input数组(十进制)，类型uint8_t*,
        parameter2: inum为input数组长度
        parameter3: bitnum为value转化为二进制的最长位数
    return value:  value转化为二进制，类型 string
*/

void Comfunctions::write_bin(const string &filepath, uint8_t *input, int inum, int bitnum)
{
    for (int i = 0; i < inum; i++)
    {
        input[i] = decimalToGray(input[i]);
    }

    // 存储连续的字符串
    string concatenatedString; // string 可以看作是一个动态数组，能够根据需要自动调整大小
    if ((inum * bitnum) % 8 == 0)
    {
        // 提取每个元素的后6位，并拼接成一个长字符串
        for (int i = 0; i < inum; i++)
        {
            string binaryString = extractLastSixBitsToString(input[i], bitnum);
            concatenatedString += binaryString; // 将 extractLastSixBitsToString 函数返回的字符串
                                                // binaryString 连接到 concatenatedString 变量上。
        }
    }
    else
    {
        for (int i = 0; i < inum; i++)
        {
            string binaryString = extractLastSixBitsToString(input[i], bitnum);
            concatenatedString += binaryString;
        }
        // 添加bitnum个二进制的0
        for (int i = 0; i < 8 - ((inum * bitnum) % 8); i++)
        {
            concatenatedString += '0'; // 在每次迭代中，将一个 '0' 字符追加到 concatenatedString 的末尾。
        }
    }

    int charnum = ceil(inum * bitnum / 8.0); // 需要的char型字符个数
    // vector<char>chars(charnum);
    char *chars = new char[charnum];
    // 将字符串拆分并存储到chars数组中
    for (int i = 0; i < charnum; i++)
    {
        string subStr = concatenatedString.substr(i * 8, 8); // 从i*8开始提取8位
        char value = static_cast<char>(stoi(subStr, nullptr, 2));
        chars[i] = value;
    }

    // 写入二进制文件
    ofstream outfile(filepath, ios::out | ios::binary);
    outfile.write(chars, charnum);
    outfile.close();
    delete[] chars;
}

/*
    function: 读取bin文件，并将读取内容存放到char类型数组
    output:
        parameter1: output数组(十进制)，类型uint8_t*,
        parameter2: inum为output数组长度
    return value: 
                 1 ---- 读取成功 
                 -1 --- 读取失败 
*/
int Comfunctions::read_bin(const string &filepath, uint8_t *output, int* inum)
{

    // 打开二进制文件
    ifstream file(filepath, ios::binary);
    if (!file) {
        cerr << "无法打开文件 " << filepath << endl;
        return -1;
    }

    // 获取文件大小
    file.seekg(0, ios::end);
    streamsize fileSize = file.tellg();
    file.seekg(0, ios::beg);

    *inum = fileSize;

    // 动态分配char数组来存储文件内容
    char* buffer = new char[fileSize];

    // 读取文件内容
    if (!file.read(buffer, fileSize)) 
    {
         cerr << "无法读取bin文件 " << filepath << endl;
        return -1;
    }

    memcpy(output,buffer,sizeof(char)*fileSize);

    // 释放动态分配的内存
    delete[] buffer;

    // 关闭文件
    file.close();

    return 1;
}


/*
    function: 将txt文件中的bin
    input:
        parameter1: input数组(十进制)，类型uint8_t*,
        parameter2: inum为input数组长度
        parameter3: bitnum为value转化为二进制的最长位数
    return value:  value转化为二进制，类型 string
*/

