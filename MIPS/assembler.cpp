#include "assembler.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <QMessageBox>
#include <QTextEdit>
#include <QDebug>


assembler::assembler()
{
    pc = 0x4000;
    ir = 0;
    memset(reg,0,sizeof(int)*32);
    memset(memory,0, sizeof(byte)*MEMSIZE);
    reg[1] = 1;
    address = 0x0000;
    sign_list = (list )malloc(sizeof(struct node));
    sign_list->next = NULL;
}

void assembler::reset(){
    pc = 0x4000;
    ir = 0;
    memset(reg,0,sizeof(int)*32);
    memset(memory,0, sizeof(byte)*MEMSIZE);
    reg[1] = 1;
    address = 0x0000;
    sign_list = (list )malloc(sizeof(struct node));
    sign_list->next = NULL;

    qDebug()<<pc;

    return;
}

void assembler::shiftad_3(Ui::MainWindow *ui){
    QString str = ui->address->text();
    char *buf;
    unsigned int temp_address;

    QByteArray ba = str.toLatin1();
    buf=ba.data();
    sscanf(buf,"%x",&temp_address);

    if(temp_address<=32){
        temp_address = 0;
    }
    else{
        temp_address -= 32;
    }

    char c[10];

    sprintf(c,"0x%04x",temp_address);

    str = c;

    ui->address->setText(str);
}


void assembler::shiftad_4(Ui::MainWindow *ui){
    QString str = ui->address->text();
    char *buf;
    unsigned int temp_address;

    QByteArray ba = str.toLatin1();
    buf=ba.data();
    sscanf(buf,"%x",&temp_address);

    if(temp_address>=65472){
        temp_address = 65504;
    }
    else{
        temp_address += 32;
    }

    char c[10];

    sprintf(c,"0x%04x",temp_address);

    str = c;

    ui->address->setText(str);

}

void assembler::shiftad(Ui::MainWindow *ui){
    QString str = ui->address_2->text();
    char *buf;

    QByteArray ba = str.toLatin1();
    buf=ba.data();
    sscanf(buf,"%x",&address);

}

void assembler::shiftad_2(Ui::MainWindow *ui){
    char c[10];

    sprintf(c,"0x%04x",address);

    QString str = c;

    ui->address_2->setText(str);
}

void assembler::shiftReg(Ui::MainWindow *ui){
    unsigned int tempreg;
    char c[100];
    QString str;

    tempreg = pc;
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->pc->setText(str);

    tempreg = ir;
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->ir->setText(str);

    tempreg = reg[0];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r0->setText(str);

    tempreg = reg[1];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r1->setText(str);

    tempreg = reg[2];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r2->setText(str);

    tempreg = reg[3];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r3->setText(str);


    tempreg = reg[4];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r4->setText(str);

    tempreg = reg[5];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r5->setText(str);

    tempreg = reg[6];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r6->setText(str);

    tempreg = reg[7];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r7->setText(str);

    tempreg = reg[8];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r8->setText(str);

    tempreg = reg[9];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r9->setText(str);

    tempreg = reg[10];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r10->setText(str);

    tempreg = reg[11];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r11->setText(str);

    tempreg = reg[12];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r12->setText(str);

    tempreg = reg[13];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r13->setText(str);

    tempreg = reg[14];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r14->setText(str);

    tempreg = reg[15];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r15->setText(str);

    tempreg = reg[16];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r16->setText(str);

    tempreg = reg[17];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r17->setText(str);

    tempreg = reg[18];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r18->setText(str);

    tempreg = reg[19];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r19->setText(str);

    tempreg = reg[20];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r20->setText(str);

    tempreg = reg[21];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r21->setText(str);

    tempreg = reg[22];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r22->setText(str);

    tempreg = reg[23];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r23->setText(str);

    tempreg = reg[24];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r24->setText(str);

    tempreg = reg[25];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r25->setText(str);

    tempreg = reg[26];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r26->setText(str);

    tempreg = reg[27];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r27->setText(str);

    tempreg = reg[28];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r28->setText(str);

    tempreg = reg[29];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r29->setText(str);

    tempreg = reg[30];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r30->setText(str);

    tempreg = reg[31];
    sprintf(c,"0x%04x",tempreg);
    str = c;
    ui->r31->setText(str);
}



void assembler::shiftAddress(Ui::MainWindow *ui){
    char *buf;
    char t_address[8][12];
    char label_1[8][10] = {"","","","","","","",""};
    char mac[8][33];
    char inst[8][30];
    list tempnode;
    unsigned int result = 0;
    QString str = ui->address->text();
    unsigned int temp_address, label[8];

    if(NULL ==str){
        QMessageBox::information(NULL, "ERROR","地址栏不能为空！", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }

    QByteArray ba = str.toLatin1();
    buf=ba.data();

    sscanf(buf,"%x",&temp_address);

    for(int i = 0;i<8;i++){
        label[i] = temp_address;
        result = 0;
        sprintf(t_address[i],"0x%04x",label[i]);
        tempnode = sign_list->next;
        while(tempnode != NULL){
            if(tempnode->address == temp_address){
                strcpy(label_1[i],tempnode->sign);
                break;
            }
            tempnode = tempnode->next;
        }
        result += memory[temp_address++]<<24;
        result += memory[temp_address++]<<16;
        result += memory[temp_address++]<<8;
        result += memory[temp_address++];
        reverse_assemble(result,inst[i],temp_address-4);
        sprintf(mac[i],"0x%08x",result);
    }

    str = t_address[0];
    ui->add1->setText(str);
    str = mac[0];
    ui->m1->setText(str);
    str = inst[0];
    ui->l1->setText(str);
    str = label_1[0];
    ui->f1->setText(str);

    str = t_address[1];
    ui->add2->setText(str);
    str = mac[1];
    ui->m2->setText(str);
    str = inst[1];
    ui->l2->setText(str);
    str = label_1[1];
    ui->f2->setText(str);

    str = t_address[2];
    ui->add3->setText(str);
    str = mac[2];
    ui->m3->setText(str);
    str = inst[2];
    ui->l3->setText(str);
    str = label_1[2];
    ui->f3->setText(str);

    str = t_address[3];
    ui->add4->setText(str);
    str = mac[3];
    ui->m4->setText(str);
    str = inst[3];
    ui->l4->setText(str);
    str = label_1[3];
    ui->f4->setText(str);

    str = t_address[4];
    ui->add5->setText(str);
    str = mac[4];
    ui->m5->setText(str);
    str = inst[4];
    ui->l5->setText(str);
    str = label_1[4];
    ui->f5->setText(str);

    str = t_address[5];
    ui->add6->setText(str);
    str = mac[5];
    ui->m6->setText(str);
    str = inst[5];
    ui->l6->setText(str);
    str = label_1[5];
    ui->f6->setText(str);

    str = t_address[6];
    ui->add7->setText(str);
    str = mac[6];
    ui->m7->setText(str);
    str = inst[6];
    ui->l7->setText(str);
    str = label_1[6];
    ui->f7->setText(str);

    str = t_address[7];
    ui->add8->setText(str);
    str = mac[7];
    ui->m8->setText(str);
    str = inst[7];
    ui->l8->setText(str);
    str = label_1[7];
    ui->f8->setText(str);
}

int assembler::assemble(char *buf)
{
    unsigned int result = 0, op = 0, r[3], imm_Num = 0;
    int i, j, k,flag;
    char temp[20];
    NextNode temp_node,node;

    i = 0;
    j = 0;

    while ('\0' != buf[i]) {
        i++;
    }
    if (':' == buf[i - 1]) {
        buf[i - 1] = '\0';
        flag = 1;
        temp_node = sign_list->next;

        while (NULL != temp_node) {

            if (temp_node->address == address || !strcmp(temp_node->sign, buf)) {
                flag = 0;
            }
            temp_node = temp_node->next;
        }


        if (flag) {
            node = (list )malloc(sizeof(struct node));
            node->address = address;
            node->next = NULL;
            strcpy(node->sign, buf);

            temp_node = sign_list;

            while(NULL != temp_node->next){
                temp_node = temp_node->next;
            }
            temp_node->next = node;
            return 1;
        }
        else {
            QMessageBox::information(NULL, "ERROR","当前地址已经存在标签或者当前标签已经存在！", QMessageBox::Yes, QMessageBox::Yes);
            return 0;
        }
    }
    else {
        i = 0;
        while (' ' == buf[i]) {
            i++;
        }

        while (' ' != buf[i]) {
            temp[j] = buf[i];
            i++;
            j++;
        }

        temp[j] = '\0';


        if (!strcmp(temp, "add") || !strcmp(temp, "sub") || !strcmp(temp, "subu") || !strcmp(temp, "addu") || !strcmp(temp, "slt") || !strcmp(temp, "sltu") || !strcmp(temp, "xor") || !strcmp(temp, "nor") || !strcmp(temp, "or") || !strcmp(temp, "sllv") || !strcmp(temp, "srlv") || !strcmp(temp, "srav")) {
            if (!strcmp(temp, "add")) op = 32;

            if (!strcmp(temp, "addu")) op = 33;

            if (!strcmp(temp, "sub")) op = 34;

            if (!strcmp(temp, "subu")) op = 35;

            if (!strcmp(temp, "slt")) op = 42;

            if (!strcmp(temp, "sltu")) op = 43;

            if (!strcmp(temp, "xor")) op = 38;

            if (!strcmp(temp, "nor")) op = 39;

            if (!strcmp(temp, "or")) op = 37;

            if (!strcmp(temp, "sllv")) op = 4;

            if (!strcmp(temp, "srlv")) op = 6;

            if (!strcmp(temp, "srav")) op = 7;

            for (k = 0; k<3; k++) {
                j = 0;

                while (' ' == buf[i] || ',' == buf[i]) i++;

                while (' ' != buf[i] && ',' != buf[i] && '\0' != buf[i]) {
                    temp[j] = buf[i];
                    i++;
                    j++;
                }

                temp[j] = '\0';

                r[k] = switch_Register(temp);
            }

            if(op==4||op==6||op==7){
                result += (r[2] << 21) + (r[1] << 16) + (r[0] << 11) + op;
            }
            else{
                result += (r[1] << 21) + (r[2] << 16) + (r[0] << 11) + op;
            }
        }

        else if (!strcmp(temp, "sw") || !strcmp(temp, "lw")) {

            if (!strcmp(temp, "lw")) op = 35;

            if (!strcmp(temp, "sw")) op = 43;

            j = 0;

            while (' ' == buf[i]) i++;

            while (' ' != buf[i] && ',' != buf[i]) {
                temp[j] = buf[i];
                i++;
                j++;
            }
            temp[j] = '\0';

            r[0] = switch_Register(temp);

            while (' ' == buf[i] || ',' == buf[i]) i++;

            j = 0;
            while (' ' != buf[i] && '(' != buf[i]) {
                temp[j] = buf[i];
                i++;
                j++;
            }

            temp[j] = '=';
            temp[j + 1] = '\0';
            imm_Num = cal(temp);

            while (' ' == buf[i] || '(' == buf[i]) i++;

            j = 0;
            while (' ' != buf[i] && ')' != buf[i]) {
                temp[j] = buf[i];
                i++;
                j++;
            }
            temp[j] = '\0';

            r[1] = switch_Register(temp);

            result = (op << 26) + (r[0] << 22) + (r[1] << 18) + imm_Num;
        }

        else if (!strcmp(temp, "beq") || !strcmp(temp, "bne")) {

            if (!strcmp(temp, "beq")) op = 4;
            if (!strcmp(temp, "bne")) op = 5;

            for (k = 0; k<2; k++) {
                j = 0;

                while (' ' == buf[i] || ',' == buf[i]) i++;

                while (' ' != buf[i] && ',' != buf[i] && '\0' != buf[i]) {
                    temp[j] = buf[i];
                    i++;
                    j++;
                }

                temp[j] = '\0';

                r[k] = switch_Register(temp);
            }

            while (' ' == buf[i] || ',' == buf[i]) i++;
            j = 0;
            while (' ' != buf[i] && '\0' != buf[i]) {
                temp[j] = buf[i];
                i++;
                j++;
            }

            temp[j] = '\0';

            temp_node = sign_list->next;


            while (1) {

                if (NULL == temp_node) {
                    QMessageBox::information(NULL, "ERROR","不存在该标签!", QMessageBox::Yes, QMessageBox::Yes);
                    return 0;
                }
                if (!strcmp(temp, temp_node->sign))
                    break;

                temp_node = temp_node->next;
            }

            //qDebug()<< op;

            result = (op << 26) + (r[0] << 21) + (r[1] << 16) + (0x0FFFF & (((int )temp_node->address -(int )address - 4) >> 2));
        }

        else if (!strcmp(temp, "sll")||!strcmp(temp, "srl")||!strcmp(temp, "sra")) {

            if (!strcmp(temp, "sll")) op = 0;

            if (!strcmp(temp, "srl")) op = 2;

            if (!strcmp(temp, "sra")) op = 3;


            for (k = 0; k<2; k++) {
                j = 0;

                while (' ' == buf[i] || ',' == buf[i]) i++;

                while (' ' != buf[i] && ',' != buf[i] && '\0' != buf[i]) {
                    temp[j] = buf[i];
                    i++;
                    j++;
                }

                temp[j] = '\0';

                r[k] = switch_Register(temp);
            }

            while (' ' == buf[i] || ',' == buf[i]) i++;
            j = 0;

            while (' '!=buf[i]&&'\0'!=buf[i]) {
                temp[j] = buf[i];
                i++;
                j++;
            }

            temp[j] = '=';
            temp[j+1] = '\0';
            imm_Num = cal(temp);


            result = (r[0] << 16) + (r[1] << 11) + (imm_Num << 6) +op;
        }

        else if (!strcmp(temp, "addi")||!strcmp(temp, "addiu")||!strcmp(temp, "slti")||!strcmp(temp, "andi")||!strcmp(temp, "ori")||!strcmp(temp, "sltiu")||!strcmp(temp, "xori")) {

            if (!strcmp(temp, "addi")) op = 8;

            if (!strcmp(temp, "addiu")) op = 9;

            if (!strcmp(temp, "slti")) op = 10;

            if (!strcmp(temp, "sltiu")) op = 11;

            if (!strcmp(temp, "andi")) op = 12;

            if (!strcmp(temp, "ori")) op = 13;

            if (!strcmp(temp, "xori")) op = 14;


            for (k = 0; k<2; k++) {
                j = 0;

                while (' ' == buf[i] || ',' == buf[i]) i++;

                while (' ' != buf[i] && ',' != buf[i] && '\0' != buf[i]) {
                    temp[j] = buf[i];
                    i++;
                    j++;
                }

                temp[j] = '\0';

                r[k] = switch_Register(temp);
            }

            while (' ' == buf[i] || ',' == buf[i]) i++;
            j = 0;

            while (' '!=buf[i]&&'\0'!=buf[i]) {
                temp[j] = buf[i];
                i++;
                j++;
            }

            temp[j] = '=';
            temp[j+1] = '\0';
            imm_Num = cal(temp);


            result = (op << 26) + (r[0] << 21) + (r[1] << 16) + imm_Num ;
        }

        else if (!strcmp(temp, "jr")||!strcmp(temp, "mfhi")||!strcmp(temp, "mflo")||!strcmp(temp, "mthi")||!strcmp(temp, "mtlo")) {
            if(!strcmp(temp, "jr")) op = 8;
            if(!strcmp(temp, "mfhi")) op = 16;
            if(!strcmp(temp, "mflo")) op = 18;
            if(!strcmp(temp, "mthi")) op = 17;
            if(!strcmp(temp, "mtlo")) op = 19;

            j = 0;

            while (' ' == buf[i] || ',' == buf[i]) i++;

            while (' ' != buf[i] && ',' != buf[i] && '\0' != buf[i]) {
                temp[j] = buf[i];
                i++;
                j++;
            }

            temp[j] = '\0';

            r[0] = switch_Register(temp);



            if(op==8||op==17||op==19)
                result = (r[0] << 21) + op;
            else
                result = (r[0] << 11) + op;

        }


    else if (!strcmp(temp, "j")||!strcmp(temp, "jal")) {
        if(!strcmp(temp, "j")) op = 2;
        else op=3;
        j = 0;

        while (' ' == buf[i]) i++;

        j = 0;
        while (' ' != buf[i] && '\0' != buf[i]) {
            temp[j] = buf[i];
            i++;
            j++;
        }

        temp[j] = '\0';

        temp_node = sign_list->next;

        while (1) {
            if (NULL == temp_node) {
                QMessageBox::information(NULL, "ERROR","不存在该标签!", QMessageBox::Yes, QMessageBox::Yes);
                return 0;
            }

            if(!strcmp(temp,temp_node->sign)){
                break;
            }
            temp_node = temp_node->next;
        }



        result = (op << 26) + (temp_node->address >> 2);

    }

    memory[address++] = result >> 24;
    memory[address++] = (result >> 16)&(0x00FF);
    memory[address++] = (result >> 8)&(0x00FF);
    memory[address++] = (result)&(0x00FF);

    return 1;
    }

}

void assembler::reverse_assemble(unsigned int input, char* buf,unsigned int cur_address)
{
    unsigned int ir = input;
    unsigned int op = (input >> 26);
    int r[3];
    int imm_num;
    char reg[3][10];
    char sign[20];
    QString temp1;
    NextNode temp = NULL;

    if(ir == 0){
        sprintf(buf,"nop");
        return;
    }

    switch (op) {
    case 0:
        op = (input)&0x003F;
        switch(op){
        case 0:
            r[0] = (ir >> 16) & 0x001F;
            r[1] = (ir >> 11) & 0x001F;

            imm_num = (ir & 0x07C0) >> 6;


            switch_Number(r[0], reg[0]);
            switch_Number(r[1], reg[1]);



            sprintf(buf, "sll %s, %s, %04x", reg[0], reg[1], imm_num);
            //addiu();
                break;
        case 2:
            r[0] = (ir >> 16) & 0x001F;
            r[1] = (ir >> 11) & 0x001F;

            imm_num = (ir & 0x07C0) >> 6;


            switch_Number(r[0], reg[0]);
            switch_Number(r[1], reg[1]);



            sprintf(buf, "srl %s, %s, %04x", reg[0], reg[1], imm_num);
            //addiu();
                break;
        case 3:
            r[0] = (ir >> 16) & 0x001F;
            r[1] = (ir >> 11) & 0x001F;

            imm_num = (ir & 0x07C0) >> 6;


            switch_Number(r[0], reg[0]);
            switch_Number(r[1], reg[1]);



            sprintf(buf, "sra %s, %s, %04x", reg[0], reg[1], imm_num);
            //addiu();
                break;
        case 4:
            r[0] = (ir >> 21) & 0x001F;
            r[1] = (ir >> 16) & 0x001F;
            r[2] = (ir >> 11) & 0x001F;
            switch_Number(r[0], reg[0]);
            switch_Number(r[1], reg[1]);
            switch_Number(r[2], reg[2]);
            sprintf(buf, "sllv %s, %s, %s", reg[2], reg[0], reg[1]);
            //strcat(buf, " ");
            //strcat(buf, reg[0]);
            //strcat(buf, ",");
            //strcat(buf, )
            break;
        case 6:
            r[0] = (ir >> 21) & 0x001F;
            r[1] = (ir >> 16) & 0x001F;
            r[2] = (ir >> 11) & 0x001F;
            switch_Number(r[0], reg[0]);
            switch_Number(r[1], reg[1]);
            switch_Number(r[2], reg[2]);
            sprintf(buf, "srlv %s, %s, %s", reg[2], reg[0], reg[1]);
            //strcat(buf, " ");
            //strcat(buf, reg[0]);
            //strcat(buf, ",");
            //strcat(buf, )
            break;
        case 7:
            r[0] = (ir >> 21) & 0x001F;
            r[1] = (ir >> 16) & 0x001F;
            r[2] = (ir >> 11) & 0x001F;
            switch_Number(r[0], reg[0]);
            switch_Number(r[1], reg[1]);
            switch_Number(r[2], reg[2]);
            sprintf(buf, "srav %s, %s, %s", reg[2], reg[0], reg[1]);
            //strcat(buf, " ");
            //strcat(buf, reg[0]);
            //strcat(buf, ",");
            //strcat(buf, )
            break;
            case 32:
                r[0] = (ir >> 21) & 0x001F;
                r[1] = (ir >> 16) & 0x001F;
                r[2] = (ir >> 11) & 0x001F;
                switch_Number(r[0], reg[0]);
                switch_Number(r[1], reg[1]);
                switch_Number(r[2], reg[2]);
                sprintf(buf, "add %s, %s, %s", reg[2], reg[0], reg[1]);
                //strcat(buf, " ");
                //strcat(buf, reg[0]);
                //strcat(buf, ",");
                //strcat(buf, )
                break;
            case 34:
                r[0] = (ir >> 21) & 0x001F;
                r[1] = (ir >> 16) & 0x001F;
                r[2] = (ir >> 11) & 0x001F;
                switch_Number(r[0], reg[0]);
                switch_Number(r[1], reg[1]);
                switch_Number(r[2], reg[2]);
                sprintf(buf, "sub %s, %s, %s", reg[2], reg[0], reg[1]);
                //sub(mem);
                break;
        case 33:
            r[0] = (ir >> 21) & 0x001F;
            r[1] = (ir >> 16) & 0x001F;
            r[2] = (ir >> 11) & 0x001F;
            switch_Number(r[0], reg[0]);
            switch_Number(r[1], reg[1]);
            switch_Number(r[2], reg[2]);
            sprintf(buf, "addu %s, %s, %s", reg[2], reg[0], reg[1]);
            //strcat(buf, " ");
            //strcat(buf, reg[0]);
            //strcat(buf, ",");
            //strcat(buf, )
            break;
        case 35:
            r[0] = (ir >> 21) & 0x001F;
            r[1] = (ir >> 16) & 0x001F;
            r[2] = (ir >> 11) & 0x001F;
            switch_Number(r[0], reg[0]);
            switch_Number(r[1], reg[1]);
            switch_Number(r[2], reg[2]);
            sprintf(buf, "subu %s, %s, %s", reg[2], reg[0], reg[1]);
            //sub(mem);
            break;
            case 42:
                r[0] = (ir >> 21) & 0x001F;
                r[1] = (ir >> 16) & 0x001F;
                r[2] = (ir >> 11) & 0x001F;
                switch_Number(r[0], reg[0]);
                switch_Number(r[1], reg[1]);
                switch_Number(r[2], reg[2]);
                sprintf(buf, "slt %s, %s, %s", reg[2], reg[0], reg[1]);
                //slt(mem);
                break;
        case 43:
            r[0] = (ir >> 21) & 0x001F;
            r[1] = (ir >> 16) & 0x001F;
            r[2] = (ir >> 11) & 0x001F;
            switch_Number(r[0], reg[0]);
            switch_Number(r[1], reg[1]);
            switch_Number(r[2], reg[2]);
            sprintf(buf, "sltu %s, %s, %s", reg[2], reg[0], reg[1]);
            //slt(mem);
            break;
            case 37:
                r[0] = (ir >> 21) & 0x001F;
                r[1] = (ir >> 16) & 0x001F;
                r[2] = (ir >> 11) & 0x001F;
                switch_Number(r[0], reg[0]);
                switch_Number(r[1], reg[1]);
                switch_Number(r[2], reg[2]);
                sprintf(buf, "or %s, %s, %s", reg[2], reg[0], reg[1]);
                break;
            case 38:
                r[0] = (ir >> 21) & 0x001F;
                r[1] = (ir >> 16) & 0x001F;
                r[2] = (ir >> 11) & 0x001F;
                switch_Number(r[0], reg[0]);
                switch_Number(r[1], reg[1]);
                switch_Number(r[2], reg[2]);
                sprintf(buf, "xor %s, %s, %s", reg[2], reg[0], reg[1]);
                break;
            case 39:
                r[0] = (ir >> 21) & 0x001F;
                r[1] = (ir >> 16) & 0x001F;
                r[2] = (ir >> 11) & 0x001F;
                switch_Number(r[0], reg[0]);
                switch_Number(r[1], reg[1]);
                switch_Number(r[2], reg[2]);
                sprintf(buf, "nor %s, %s, %s", reg[2], reg[0], reg[1]);
                break;
        case 8:
            r[0] = (ir >> 21) & 0x001F;
            switch_Number(r[0], reg[0]);
            sprintf(buf, "mflo %s", reg[0]);
            break;
        case 16:
            r[0] = (ir >> 11) & 0x001F;
            switch_Number(r[0], reg[0]);
            sprintf(buf, "mfhi %s", reg[0]);
            break;
        case 17:
            r[0] = (ir >> 21) & 0x001F;
            switch_Number(r[0], reg[0]);
            sprintf(buf, "mthi %s", reg[0]);
            break;
        case 18:
            r[0] = (ir >> 11) & 0x001F;
            switch_Number(r[0], reg[0]);
            sprintf(buf, "mflo %s", reg[0]);
            break;
        case 19:
            r[0] = (ir >> 21) & 0x001F;
            switch_Number(r[0], reg[0]);
            sprintf(buf, "mtlo %s", reg[0]);
            break;
        default:
            sprintf(buf, "nop");
            break;
            }

        break;
    case 8:
    r[0] = (ir >> 21) & 0x001F;
    r[1] = (ir >> 16) & 0x001F;

    imm_num = ir & 0x0FFFF;

    if(imm_num & 0x08000){
        imm_num = imm_num|0xFFFF0000;
    }


    switch_Number(r[0], reg[0]);
    switch_Number(r[1], reg[1]);



    sprintf(buf, "addi %s, %s, %04x", reg[0], reg[1], imm_num);
        //addi();
        break;
    case 9:
    r[0] = (ir >> 21) & 0x001F;
    r[1] = (ir >> 16) & 0x001F;

    imm_num = ir & 0x0FFFF;


    switch_Number(r[0], reg[0]);
    switch_Number(r[1], reg[1]);



    sprintf(buf, "addiu %s, %s, %04x", reg[0], reg[1], imm_num);
    //addiu();
        break;
    case 10:
    r[0] = (ir >> 21) & 0x001F;
    r[1] = (ir >> 16) & 0x001F;

    imm_num = ir & 0x0FFFF;

    if(imm_num & 0x08000){
        imm_num = imm_num|0xFFFF0000;
    }


    switch_Number(r[0], reg[0]);
    switch_Number(r[1], reg[1]);



    sprintf(buf, "slt %s, %s, %04x", reg[0], reg[1], imm_num);
    //slti();
        break;
    case 11:
    r[0] = (ir >> 21) & 0x001F;
    r[1] = (ir >> 16) & 0x001F;

    imm_num = ir & 0x0FFFF;

    switch_Number(r[0], reg[0]);
    switch_Number(r[1], reg[1]);

    sprintf(buf, "sltiu %s, %s, %04x", reg[0], reg[1], imm_num);
    //sltiu();
        break;
    case 12:
    r[0] = (ir >> 21) & 0x001F;
    r[1] = (ir >> 16) & 0x001F;

    imm_num = ir & 0x0FFFF;

    if(imm_num & 0x08000){
        imm_num = imm_num|0xFFFF0000;
    }


    switch_Number(r[0], reg[0]);
    switch_Number(r[1], reg[1]);



    sprintf(buf, "andi %s, %s, %04x", reg[0], reg[1], imm_num);
    //andi();
        break;
    case 13:
    r[0] = (ir >> 21) & 0x001F;
    r[1] = (ir >> 16) & 0x001F;

    imm_num = ir & 0x0FFFF;

    if(imm_num & 0x08000){
        imm_num = imm_num|0xFFFF0000;
    }


    switch_Number(r[0], reg[0]);
    switch_Number(r[1], reg[1]);



    sprintf(buf, "ori %s, %s, %04x", reg[0], reg[1], imm_num);
    //ori();
        break;
    case 14:
    r[0] = (ir >> 21) & 0x001F;
    r[1] = (ir >> 16) & 0x001F;

    imm_num = ir & 0x0FFFF;

    if(imm_num & 0x08000){
        imm_num = imm_num|0xFFFF0000;
    }


    switch_Number(r[0], reg[0]);
    switch_Number(r[1], reg[1]);



    sprintf(buf, "xori %s, %s, %04x", reg[0], reg[1], imm_num);
        xori();
        break;
    case 35:
        r[0] = (ir >> 21) & 0x001F;
        r[1] = (ir >> 16) & 0x001F;
        imm_num = ir & 0xFFFF;
        switch_Number(r[0], reg[0]);
        switch_Number(r[1], reg[1]);
        sprintf(buf, "lw %s, %d(%s)", reg[0], imm_num, reg[1]);
        //lw(mem);
        break;
    case 43:
        r[0] = (ir >> 21) & 0x001F;
        r[1] = (ir >> 16) & 0x001F;
        imm_num = ir & 0xFFFF;
        switch_Number(r[0], reg[0]);
        switch_Number(r[1], reg[1]);
        sprintf(buf, "sw %s, %d(%s)", reg[0], imm_num, reg[1]);
        //sw(mem);
        break;
    case 2:
        imm_num = ir & 0x003FFFFFF;
        imm_num <<= 2;
        temp = sign_list;
        while (NULL != temp) {
            if ((unsigned)imm_num == temp->address) {
                strcpy(sign, temp->sign);
                sprintf(buf, "j %s", sign);
                break;
            }
            temp = temp->next;
        }
        //jump(mem);
        break;
    case 3:
        imm_num = ir & 0x003FFFFFF;
        imm_num <<= 2;
        temp = sign_list;
        while (NULL != temp) {
            if (imm_num == temp->address) {
                strcpy(sign, temp->sign);
                sprintf(buf, "jal %s", sign);
                break;
            }
            temp = temp->next;
        }
        //jump(mem);
        break;
    case 4:
        r[0] = (ir >> 21) & 0x001F;
        r[1] = (ir >> 16) & 0x001F;

        imm_num = ir & 0x0FFFF;

        if(imm_num & 0x08000){
            imm_num = imm_num|0xFFFF0000;
        }


        imm_num <<= 2;

        switch_Number(r[0], reg[0]);
        switch_Number(r[1], reg[1]);
        temp = sign_list;

        while (1) {
            if(temp == NULL){
                return;
            }


            if (imm_num + cur_address + 4 == temp->address) {
                strcpy(sign, temp->sign);
                break;
            }
            temp = temp->next;
        }


        sprintf(buf, "beq %s, %s, %s", reg[0], reg[1], sign);

        //qDebug() <<"here";

        break;
    case 5:
        r[0] = (ir >> 21) & 0x001F;
        r[1] = (ir >> 16) & 0x001F;

        imm_num = ir & 0x0FFFF;

        if(imm_num & 0x08000){
            imm_num = imm_num|0xFFFF0000;
        }


        imm_num <<= 2;

        switch_Number(r[0], reg[0]);
        switch_Number(r[1], reg[1]);
        temp = sign_list;

        while (1) {
            if(temp == NULL){
                return;
            }


            if (imm_num + cur_address + 4 == temp->address) {
                strcpy(sign, temp->sign);
                break;
            }
            temp = temp->next;
        }


        sprintf(buf, "bne %s, %s, %s", reg[0], reg[1], sign);

        //qDebug() <<"here";

        break;
    default:
        sprintf(buf, "nop");
        break;
    }
    return;

}

unsigned int assembler::switch_Register(char* temp)
{
    unsigned int result = 0;

    if ('0' <= temp[2] && '9' >= temp[2]) {
        result = temp[2] - '0';
        switch (temp[1]) {
        case 'v':
            result += 2;
            break;
        case 'a':
            result += 4;
            break;
        case 't':
            if (result >= 8) result += 8;
            result += 8;
            break;
        case 's':
            result += 16;
            break;
        case 'k':
            result += 26;
            break;
        default:
            break;
        }
    }
    else {
        if (!strcmp(temp, "$zero")) result = 0;
        if (!strcmp(temp, "$at")) result = 1;
        if (!strcmp(temp, "$gp")) result = 28;
        if (!strcmp(temp, "$sp")) result = 29;
        if (!strcmp(temp, "$fp")) result = 30;
        if (!strcmp(temp, "$ra")) result = 31;
    }
    return result;

}

void assembler::switch_Number(unsigned int input, char* output)
{
    switch (input) {
    case 0:
        strcpy(output, "$zero");
        break;
    case 1:
        strcpy(output, "$at");
        break;
    case 2:
        strcpy(output, "$v0");
        break;
    case 3:
        strcpy(output, "$v1");
        break;
    case 4:
        strcpy(output, "$a0");
        break;
    case 5:
        strcpy(output, "$a1");
        break;
    case 6:
        strcpy(output, "$a2");
        break;
    case 7:
        strcpy(output, "$a3");
        break;
    case 24:
        strcpy(output, "$t8");
        break;
    case 25:
        strcpy(output, "$t9");
        break;
    case 26:
        strcpy(output, "$k0");
        break;
    case 27:
        strcpy(output, "$k1");
        break;
    case 28:
        strcpy(output, "$gp");
        break;
    case 29:
        strcpy(output, "$sp");
        break;
    case 30:
        strcpy(output, "$fp");
        break;
    case 31:
        strcpy(output, "$ra");
        break;
    default:
        break;
    }

    if (input >= 8 && input <= 15) {
        output[0] = '$';
        output[1] = 't';
        output[2] = '0' + input - 8;
        output[3] = '\0';
    }

    if (input >= 16 && input <= 23) {
        output[0] = '$';
        output[1] = 's';
        output[2] = '0' + input - 16;
        output[3] = '\0';
    }
}

void assembler::numToString(unsigned int result, char* output)
{
    unsigned int temp;
    int i = 0;
    temp = result;


    output[32] = '\0';
    while (temp) {
        output[31 - i] = temp % 2 + '0';
        temp /= 2;
        i++;
    }

    while (i != 32) {
        output[31 - i] = '0';
        i++;
    }

    return;
}

int assembler::cal(char* temp)
{
    int a = 0, i = 0, x = 0, j = 0, u = 0, s[100], zi = 0, b = 0;
    char c, f[100];
    for (i = 0; ; i++) {
        for (x = 0; (c = temp[j]) >= '0'&&c <= '9'; x++) {
            u = c - '0';
            if (x == 0)
                zi = u;
            else  zi = zi * 10 + u;
            j++;
        }
        s[a] = zi;
        f[a++] = c;

        if (c == '=')
            break;
        j++;
    }

    for (a = 0; a <= i; a++) {
        x = a + 1;
        if ((f[a] == '*' || f[a] == '/') && b == 0) { u = a; b = 1; }
        if (f[a] == '+' || f[a] == '-')  b = 0;
        if (f[a] == '*') { s[u] = s[u] * s[x];  f[a] = '+'; s[x] = 0; }
        if (f[a] == '/') { s[u] = s[u] / s[x];  f[a] = '+'; s[x] = 0; }
    }
    for (a = 0; a <= i; a++) {
        x = a + 1;
        if (f[a] == '+') { s[0] = s[0] + s[x]; }
        if (f[a] == '-') { s[0] = s[0] - s[x]; }
    }
    return s[0];
}

void assembler::exec()
{
    ir = (memory[pc]<<24)+(memory[pc+1]<<16)+(memory[pc+2]<<8)+(memory[pc+3]);
    pc += 4;

    unsigned int inst = (ir >> 26);


    switch (inst) {
    case 0:
        inst = ir&0x003F;
        switch(inst){
        case 0:
            sll();
            break;
        case 2:
            srl();
            break;
        case 3:
            sra();
            break;
        case 4:
            sllv();
            break;
        case 6:
            srlv();
            break;
        case 7:
            srav();
            break;
        case 8:
            jr();
            break;
        case 16:
            mfhi();
            break;
        case 17:
            mthi();
            break;
        case 18:
            mflo();
            break;
        case 19:
            mtlo();
            break;
        case 32:
            add();
            break;
        case 33:
            addu();
            break;
        case 34:
            sub();
            break;
        case 35:
            subu();
            break;
        case 42:
            slt();
            break;
        case 43:
            sltu();
            break;
        case 37:
            orx();
            break;
        case 38:
            xorx();
            break;
        case 39:
            nor();
            break;
        }
        break;
    case 8:
        addi();
        break;
    case 9:
        addiu();
        break;
    case 10:
        slti();
        break;
    case 11:
        sltiu();
        break;
    case 12:
        andi();
        break;
    case 13:
        ori();
        break;
    case 14:
        xori();
        break;
    case 35:
        lw();
        break;
    case 4:
        beq();
        break;
    case 5:
        bne();
        break;
    case 43:
        sw();
        break;
    case 2:
        jump();
        break;
    case 3:
        jumpal();
        break;
    default:
        break;
    }

}

void assembler::add()
{
    int r[3];

    r[0] = (ir >> 21) & 0x001F;
    r[1] = (ir >> 16) & 0x001F;
    r[2] = (ir >> 11) & 0x001F;


    reg[r[2]] = reg[r[0]] + reg[r[1]];

    return;
}

void assembler::addu()
{
    int r[3];

    r[0] = (ir >> 21) & 0x001F;
    r[1] = (ir >> 16) & 0x001F;
    r[2] = (ir >> 11) & 0x001F;


    reg[r[2]] = reg[r[0]] + reg[r[1]];

    return;
}

void assembler::sw()
{
    int r[2], imm_num;

    r[0] = (ir >> 21) & 0x001F;
    r[1] = (ir >> 16) & 0x001F;

    imm_num = ir & 0xFFFF;

    memory[reg[r[1]] + imm_num] = reg[r[0]];

    return;
}

void assembler::jump()
{
    int imm_num;

    imm_num = ir & 0x003FFFF;

    imm_num <<= 2;

    pc = imm_num;
}

void assembler::jumpal(){
    int imm_num;

    imm_num = ir & 0x003FFFF;

    imm_num <<= 2;


    reg[31] = pc;
    pc = imm_num;
}

void assembler::sub()
{
    int r[3];

    r[0] = (ir >> 21) & 0x001F;
    r[1] = (ir >> 16) & 0x001F;
    r[2] = (ir >> 11) & 0x001F;

    reg[r[2]] = reg[r[0]] - reg[r[1]];

    return;
}

void assembler::subu()
{
    int r[3];

    r[0] = (ir >> 21) & 0x001F;
    r[1] = (ir >> 16) & 0x001F;
    r[2] = (ir >> 11) & 0x001F;

    reg[r[2]] = reg[r[0]] - reg[r[1]];

    return;
}

void assembler::lw()
{
    int r[2], imm_num;

    r[0] = (ir >> 21) & 0x001F;
    r[1] = (ir >> 16) & 0x001F;

    imm_num = ir & 0xFFFF;

    reg[r[0]] = memory[reg[r[1]] + imm_num];

    return;
}

void assembler::slt()
{
    int r[3];

    r[0] = (ir >> 21) & 0x001F;
    r[1] = (ir >> 16) & 0x001F;
    r[2] = (ir >> 11) & 0x001F;

    if (reg[r[0]] <  reg[r[1]])
        reg[r[2]] = 1;
    else
        reg[r[2]] = 0;

    return;
}

void assembler::sltu()
{
    int r[3];

    r[0] = (ir >> 21) & 0x001F;
    r[1] = (ir >> 16) & 0x001F;
    r[2] = (ir >> 11) & 0x001F;

    if (reg[r[0]] <  reg[r[1]])
        reg[r[2]] = 1;
    else
        reg[r[2]] = 0;

    return;
}

void assembler::beq()
{
     int r[2],imm_num;

     r[0] = (ir>>21)&0x001F;
     r[1] = (ir>>16)&0x001F;

     imm_num =ir&0xFFFF;


     if (imm_num&0x008000) {
         imm_num = imm_num | 0xFFFF0000;
     }

     if(reg[r[1]] == reg[r[0]])
         pc += imm_num<<2;

     return;
}

void assembler::addi(){
    int r[2],imm_num;

    r[0] = (ir>>21)&0x001F;
    r[1] = (ir>>16)&0x001F;


    imm_num =ir&0xFFFF;

    reg[r[0]] = reg[r[1]] + imm_num;

    return;

}

void assembler::addiu(){
    int r[2],imm_num;

    r[0] = (ir>>21)&0x001F;
    r[1] = (ir>>16)&0x001F;

    imm_num =ir&0xFFFF;

    reg[r[0]] = reg[r[1]] + imm_num;

    return;

}

void assembler::slti(){
    int r[2],imm_num;

    r[0] = (ir>>21)&0x001F;
    r[1] = (ir>>16)&0x001F;

    imm_num =ir&0xFFFF;

    if (reg[r[1]] <  imm_num)
        reg[r[0]] = 1;
    else
        reg[r[0]] = 0;

    return;

}

void assembler::sltiu(){
    int r[2],imm_num;

    r[0] = (ir>>21)&0x001F;
    r[1] = (ir>>16)&0x001F;

    imm_num =ir&0xFFFF;

    if (reg[r[1]] <  imm_num)
        reg[r[0]] = 1;
    else
        reg[r[0]] = 0;

    return;

}

void assembler::andi(){
    int r[2],imm_num;

    r[0] = (ir>>21)&0x001F;
    r[1] = (ir>>16)&0x001F;

    imm_num =ir&0xFFFF;

    reg[r[0]] = reg[r[1]] & imm_num;

    return;
}

void assembler::ori(){
    int r[2],imm_num;

    r[0] = (ir>>21)&0x001F;
    r[1] = (ir>>16)&0x001F;

    imm_num =ir&0xFFFF;

    reg[r[0]] = reg[r[1]] | imm_num;

    return;
}

void assembler::xori(){
    int r[2],imm_num;

    r[0] = (ir>>21)&0x001F;
    r[1] = (ir>>16)&0x001F;

    imm_num =ir&0xFFFF;

    reg[r[0]] = reg[r[1]] ^ imm_num;

    return;
}

void assembler::orx(){
    int r[3];

    r[0] = (ir>>21)&0x001F;
    r[1] = (ir>>16)&0x001F;
    r[2] = (ir >> 11) & 0x001F;

    reg[r[2]] = reg[r[0]] | reg[r[1]];

    return;
}

void assembler::xorx(){
    int r[3];

    r[0] = (ir>>21)&0x001F;
    r[1] = (ir>>16)&0x001F;
    r[2] = (ir >> 11) & 0x001F;

    reg[r[0]] = reg[r[1]] ^ reg[r[0]];

    return;
}

void assembler::nor(){
    int r[3];

    r[0] = (ir>>21)&0x001F;
    r[1] = (ir>>16)&0x001F;
    r[2] = (ir >> 11) & 0x001F;

    reg[r[0]] = ~(reg[r[1]] | reg[r[0]]);

    return;
}


void assembler::mthi(){

}

void assembler::mtlo(){

}

void assembler::mflo(){

}

void assembler::mfhi(){

}

void assembler::bne(){
    int r[2],imm_num;

    r[0] = (ir>>21)&0x001F;
    r[1] = (ir>>16)&0x001F;

    imm_num =ir&0xFFFF;


    if (imm_num&0x008000) {
        imm_num = imm_num | 0xFFFF0000;
    }

    if(reg[r[1]] != reg[r[0]])
        pc += imm_num<<2;

    return;
}

void assembler::jr(){
    pc = reg[31];
    return;
}

void assembler::sllv(){
    int r[3];

    r[0] = (ir>>21)&0x001F;
    r[1] = (ir>>16)&0x001F;
    r[2] = (ir >> 11) & 0x001F;

    reg[r[2]]=reg[r[1]]<<reg[r[0]];

    return;
}

void assembler::srlv(){
    int r[3];

    r[0] = (ir>>21)&0x001F;
    r[1] = (ir>>16)&0x001F;
    r[2] = (ir >> 11) & 0x001F;

    reg[r[2]]=reg[r[1]]>>reg[r[0]];

    return;

}

void assembler::srav(){
    int r[3];

    r[0] = (ir>>21)&0x001F;
    r[1] = (ir>>16)&0x001F;
    r[2] = (ir >> 11) & 0x001F;

    reg[r[2]]=((int )reg[r[1]])>>reg[r[0]];

    return;
}

void assembler::sll(){
    int r[2],imm_num;

    r[0] = (ir>>16)&0x001F;
    r[1] = (ir>>11)&0x001F;

    imm_num =(ir&0x07C0) >> 6;

    reg[r[1]] = reg[r[0]] << imm_num;

    return;

}

void assembler::srl(){
    int r[2],imm_num;

    r[0] = (ir>>16)&0x001F;
    r[1] = (ir>>11)&0x001F;

    imm_num =(ir&0x07C0) >> 6;

    reg[r[1]] = reg[r[0]] >> imm_num;

    return;

}

void assembler::sra(){
    int r[2],imm_num;

    r[0] = (ir>>16)&0x001F;
    r[1] = (ir>>11)&0x001F;

    imm_num =(ir&0x07C0) >> 6;

    reg[r[1]] = ((int )reg[r[0]]) >> imm_num;

    return;
}
