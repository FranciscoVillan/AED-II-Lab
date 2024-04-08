#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int result=0;
   
    for (int i = 0; i < FIXSTRING_MAX; i++)
    {
        if (s[i] == '\0')
        {
            return result;
        }
        else
        result++;
        continue;
        
    }
    
    return result;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    for (int i = 0; i < FIXSTRING_MAX; i++)
    {
        if (s1[i]!=s2[i])
        {
            return false;
        }
        else
        continue;
        
    }
    return true;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {

    for (int i = 0; i < FIXSTRING_MAX; i++)
    {
      if (s1[i] != '\0'&&s2[i] != '\0')
      {
        if (s1[i]<=s2[i])
          {
              return true;
          }
          else 
             return false;
     
      }
      else
      break;
    }
    return true;
    
}
