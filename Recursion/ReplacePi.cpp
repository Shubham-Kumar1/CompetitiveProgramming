// Change in the given string itself. So no need to return or print anything
#include <cstring>
void replacePi(char input[]) {
    
    int n = strlen(input);
    if(n < 2) return;  // pi word is not possible
    
    if(input[0]=='p' && input[1]=='i')
    {
        for(int i=n-1;i>=2;--i) input[i+2] = input[i];

        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
        return replacePi(input+2);
    }else{
        return replacePi(input+1);
    }
}
