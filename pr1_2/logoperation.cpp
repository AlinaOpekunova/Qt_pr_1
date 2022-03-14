#include "logoperation.h"
#include <vector>
#include <iostream>
#include <bitset>

QString IntPrinter::operator()(std::vector<int> &numbers){
    QString outInt = "";
    for (std::vector<int>::const_iterator i = numbers.begin(); i != numbers.end(); i++)
        outInt += QString::number(*i)+" ";
    return outInt;

}

QString CharPrinter::operator()(std::vector<char> &chars){
    QString outChar = "";
    for (std::vector<char>::const_iterator i = chars.begin(); i != chars.end(); ++i)
        outChar += QString(QChar::fromLatin1(*i))+" ";
    return outChar;
}

QString BitsetPrinter::operator()(std::vector<bitset<67>> &chars){
    QString outBit = "";
    for(unsigned int i=0;i<chars.size();i++)
        outBit.append(QString::fromStdString(chars[i].to_string()));
    return outBit;
}
