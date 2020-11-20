/******************************************************************************

    Connor Clark, Nickolas Jackson
    ELET-1102-001
    11/19/2020
    Mini Project 3
    
    This program calculates the toll amount based on a weekday or weekend and the 
    time of day. 
    
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main() 
{
    int dayWeek;        //inializing dayweek
    float timeHourA;    //inializing hours
    int timeHourB;
    float timeMinutesA; //inializing minutes in decimal
    int timeMinutesB;
    char *am_pm;
    float time;         //inializing time of day in 24 hr decimal
    float toll;         //inializing toll fee
    float total;        //inializing total cost
    float exitFee;      //inializing fee based on exits passed
    float quickPass;    //inializing quickpass Balance
    float totalAccount; ///inializing total account balane
    
    printf("Enter 0 for weekday or 1 for weekend/holiday: ");    //User specifiying if Weekday or weekend
    scanf("%d", &dayWeek);
    
    printf("\nEnter the hour of time in 24 hour format: ");      // User specify current hour of the day
    scanf("%f", &timeHourA);

    printf("\nEnter the minutes of time in format: ");           // User specify minutes
    scanf("%f", &timeMinutesA);

    printf("\nEnter the amount of money in your Carolina Quick Pass account: ");
    scanf("%f", &quickPass);

    time = timeHourA + (timeMinutesA / 60);                      // Calculates time of day in decimal 
    exitFee = 25 * 0.10;

    if (dayWeek == 1)                                            // decieds toll cost based on time entered for weekend
    {
        if (time < 8)
        {
            toll = 1;
        }

        if (time >= 8 && time < 12)
        {
            toll = 2.05;
        }

        if (time >= 12 && time < 16)
        {
            toll = 2.45;
        }
        
        if (time >= 16 && time < 19)
        {
            toll = 2.60;
        }

        if (time >= 19 && time < 22)
        {
            toll = 2.05;
        }

        if (time >= 22 && time < 24)
        {
            toll = 0.55;
        }

        if (time >= 24)
        {
            printf("The time you entered does not make any logical sense whatsoever");
        }
    }

    else if (dayWeek == 0)                                     // decieds toll cost based on time entered for weekday
    {
        if (time < 6)
        {
            toll = 1.55;
        }
        
        if (time >= 6 && time < 10)
        {
            toll = 2.65;
        }
        
        if (time >= 10 && time < 18)
        {
            toll = 2.35;
        }
        
        if (time >= 18 && time < 24)
        {
            toll = 1.25;
        }

        if (time >= 24)
        {
            printf("\nThe time you entered does not make any logical sense whatsoever");
        }
    }

    total = toll + exitFee;
    totalAccount = quickPass - total;
    
    if (timeHourA > 0 && timeHourA < 12)
    {
        timeHourA = timeHourA;
        am_pm = "am";
    }

    else if (timeHourA >= 13)
    {
        timeHourA = timeHourA - 12;
        am_pm = "pm";
    }

    else if (timeHourA = 12)
    {
        timeHourA = timeHourA;
        am_pm = "pm";
    }


    timeHourB = timeHourA;
    timeMinutesB = timeMinutesA;

    printf("\nHere is your receipt:\n");

    if (timeMinutesB >= 10)
    {
        printf("\n|   Time   | Toll Fee | Exit Fee | Total Fee | Quickpass Balance |");
        printf("\n_____________________________________________________________________");
        printf("\n| %d:%d %s |   %.2f   |   %.2f   |    %.2f   |        %.2f       |", timeHourB, timeMinutesB, am_pm, toll, exitFee, total, totalAccount);
    }

    else if (timeMinutesB < 10)
    {
        printf("\n|   Time   | Toll Fee | Exit Fee | Total Fee | Quickpass Balance |");
        printf("\n_____________________________________________________________________");
        printf("\n| %d:0%d %s |   %.2f   |   %.2f   |    %.2f   |        %.2f       |", timeHourB, timeMinutesB, am_pm, toll, exitFee, total, totalAccount);
    }


    return(0);

}
