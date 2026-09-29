#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/sysinfo.h>

void mostrar_info_sistema() {
   printf("=== Monitor de Procesos del Sistema ===\n");
printf("Versión: 1.1 - Estable\n");


    
    struct passwd *pw = getpwuid(getuid());
    if (pw) {
        printf("Usuario: %s\n", pw->pw_name);
    }
    
    printf("PID del proceso: %d\n", getpid());
    printf("PID del proceso padre: %d\n", getppid());
}

void mostrar_uso_memoria() {
    printf("--- Información de Memoria ---\n");
    
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        printf("Memoria total: %lu MB\n", info.totalram / 1024 / 1024);
        printf("Memoria libre: %lu MB\n", info.freeram / 1024 / 1024);
        printf("Memoria utilizada: %lu MB\n", 
               (info.totalram - info.freeram) / 1024 / 1024);
    } else {
        printf("Error al obtener información de memoria\n");
    }
}

int main() {
    mostrar_info_sistema();
    mostrar_uso_memoria();
    return 0;
}



