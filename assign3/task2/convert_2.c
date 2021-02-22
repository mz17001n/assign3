#include<stdio.h>
#include<stdlib.h>

//Program to convert a 32-bit Decimal numbers to Binary
//1) Do not change the signature of convert_2, or your task receives zero
//2) No globals allowed.

int getP(int base, int exponent) {
  if (exponent == 0) {
    return 1;
  } else {
    return base * getP(base, exponent-1);
  }
}

char* convert_2(int dec)
{
	//TODO: your implementation
  char* binaryConversion = (char*)malloc(sizeof(char)*42);
  binaryConversion[0] = '0';
  binaryConversion[1] = 'b';
  binaryConversion[41] = '\0';
  int spaces = 2;
  int power = 30;

  if (dec < 0) {
    dec = (-1*dec) - 2147483648;
    binaryConversion[2] = '1';
    for (int i = 37; i >= 0; i--) {
      if (spaces %5 == 0){
        binaryConversion[40-i] = ' ';
      } else if ((dec + (getP(2, power))) <= 0) {
        dec = dec + (getP(2, power));
        binaryConversion[40-i] = '1';
        power -= 1;
      } else {
        binaryConversion[40-i] = '0';
        power -= 1;
      }
      spaces += 1;
    }
  } else {
    binaryConversion[2] = '0';
    for (int i = 37; i >= 0; i--) {
      if (spaces %5 == 0){
        binaryConversion[40-i] = ' ';
      } else if ((dec - (getP(2, power))) >= 0) {
        dec = dec - (getP(2, power));
        binaryConversion[40-i] = '1';
        power -= 1;
      } else {
        binaryConversion[40-i] = '0';
        power -= 1;
      }
      spaces += 1;
    }
  }


  return binaryConversion;
}

int main() {
	int n;
	char * bin;
	printf("Enter the Decimal Number\n");
	scanf("%d",&n);
	bin = convert_2(n);
	printf("The Binary Notation of %d is\t %s \n", n, bin);
	//TODO: do we need to release the memory of bin?
  free(bin);
  bin = NULL;
  return 0;
}