#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#define MEMSIZE 65536

//#include "mainwindow.h"
#include "ui_mainwindow.h"

typedef unsigned char byte;
typedef struct node *NextNode;
typedef struct node *list;

struct node{
    unsigned int address;
    char sign[20];
    NextNode next;
};

class assembler
{
private:
    unsigned int pc,ir;
    unsigned int reg[32];
    byte memory[MEMSIZE];
    unsigned int address;
    list sign_list;
public:
    assembler();
    int assemble(char* buf);
    void reset();
    void reverse_assemble(unsigned int input, char* buf,unsigned int cur_address);
    unsigned int switch_Register(char* temp);
    void switch_Number(unsigned int input,char* output);
    void numToString(unsigned int result,char* output);
    void shiftReg(Ui::MainWindow *ui);
    void shiftAddress(Ui::MainWindow *ui);
    void shiftad(Ui::MainWindow *ui);
    void shiftad_2(Ui::MainWindow *ui);
    void shiftad_3(Ui::MainWindow *ui);
    void shiftad_4(Ui::MainWindow *ui);
    int cal(char* temp);
    void jumpal();
    void exec();
    void add();
    void addu();
    void sw();
    void jump();
    void sub();
    void subu();
    void lw();
    void slt();
    void sltu();
    void beq();
    void bne();
    void jr();
    void addi();
    void addiu();
    void slti();
    void sltiu();
    void andi();
    void ori();
    void xori();
    void orx();
    void xorx();
    void nor();
    void mthi();
    void mflo();
    void mtlo();
    void mfhi();
    void sllv();
    void srlv();
    void srav();
    void sll();
    void srl();
    void sra();

};

#endif // ASSEMBLER_H
