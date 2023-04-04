lab10-1
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
int main ( void ) {
    int pin = 7;printf(”LED blinking by wiringPi\n”);
    if (wiringPiSetup() == -1) {
        printf( ”Setting up problem ... Abort!” );
        exit (1);
    }
    pinMode(pin, OUTPUT); /* set pin=7 to Output mode */
    int i;
    for ( i=0; i<10; i++ ) {
        digitalWrite(pin, 1);    /* LED On  */
        delay(500);
        digitalWrite(pin, 0);    /* LED Off */
        delay(500);
    }
    return 0;
}


lab10-2
#--------------------
# data segment
#--------------------
    .data
    .balign 4
intro:   .asciz  ”LED blinking by wiringPi\n”
errMsg:  .asciz ”Setting up problem ... Abort!\n”
pin:    .int   7
i:      .int   0
duration:.int   500
OUTPUT   = 1    @constant
#--------------------
# text segment
#--------------------
    .text
    .global main
    .extern printf
    .extern wiringPiSetup
    .extern delay
    .extern digitalWrite
    .extern pinMode
    
main:   PUSH    {ip, lr} @push link return register on stack segment
    LDRR0,  =intro
    BL      printf
    BL      wiringPiSetup
    MOV     R1,#-1
    CMP     R0, R1
    BNE     init
    LDR     R0, =errMsg
    BL      printf
    B       done
init:
    LDR     R0, =pin
    LDR     R0, [R0]
    MOV     R1,#OUTPUT
    BL      pinMode
    LDR     R4, =i
    LDR     R4, [R4]
    MOV     R5,#10
forLoop:
    CMP     R4, R5
    BGT     done
    LDR     R0, =pin
    LDR     R0, [R0]
    MOV     R1,#1
    BL      digitalWrite
    LDR     R0, =duration
    LDR     R0, [R0]
    BL      delay
    LDR     R0, =pin
    LDR     R0, [R0]
    MOV     R1,#0
    BL      digitalWrite
    LDR     R0, =duration
    LDR     R0, [R0]
    BL      delay
    ADD     R4,#1
    B       forLoop
done:
    POP     {ip, pc} @pop return address into pc




lab11
#include <stdio.h>
#include <errno.h>
#include <wiringPi.h>
#define BUTTON_PIN 0
// Use GPIO Pin 17 = Pin 0 of wiringPi library
volatile int eventCount = 0;
void myInterrupt(void) {  // called every time an event occurs
    eventCount++; // the event counter
}
int main(void) {
    if (wiringPiSetup()<0)   // check the existence of wiringPi library
    {
        printf (”Cannot setup wiringPi: %s\n”, strerror (errno));
        return 1; // error code = 1
    }
    // set wiringPi Pin 0 to generate an interrupt from 1-0 transition
    // myInterrupt() = my Interrupt Service Routine
    if (wiringPiISR (BUTTON_PIN, INT_EDGE_FALLING, &myInterrupt) < 0) 
    {
        printf (”Cannot setup ISR: %s\n”, strerror (errno));
        return 2; // error code = 2
    }
    // display counter value every second
    while(1) 
    {
        printf(”%d\n”, eventCount);
        eventCount = 0;delay(1000); // wait 1000 milliseconds = 1 second
    }
    return 0;  // error code = 0 (No Error)
}