#ifndef _SELF_STRING_H
#define _SELF_STRING_H

#include <string>

std::string zfill(std::string str,int num);
void printPath();
std::string int2string(int i,int num);
std::string float2HEX(const float &f);
void replace_str(std::string &str, const std::string &before, const std::string &after);
#endif
