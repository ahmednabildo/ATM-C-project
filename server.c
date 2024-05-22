#include "server.h"

uint8_t check_the_state(data_base data_base_)
{
    if(data_base_.state == RUNNING)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void save_trans(ST_transaction_t *trans , ST_cardData_t *card , ST_terminalData_t *terminal , float new_balance , uint8_t status)
{
    uint8_t run[10] = "accepted";
    uint8_t block[10] = "not_accept";

    trans->new_balance = new_balance;

    for (int i = 0; i < strlen(card->cardHolderName); ++i)
    {
        trans->name[i] = card->cardHolderName[i];
    }
    for (int i = 0; i < strlen(card->primaryAccountNumber); ++i)
    {
        trans->PAN[i] = card->primaryAccountNumber[i];
    }
    for (int i = 0; i < strlen(terminal->transactionDate); ++i)
    {
        trans->trans_date[i] = terminal->transactionDate[i];
    }
    if(status == 1)
    {
        for (int i = 0; i < 10; ++i)
        {
            trans->trans_status[i] = run[i];
        }
    }
    else
    {
        for (int i = 0; i < 10; ++i)
        {
            trans->trans_status[i] = block[i];
        }
    }
}