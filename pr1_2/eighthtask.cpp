#include "eighthtask.h"
#include "ui_eighthtask.h"
#include <bitset>
#include <logoperation.h>
#include <vector>
using namespace std;

typedef vector<char> Chars;
typedef vector<int> Ints;
typedef bitset<67> Bits;

EighthTask::EighthTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EighthTask)
{
    ui->setupUi(this);
}

EighthTask::~EighthTask()
{
    delete ui;
}

void EighthTask::on_intOperation_clicked()
{
    QString outInt = "";
    Ints ints_1{1,2,3}, ints_2{1,2,3,4,5};
    IntPrinter intsOutput;
    And<int> and_logics_ints;
    Or<int> or_logics_ints;
    Xor<int> xor_logics_ints;
    Not<int> not_logics_ints;
    Ints andInts = and_logics_ints(ints_1, ints_2);
    outInt += "\nAnd: "+intsOutput(andInts);
    Ints orInts = or_logics_ints(ints_1, ints_2);
    outInt += "\nOr: "+intsOutput(orInts);
    Ints xorInts = xor_logics_ints(ints_1, ints_2);
    outInt += "\nXor: "+intsOutput(xorInts);
    Ints notInts = not_logics_ints(ints_1);
    outInt += "\nNot vector 1: "+intsOutput(notInts);
    Ints notints_2 = not_logics_ints(ints_2);
    outInt += "\nNot vector 2: "+intsOutput(notints_2);
    ui->int1->setText(intsOutput(ints_1));
    ui->int2->setText(intsOutput(ints_2));
    ui->outInt->setText(outInt);
}


void EighthTask::on_CharOperation_clicked()
{
    QString outChar = "";
    CharPrinter charsOutput;
    Chars chars_1{'a','b','c'}, chars_2{'a','b','d','e'};
    And<char> and_logics_chars;
    Or<char> or_logics_chars;
    Xor<char> xor_logics_chars;
    Not<char> not_logics_chars;
    Chars andChars = and_logics_chars(chars_1, chars_2);
    outChar+="\nAnd: "+charsOutput(andChars);
    Chars orChars = or_logics_chars(chars_1, chars_2);
    outChar+= "\nOr: "+charsOutput(orChars);
    Chars xorChars = xor_logics_chars(chars_1, chars_2);
    outChar+= "\nXor: "+charsOutput(xorChars);
    Chars notChars = not_logics_chars(chars_1);
    outChar+= "\nNot vector 1: "+charsOutput(notChars);
    Chars notchars_2 = not_logics_chars(chars_2);
    outChar+="\nNot vector 2: "+charsOutput(notchars_2);
    ui->char1->setText(charsOutput(chars_1));
    ui->char2->setText(charsOutput(chars_2));
    ui->OutChar->setText(outChar);
}


void EighthTask::on_bitsetOperation_clicked()
{
    QString outBitset = "";
    BitsetPrinter bitsetOutput;
    vector<Bits> bits_1{Bits(1), Bits(2), Bits(4)};
    vector<Bits> bits_2{Bits(0), Bits(2)};
    And<Bits> and_logics_bits;
    Or<Bits> or_logics_bits;
    Not<Bits> not_logics_bits;
    Xor<Bits> xor_logics_bits;
    vector<Bits> andBits = and_logics_bits(bits_1, bits_2);
    vector<Bits> orBits = or_logics_bits(bits_1, bits_2);
    vector<Bits> notbits_1 = not_logics_bits(bits_1);
    vector<Bits> notbits_2 = not_logics_bits(bits_2);
    vector<Bits> xorBits = xor_logics_bits(bits_1, bits_2);
    outBitset += "\nAnd: "+bitsetOutput(andBits);
    outBitset += "\nOr: "+bitsetOutput(orBits);
    outBitset += "\nXor: "+bitsetOutput(xorBits);
    outBitset += "\nNot vector 1: "+bitsetOutput(notbits_1);
    outBitset += "\nNot vector 2: "+bitsetOutput(notbits_2);
    ui->bitset1->setText(bitsetOutput(bits_1));
    ui->bitset2->setText(bitsetOutput(bits_2));
    ui->OutBitset->setText(outBitset);
}

void EighthTask::on_delPushButton_clicked()
{
    ui->int1->setText("");
    ui->int2->setText("");
    ui->outInt->setText("");
    ui->char1->setText("");
    ui->char2->setText("");
    ui->OutChar->setText("");
    ui->bitset1->setText("");
    ui->bitset2->setText("");
    ui->OutBitset->setText("");
}
