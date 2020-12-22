#include <string>
#include "unistd.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

void printPath()
{
    char   buffer[100];
    getcwd(buffer, 100);
    cout<<"The current directory is: "<<buffer<<endl;
}

/**
 * 字符串替换函数
 * #function name   : replace_str()
 * #param str       : 操作之前的字符串
 * #param before    : 将要被替换的字符串
 * #param after     : 替换目标字符串
 * #return          : void
 */
void replace_str(std::string &str, const std::string &before, const std::string &after) {
    for (std::string::size_type pos(0); pos != std::string::npos; pos += after.length()) {
        pos = str.find(before, pos);
        if (pos != std::string::npos)
            str.replace(pos, before.length(), after);
        else
            break;
    }
}

string int2string(int i,int num)
{
    std::string str = std::to_string(i);
    while (str.size() < num)
        str = "0" + str;
    return str;
}

string zfill(string str,int num)
{
    string out_str=str;
    if(out_str.empty())
        out_str="0";
    for(int i=0; i<num; i++)
    {
        if(str.size()<i+1)
        {
            out_str="0" + out_str;
        } else {

        }

    }
    return out_str;
}

std::string float2HEX(const float &f) {
  std::string ret, tmp;
  std::stringstream stream;
  unsigned char *btemp = (unsigned char *) &f;
  unsigned char blist[4];
  blist[0] = *btemp;
  blist[1] = *(btemp + 1);
  blist[2] = *(btemp + 2);
  blist[3] = *(btemp + 3);
  int a[4];
  for (int i = 3; i >= 0; --i) {
    a[i] = (int) blist[i];
    if (a[i] < 16) {
      stream << std::setiosflags(std::ios::uppercase) << std::hex << "0" << (int) blist[i] << " ";
    } else {
      stream << std::setiosflags(std::ios::uppercase) << std::hex << (int) blist[i] << " ";
    }
    stream >> tmp;
    ret += tmp + " ";
  }
  return ret;
}
