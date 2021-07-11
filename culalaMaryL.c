/***********************************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or otherwise plagiarized the work of other students and/or persons.
 
CULALA, MARY ERIKA L. , DLSU ID# 12030783
*************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* AGENDA
 
 [/] - create terminal for xcode file                       [/] - generation of trends
 [/] - generation of daisy mae trends                       [/] - nTotal (Earnings and Expenses)
 [/] - Week LOOP                                            [/] - Days LOOP
 [/] - COndition when u buy too much from Daisy Mae         [/] - condition to when turnips have gone bad
 [/] - loop when 0 earnings
 
 [/] - loop even though there is checker (n spent < ntotal) in the beginning
 [/] - restarts if error in the beginning (negative balance)

 [/] - days switch                                          [/] - add earnings to Total
 [/] - dialogue box to earnings                             [/] - fail status
 [/] - congrats status                                      [/] - one million
 [/] - instructions                                         [/] - space on NO
 [/] - amount per 1 stack                                   [/] - no negative Turnips
 [/] - restore if wrong input                               [/] - no new trend on wrong inputs
 
 */

/* NOTE: All printf here has \n for terminal. Remove if needed! */



void daysGenerate(int n)
{
    switch (n)
    {
        case 1:
            printf("SUNDAY\n");
            break;
        case 2:
            printf("MONDAY\n");
            break;
        case 3:
            printf("TUESDAY\n");
            break;
        case 4:
            printf("WEDNESDAY\n");
            break;
        case 5:
            printf("THURSDAY\n");
            break;
        case 6:
            printf("FRIDAY\n");
            break;
        case 7:
            printf("SATURDAY\n");
            break;
       case 8:
            printf("\n");
            break;
    }
}

/* --------------------------------------------------------------- TURNIPS COUNTER --------------------------------! TURNIPS COUNTER !----*/


                                                                /*  [ 1 ] - Counts turnips at the start before the day loop and stores in nTurnips  */
int countTurnips(int nSunday, int nSpent)                       // nspent is nExpense in int main()
{
    int nTurnips;
    
    nTurnips = nSpent / nSunday;
    return nTurnips;
}

int displayTurnips(int *nTurnips, int nQuant)                   /*  [ 2 ] - DISPLAY turnips and stack every day in day loop    */
{                                                               /*      and return newest nTurnips count at the start of each day     */
    int nStack;
    *nTurnips = *nTurnips - nQuant * 10 ;
    nStack = *nTurnips / 10;
    
    printf("Turnips: %d | Stack: %d\n", *nTurnips, nStack);
    return *nTurnips;
  
}

/* ---------------------------- DAISY MAE TRANSACTION SUNDAY --------------------------! SUNDAY TRANSACTION !----*/


int daisyMae()                                                                  // RANDOM PRICE GENERATION OF DAISY MAE
{
    int nLower = 90;
    int nUpper = 110;
    int nCount = 1;
    int nNum1 = 1;
                                                                                    
    
    for (int i = 0; i < nCount; i++)
    {
        nNum1 = (rand() % (nUpper - nLower + 1)) + nLower;
    }
    return nNum1;
}


int computeTurnipBUY( int nSunday, int nMany, int *nExp)      /* This function computes the expenses from buying a turnip from Daisy Mae*/
{
    
    *nExp = nMany * nSunday * 10;              // multiplied by 10 because the buying price is per turnips not per stack
    return *nExp;
    
}



int daisySUNDAY(int nSunday)                /* SUNDAY TRANSACTION WITH DAISY MAE DIALOGUE and Expense return */
{
    int nMany;
    int nExpense = 0;
    
    printf("\tDaisy Mae is selling a turnip for %d bells [ %d for 1 Stack ]\n", nSunday, nSunday * 10);
    printf("\tHow many stacks would you like to buy? ");
    scanf("%d", &nMany);
    fflush(stdin);
    printf("\n");
    
    if (nMany >= 0)
        printf("\t ➤ You bought %d stack of turnips for %d\n", nMany,  computeTurnipBUY(nSunday, nMany, &nExpense)); // This computes expenses every sunday
    else
        nExpense = nMany;        // returns the number of turnips bought instead (negative number)
    return nExpense;
   
    
}

/* --------------------------- MONEY COUNTER ----------------------------------------------------! TRENDS START !---*/


int countBells(int nExpense, int *nTotal, int nEarnings)      /* This function counts the total bells (your money) */
{
    int nBells;
    
    nBells = (*nTotal - nExpense) + nEarnings;
    printf("\tCurrent Bells: %d\n", nBells);
    
    *nTotal = nBells;
    
    return *nTotal;
    
}

/* -------------------------- SPACE FOR TRENDS ----------------------------------------------------! TRENDS START !---*/

/* Reference for random generator: https://www.includehelp.com/c-programs/generate-random-numbers-within-a-range.aspx. I am not really familiar with rand() that's why I looked for randomizer that could work on ranges */



int averageTrend(int nSunday)
{
   int nLower = 80;
   int nUpper = 1.05 * nSunday;
   int nCount = 1;
   int nNum1 = 1;
                                                                    /* <----- AVERAGE TREND ------> */
   for (int i = 0; i < nCount; i++)
   {
       nNum1 = (rand() % (nUpper - nLower + 1)) + nLower;
   }
    
    return nNum1;
}

int awesomeTrend(int nSunday)
{
   int nLower = nSunday;
   int nUpper = 4 * nSunday;
   int nCount = 1;
   int nNum1 = 1;
                                                                    /* <----- AWESOME TREND ------> */
   for (int i = 0; i < nCount; i++)
   {
       nNum1 = (rand() % (nUpper - nLower + 1)) + nLower;
   }
    return nNum1;
}

int badTrend(int nSunday)
{
   int nLower = 20;
   int nUpper = nSunday;
   int nCount = 1;
   int nNum1 = 1;
                                                                    /* <----- BAD TREND ------> */
   for (int i = 0; i < nCount; i++)
   {
       nNum1 = (rand() % (nUpper - nLower + 1)) + nLower;
   }
    return nNum1;
}

int generateTrend(int nSunday)                                      /* <----- TREND GENERATOR ----> */
{
   
   
   int nLower1 = 1;
   int nUpper1 = 3;
   int nCount1 = 1;
   int nNum = 0;
   int nTrend = 0;
    
   
   for (int i = 0; i < nCount1; i++)
   {
           nNum = (rand() % (nUpper1 - nLower1 + 1)) + nLower1;
   }
   

   switch(nNum) {
   
       case 1:
           nTrend = averageTrend(nSunday);
           break;
       
       case 2:
           nTrend = awesomeTrend(nSunday);
           break;
          
       case 3:
           nTrend = badTrend(nSunday);                 /* WITH BREAKS BECAUSE IF NONE, THE FUNCTION WILL BE CALLED TWICE */
           break;
           
       }
    return nTrend;
}

/* ---------------------------- SPACE FOR TRENDS --------------------------------------------------! TRENDS END !----*/


 
int main()
{
    srand((unsigned)time(0)); // so that the numbers generated each run will be different.
    
    
    char cAns;
    int nExpense = 0;
    int nTotal = 5000;
    int nSunday = 0;
    int nWeek = 1, nDay = 1;
    int nTurnips = 0;
    /* break */
    
    int nEarnings = 0;
    int nQuant = 0;
    int nAns;
    int nDailyPrice = 0;
    int nMark = 0, nMark2 = 0;
    
    printf("\tINSTRUCTION: You can only buy turnips by 10 on Sundays.\n");
    printf("\n");
    printf("\tCurrent bells: %d\n", nTotal);

    printf("\tDaisy Mae is selling turnips would you like to buy? ( Click any keys if YES, type 0 if NO) ");
    scanf("%c", &cAns);
    
    if (cAns != '0')
    {
       while ( nWeek < 21 && nTotal >= 0 && nTotal < 1000000 )
       {
        
           
           nTurnips = 0;                                                // Initialize turnips count every week
           
           printf("\n");
           printf("\n");
           printf("\n");
           
           printf("\tWeek#%d | ", nWeek);                        /* [ Week # ] adds up every week */
           daysGenerate(nDay);                                  /* [ Day ] generate days depending on nDay value */
           nDay += 1;                                            /* Adds a day to enter Day Loop bcs day loop > 1 */

           printf("\n");
           countBells(nExpense, &nTotal, nEarnings);   /*  every week nExpense & nEarnings starts to 0 (from end bracket) */
                                                                       /*   so the computation won't double */
           printf("\n");
           printf("\n");
           
           if (nMark2 == 0)                                         // To avoid generation of new trend if nExpense > nTotal / neg input
               nSunday = daisyMae();                                /* DAISY MAE RANDOM PRICE */
            
           nMark2 = 0;                                             // initialize mark again to generate new trend after Mark2 == 1.
           
            if ( nTotal >= nSunday * 10)  // if money can buy turnips, enter this condition
            {
           
               nExpense = daisySUNDAY(nSunday);              // shows daisy mae selling turnip dialogue
            
               
                if (nExpense <= nTotal && nExpense >= 0)  // for negative when u buy too much from daisy mae // this is here because the first commands in the condition before this has to appear at first part of the game. will not enter day loop / or when input is negative from DaisyMae() [nExpense is technically nMany (number of turnips bought)]
                {
                   printf("\n");
                   printf("\n");
                   printf("\t\t\t\t\t\t\t\t-------------------------------------------------------------------------------   \n");
                   printf("\n");
            
                  
                    nTurnips = countTurnips(nSunday, nExpense);  // to display turnips on day 1
                   
                       while (nDay > 1 && nDay <= 8  && nTurnips >= 0  && nTotal < 1000000)
                       {
                           /* ------------- WILL NOT SHOW ON SPACER DAY (8TH) --------------*/
                           
                           if (nWeek <= 20 && nDay != 8 )
                           {
                               printf("\tWeek#%d | ", nWeek);
                               nQuant = 0;               // initialize everyday
                               displayTurnips(&nTurnips, nQuant);
                               
                               printf("\n");
                               
                               nEarnings = 0;           // initialize so that when showing bells it will not double nEarnings in computation
                               countBells(nExpense, &nTotal, nEarnings); // This updates the nTotal every transaction
                               nExpense = 0;            // initialize
                               
                               printf("\t");                              // to indent daysGenerate function
                               daysGenerate(nDay);
                               printf("\n");
                               
                               if (nMark == 0)                          // to stop generating new price if turnips sold > actual turnips
                                    nDailyPrice = generateTrend(nSunday);
                                    
                               nMark = 0;                  // initializes nMark again so that it will generate new trends after mark == 1
                            
                               printf("\tSunday Price: %d\n", nSunday);
                               printf("\tNook's Cranny wants to buy a turnip for %d [%d for 1 stack]\n", nDailyPrice, nDailyPrice * 10);
                            
                               if (nTurnips > 0 && nDay != 8)  // to not show up on 0 turnips days
                                {
                                       
                                   printf("\tWould you like to sell? Any digit - YES / 0 - NO ");
                                   scanf("%d", &nAns);
                                   fflush(stdin);   // ignores other irrelevant inputs. for digits only
                                   
                                    if (nAns != 0)   // just in case users input any numbers aside from 0.
                                    {
                                        printf("\tHow many stack of turnips? ");
                                        scanf("%d", &nQuant);
                                        fflush(stdin);
                                        nEarnings = nQuant * nDailyPrice * 10;
                                    }
                                }
                                
                              
                               nTurnips = nTurnips - nQuant * 10;  //counts turnips at the end of the day. Makes sure days will not add if turnip count is negative
                               nTotal = (nTotal - nExpense) + nEarnings; // counts total at the end of each day.
                               
                               printf("\n\t-----------------------\n\n");
                               
                            /* ----------------- END --------------*/
                               
                           } //nDay != 8
                            else if (nWeek < 20 && nTurnips >= 0 && nDay == 8)                // 8th Day spacer
                               printf("\t%d Turnips have gone bad", nTurnips);
                           
                         
                            if ( nTurnips < 0 && nQuant > 0)                      //repeats selling if sold turnips > actual turnips
                            {
                               nTurnips = nTurnips + nQuant * 10;   // restore turnip count to positive
                               nDay -= 1;
                               nTotal -= nEarnings;       // Minus the earnings because player has already been asked how many to sell.
                               nMark = 1;                 // stops generation of new Daily trend
                               nDailyPrice = nDailyPrice;
                               printf("\n\t [WARNING!] You inputted more than what you have! Try again!\n\n\n");
                            }
                           if (nQuant < 0)
                           {
                               nMark = 1;
                               nTurnips += nQuant * 10;  // (negative nQuant)
                               nDay -= 1;
                               nTotal -= nEarnings;
                               printf("\t [WARNING!] Negative Turnips Input. Try again!\n\n");
                           }
                           
                           if (nWeek == 20 && nDay == 8 && nTotal < 1000000)          // failed message!!
                           {
                                printf("\tCurrent Bells: %d\n", nTotal);
                                printf("\tYou failed to reach 1 million within 20 weeks. Try again!");
                           }
                          
                           
                           nDay += 1;               // DAY CYCLE
                           
                       }  // end for day loop
                          
                } // if total > 0
                
               else if (nExpense > nTotal)     //nMany becomes nExpense
               {
                    nMark2 = 1;
                    nTotal = nTotal;     // restore current bells amount
                    printf("\n\n\t [ WARNING!] You do not have enough bells. Try again!\n");
                    nWeek = nWeek - 1;  // because nWeek is initialized = 1, it has to minus 1.
               }
                else if (nExpense < 0)   // repeats transaction for neg input.
                {
                    nTotal = nTotal;
                    nWeek -= 1;
                    nMark2 = 1;        // prevent generation of new trend
                    printf("\t [WARNING!] Negative Input! Try again!");
                }
                
            } // total > nSunday
                else if ( nTotal < nSunday * 10)           // program stops
               {
                printf("\tNo Enough Bells to buy from Daisy Mae\n");
                printf("\tTurnips cost: %d\n", nSunday);
                nTotal = 0;
                printf("\n");
               }
                
                nWeek += 1;  // WEEK CYCLE
                nDay = 1;
                nExpense = 0;
            
    } // while nWeek < 20

        if (nTotal >= 1000000)
        {
            printf("\tCurrent Bells: %d\n", nTotal);
            printf("\tCONGRATULATIONS! You have reached 1 million in %d weeks!\n", nWeek - 1);
        }
} // if yes
    else if (cAns == '0')
        printf("\tGoodbye\n");  // WRONG y or n, return message.

    

 
    return 0;
}

