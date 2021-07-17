#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <stdlib.h>
#include <string.h>

char file0[50] = "/home/chung/workspace/HW/add-nbo/";
char file1[50] = "/home/chung/workspace/HW/add-nbo/";
char temp[50];

FILE* fp0;
FILE* fp1;
uint8_t buffer[20];
uint8_t add_value[20];

uint16_t my_ntohs(uint16_t a){
    return (a<<8)|(a>>8);
}

uint16_t write_0x1234(uint8_t a, uint8_t b) {
    uint8_t network_buffer[] = { a, b };
    uint16_t* p = reinterpret_cast<uint16_t*>(network_buffer);
    uint16_t n = my_ntohs(*p); // TODO
    return n;
}

void input_filename(char* arr[]){
    strcat(file0,arr[1]);
    fp0 = fopen(file0,"r");
    fread(buffer,8,1,fp0);
    add_value[0] = buffer[2];
    add_value[1] = buffer[3];

    strcat(file1,arr[2]);
    fp1 = fopen(file1,"r");
    fread(buffer,8,1,fp1);
    add_value[2] = buffer[2];
    add_value[3] = buffer[3];

    fclose(fp0);
    fclose(fp1);

}


int main(int argc, char* argv[]) {

    input_filename(argv);
    uint16_t add0 = write_0x1234(add_value[0],add_value[1]);
    uint16_t add1 = write_0x1234(add_value[2],add_value[3]);
    uint32_t result = add0 + add1;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x))\n",add0,add0,add1,add1,result,result);
}
