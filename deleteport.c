#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv){
    char* command = malloc(150);
    sprintf(command, "pwsh.exe -Command \"Start-Process netsh -ArgumentList 'interface portproxy delete v4tov4 listenport=%s listenaddress=0.0.0.0' -Verb runas\"", argv[1]);
    system(command);
    free(command);
}