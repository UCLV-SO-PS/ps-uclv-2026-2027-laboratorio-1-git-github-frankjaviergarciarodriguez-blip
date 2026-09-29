 #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

void mostrar_info_sistema() {
    printf("=== Monitor de Procesos del Sistema ===\n");
    
    // Obtener información del usuario
    struct passwd *pw = getpwuid(getuid());
    if (pw) {
        printf("Usuario: %s\n", pw->pw_name);
    }
    
    printf("PID del proceso: %d\n", getpid());
    printf("PID del proceso padre: %d\n", getppid());
}

void mostrar_uso_memoria() {
    printf("--- Información de Memoria ---\n");
    printf("Funcionalidad de memoria por implementar\n");
}

int main() {
    mostrar_info_sistema();
    mostrar_uso_memoria();
    return 0;
}


