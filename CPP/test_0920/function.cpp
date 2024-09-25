#include"function.h"

void comfunctions::getErrRate(char *decode_output, int decode_len, char *basedata, int basedatalen, float *iErrRate)
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

    *iErrRate = rate_each/compare_time;
}

// 按字节流读取float型文件
int comfunctions::ReadFile(const string& path ,float *outputdata,int& numFloats)
{
    // 打开文件，使用二进制模式读取
    ifstream file(path,ios::binary);

    // 检查文件是否成功打开
    if(!file.is_open())
    {
        cerr<<"无法打开文件！"<<endl;
        return -1;
    }

    // 移动文件指针到文件末尾以计算文件的大小
    file.seekg(0,ios::end);
    size_t fileSize = file.tellg();    // 获取文件的大小
    file.seekg(0,ios::beg);            // 将文件指针移回开头

    // 分配缓冲区来存储文件内容
    char *buffer = new char[fileSize];

    // 读取文件内容到缓冲区中
    file.read(buffer,fileSize);
    if(fileSize%sizeof(float)!=0)
    {
        cerr<<"文件大小不是float 大小的整数倍！"<<endl;
    }

    numFloats = fileSize / sizeof(float);       // 计算有多少个 float 数据

    // 关闭文件
    file.close();

    memcpy(outputdata,buffer,fileSize);

    return 0;
}

int comfunctions::ReadFile(const string& path ,complex *outputdata,int& floatnum,int& complexnum)
{
        // 打开文件，使用二进制模式读取
    ifstream file(path,ios::binary);

    // 检查文件是否成功打开
    if(!file.is_open())
    {
        cerr<<"无法打开文件！"<<endl;
        return -1;
    }

    // 移动文件指针到文件末尾以计算文件的大小
    file.seekg(0,ios::end);
    size_t fileSize = file.tellg();    // 获取文件的大小
    file.seekg(0,ios::beg);            // 将文件指针移回开头

    // 分配缓冲区来存储文件内容
    char *buffer = new char[fileSize];

    // 读取文件内容到缓冲区中
    file.read(buffer,fileSize);
    if(fileSize%sizeof(float)!=0)
    {
        cerr<<"文件大小不是float 大小的整数倍！"<<endl;
    }

    floatnum = fileSize / sizeof(float) ;       // 计算有多少个 float 数据
    complexnum = floatnum / 2; 
    
    // 关闭文件
    file.close();

    memcpy(outputdata,buffer,fileSize);

    return 0;
}


// 按float型数组按字节流写入文件
// path:写入文件路径
// data:需要写入的float型数组
// sizenum:需要写入的float型数组长度
int comfunctions::WriteFile(const string& path ,float* data,int sizenum)
{
    // 以二进制模式打开文件
    ofstream file(path,ios::binary);

    if(!file.is_open())
    {
        cerr<<"文件无法打开！"<<endl;
        return -1;
    }

    // 将float 数组转换为字节流并写入文件
    file.write(reinterpret_cast<const char*>(data),sizeof(float)*sizenum);

    // 关闭文件
    file.close();

    return 0;
}

  int comfunctions::WriteFile(const string& path ,complex * data,int complexnum)
  {
        // 以二进制模式打开文件
    ofstream file(path,ios::binary);

    if(!file.is_open())
    {
        cerr<<"文件无法打开！"<<endl;
        return -1;
    }

    // 将float 数组转换为字节流并写入文件
    file.write(reinterpret_cast<const char*>(data),sizeof(float)*complexnum*2);

    // 关闭文件
    file.close();

    return 0;
  }  

int main()
{
    comfunctions comfunction;
    int floatnum = 0;
    int cpmlexnum = 0 ;
    // float* output = new float[655360];
    complex* output = new complex[655360];
    string filePath = "C:\\Users\\PC\\Desktop\\outdata.dat";  

    comfunction.ReadFile(filePath,output,floatnum,cpmlexnum);
    
    for (size_t i = 0; i < cpmlexnum; i++)
    {
        cout<<output[i].I<<"  "<<output[i].Q<<endl;                              
    }

    filePath = "C:\\Users\\PC\\Desktop\\outdata.dat";  
    comfunction.WriteFile(filePath,output,cpmlexnum);


    return 0;
}

