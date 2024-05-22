#include "card.h"
uint8_t getCardHolderName(ST_cardData_t *cardData)
{
    char holder_name[25];
    printf("Enter your name: ");
    scanf(" %s",holder_name);
    if(strlen(holder_name) < 20 || strlen(holder_name) > 24)
    {
        printf("wrong name");
        return 0;
    }
    else
    {
        for(int i = 0 ; i <= strlen(holder_name) ; i++)
        {
            cardData->cardHolderName[i]=holder_name[i];
        }

    }
    return 1;
}
uint8_t getCardExpiryDate(ST_cardData_t *cardData)
{
    char expiry_date[6];
    printf("Enter the card expiry date: ");
    scanf("%s",expiry_date);
    if(strlen(expiry_date)<5 || strlen(expiry_date)>5)
    {
        printf("wrong");
        return 0;
    }
    else
    {
        for(int i=0;i<= strlen(expiry_date);i++)
        {
            cardData->cardExpirationDate[i]=expiry_date[i];
        }
    }
    return 1;
}

uint8_t getCardPAN(ST_cardData_t *cardData)
{
    char PAN_number[20];
    printf("Enter the PAN: ");
    scanf("%s",PAN_number);
    if(strlen(PAN_number)<19 || strlen(PAN_number)>19)
    {
        printf("wrong");
        return 0;
    }
    else
    {
        for(int i=0;i<= strlen(PAN_number);i++)
        {
            cardData->primaryAccountNumber[i]=PAN_number[i];
        }

    }
    return 1;
}

uint8_t Card_Confirm(ST_cardData_t *cardData , data_base database[n])
{
    uint8_t counter = 0;
    uint8_t index = 0;
    uint8_t confirm = 0;
    for(uint8_t i = 0 ; i < n ; i++)
    {
        for(uint8_t j = 0 ; j < 19 ; j++)
        {
            if(database[i].primaryAccountNumber[j] == cardData->primaryAccountNumber[j])
            {
                counter++;
            }
            else
            {
                counter = 0;
                break;
            }
        }
        if(counter == 19)
        {
            counter = 0;
            index = i;
            confirm++;
            for( unsigned long long k = 0 ; k < strlen(cardData->cardHolderName) ; k++)
            {
                if(database[i].cardHolderName[k] == cardData->cardHolderName[k])
                {
                    counter++;
                }
                else
                {
                    counter = 0;
                    break;
                }
            }
            if(counter == strlen(cardData->cardHolderName))
            {
                confirm++;
                counter = 0;
                for( unsigned long long k = 0 ; k < strlen(cardData->cardExpirationDate) ; k++)
                {
                    if(database[i].cardExpirationDate[k] == cardData->cardExpirationDate[k])
                    {
                        counter++;
                    }
                    else
                    {
                        counter = 0;
                        break;
                    }
                }
                if(counter == strlen(cardData->cardExpirationDate))
                {
                    confirm++;
                }
            }

        }
    }

    if(confirm == 3)
    {
        return index;
    }

    return -1;
}