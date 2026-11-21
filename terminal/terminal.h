#include "card/card.h"


uint8_t getTransactionDate(ST_terminalData_t *termData);
uint8_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData);
uint8_t getTransactionAmount(ST_terminalData_t *termData);
uint8_t isBelowMaxAmount(ST_terminalData_t *termData);
uint8_t setMaxAmount(ST_terminalData_t *termData, float maxAmount);
