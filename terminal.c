#include "terminal.h"

uint8_t getTransactionDate(ST_terminalData_t *termData)
{
    char Transaction_Date[6];
    printf("Enter the trans date: ");
    scanf("%s",Transaction_Date);
    if(strlen(Transaction_Date)!= 5)
    {
        return 0;
    }
    else
    {
        for(int i = 0;i <= strlen(Transaction_Date);i++)
        {
            termData->transactionDate[i]=Transaction_Date[i];
        }
    }
    return 1;
}


uint8_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData)
{
    int Transaction_Date=termData->transactionDate[0]*10+termData->transactionDate[1]+termData->transactionDate[3]*10*30+termData->transactionDate[4]*30 ;
    int expiry_date=cardData->cardExpirationDate[0]*10+cardData->cardExpirationDate[1]+cardData->cardExpirationDate[3]*10*30+cardData->cardExpirationDate[4]*30;

    if(Transaction_Date<=expiry_date)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}


uint8_t getTransactionAmount(ST_terminalData_t *termData)
{
    float Transaction_Amount;
    printf("Enter the transaction amount: ");
    scanf("%f",&Transaction_Amount);
    if(Transaction_Amount<=0)
    {
        return 0;
    }
    else
    {
        termData->transAmount=Transaction_Amount;
        return 1;
    }
}


uint8_t isBelowMaxAmount(ST_terminalData_t *termData)
{
    if(termData->transAmount > termData->maxTransAmount)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


uint8_t setMaxAmount(ST_terminalData_t *termData, float maxAmount)
{
    if(maxAmount<=0)
    {
        return 0;
    }
    else
    {
        termData->maxTransAmount=maxAmount;
        return 1;
    }
}

