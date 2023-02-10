#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv){
    FILE* fp;
    fp = popen("ip -json route get 8.8.8.8 | jq -r '.[].prefsrc'", "r");
    char* ip = malloc(30);
    fgets(ip, 20, fp);
    char* command = malloc(150);
    sprintf(command, "pwsh.exe -Command \"Start-Process netsh -ArgumentList 'interface portproxy set v4tov4 listenport=%s listenaddress=0.0.0.0 connectport=%s connectaddress=%s' -Verb runas\"", argv[1], argv[1], ip);
    system(command);
    free(command);
    free(ip);
    pclose(fp);
}