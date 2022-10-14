#include "stats.h"
#include "alerts.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
/*
* @brief    To calculate the Average, min and max values of the given array.
* @param    numberset : float type array pointer.
            setlength : array length.
* @return   Stats : result to be stored and return in structure type.
*/
struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s = {0.0,0.0,0.0};
    
    if(setlength == 0)
    {
        s.average = NAN;
        s.min = NAN;
        s.max = NAN;
    }
    else
    {
        s.min = numberset[0];
        s.max = numberset[0];
        /*Update Min and max Value*/
        for(int i = 0; i < setlength; i++)
        {
            /*For average*/
            s.average += numberset[i];
            /*For minimum */
            if(s.min > numberset[i])
            {
                s.min = numberset[i];
            }
            /*For Maximum */
            if(s.max < numberset[i])
            {
                s.max = numberset[i];
            }
        }
        
        s.average = (s.average/setlength);
    }
    
    return s;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if(computedStats.max > maxThreshold)
    {
        (*alerters[0])();
        (*alerters[1])();
    }
}
