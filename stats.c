#include "stats.h"
#include <math.h>

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    int sum = 0;
    if(setlength == 0)
    {
        return NAN;
    }
    else
    {
        s.min = numberset[0];
        s.max = numberset[0];
        /*Update Min and max Value*/
        for(int i = 0; i<setlength;i++)
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
        
        s.average = (s.average/setlength)
    }
    
    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
