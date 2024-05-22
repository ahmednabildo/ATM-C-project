#include "server/server.h"
data_base accounts[n] = {{.cardHolderName = "ahmednabilahmeddonia" , .primaryAccountNumber = "0123456789123456789" , .cardExpirationDate = "25/06" , .balance = 2000 , .state = RUNNING},
                         {.cardHolderName = "ahmedahmednabilnabil" , .primaryAccountNumber = "0123456789987654321" , .cardExpirationDate = "25/07" , .balance = 3000 , .state = BLOCKED}};
ST_cardData_t C_DATA;
ST_terminalData_t T_DATA;
ST_transaction_t trans[255];
int main()
    {
        setMaxAmount( &T_DATA,  MaxAmount);
        int count = 0;
        uint8_t state = 0;
        while(count < 1)
        {
            getCardHolderName(&C_DATA);
            getCardExpiryDate(&C_DATA);
            getCardPAN(&C_DATA);
            uint8_t x = Card_Confirm(&C_DATA , accounts);
            if(x != -1)
            {
                printf("found\n");
                if(getTransactionDate(&T_DATA) == 1)
                {
                   if(isCardExpired(&C_DATA , &T_DATA) == 1)
                   {
                       getTransactionAmount(&T_DATA);
                       if(isBelowMaxAmount(&T_DATA) == 1)
                       {
                           if(check_the_state(accounts[x]) == 1)
                           {
                               printf("trans accepted\n");
                               accounts[x].balance -= T_DATA.transAmount;
                               state = 1;
                           }
                           else
                           {
                               printf("blocked\n");
                               continue;
                           }

                       }
                       else
                       {
                           printf("exceed_max_amount\n");
                       }
                   }
                   else
                   {
                       printf("card_is_expired\n");
                       continue;
                   }
                }
                else
                {
                    printf("not_valid_data\n");
                    continue;
                }
            }
            else
            {
                printf("notfound\n");
                continue;
            }

            save_trans(&trans[count] , &C_DATA , &T_DATA , accounts[x].balance, state);
            count++;
        }
        for (int i = 0; i < count; ++i)
        {
            printf("name : %s\n" , trans[i].name);
            printf("PAN : %s\n" , trans[i].PAN);
            printf("status : %s\n" , trans[i].trans_status);
            printf("date : %s\n" , trans[i].trans_date);
            printf("new balance : %f\n" , trans[i].new_balance);
        }

    }
