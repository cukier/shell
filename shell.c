/*
 * shell.c
 *
 *  Created on: 26/09/2014
 *      Author: cuki
 */

#include <18F452.h>

#FUSES H4

#use delay(crystal=8MHz, clock=32MHz)
#use rs232(xmit=PIN_C6, rcv=PIN_C7, baud=9600)

#include<STRING.H>

#define b_size 128

short enter;

int cont;
int input;

int str[b_size] = "";
int quit[5] = "quit";

#INT_RDA
void isr_rda() {
	clear_interrupt(INT_RDA);
	input = getc();

	if (input == 0x0D) {
		str[cont] = "\0";
		cont = 0;
		enter = TRUE;
		printf("\n\r");
	} else {
		str[cont++] = input;
		str[cont] = "\0";
		printf("%c", input);
	}
}

int main(void) {

	enable_interrupts(INT_RDA);
	enable_interrupts(GLOBAL);

	printf("Hello\n\r");

	while (strcmp(str, quit)) {
		printf("$\:");
		while (!enter)
			;
		printf("%s\n\r", str);
		enter = FALSE;
	}

	printf("Good bye!\n\r");

	sleep();

	return 0;
}
