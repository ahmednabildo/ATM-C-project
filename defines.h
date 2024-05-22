#include <string.h>
#include <stdio.h>

typedef  char uint8_t;
typedef int uint32_t;
#define n 10
#define MaxAmount 1000000

typedef struct ST_cardData_t
{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef struct ST_terminalData_t
{
    float transAmount;
    float maxTransAmount;
    uint8_t transactionDate[6];
}ST_terminalData_t;
typedef enum state
{
    RUNNING, BLOCKED
}state_t;
typedef struct data_base
{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];
    float balance;
    state_t state;
}data_base;


typedef struct ST_transaction
{
    uint8_t name[22];
    uint8_t PAN[20];
    uint8_t trans_date[6];
    uint8_t trans_status[10];
    float new_balance;
}ST_transaction_t;
