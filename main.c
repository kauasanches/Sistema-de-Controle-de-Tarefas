#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tarefa {
    char tituloDaTarefa[50];
    char descDaTarefa[150];
    int concluida;
    
};

// Função para adicionar tarefas
void adicionarTarefa(struct Tarefa tarefas[], int *totalTarefas) {
    
    printf("Digite o nome da tarefa:\n");
    scanf(" %[^\n]", tarefas[*totalTarefas].tituloDaTarefa); // Le ate o enter
    
    printf("Digite a descricao da tarefa:\n");
    scanf(" %[^\n]", tarefas[*totalTarefas].descDaTarefa); // Le ate o enter
    
    tarefas[*totalTarefas].concluida = 0; // ainda não concluída
    (*totalTarefas)++; // aumenta o contador
    
    printf("\nTarefa adicionada com sucesso!\n\n");
    
}

// Função para exibir todas as tarefas cadastradas
void visualizarTarefas(struct Tarefa tarefas[], int totalTarefas) {
    if (totalTarefas == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    printf("--- Lista de Tarefas ---\n\n");

    for (int i = 0; i < totalTarefas; i++) {
        if (tarefas[i].concluida) {
            printf("%d. [X] %s\n", i + 1, tarefas[i].tituloDaTarefa);
        } else {
            printf("%d. [ ] %s\n", i + 1, tarefas[i].tituloDaTarefa);
        }
        printf("    Descricao: %s\n\n", tarefas[i].descDaTarefa);
    }
}

// Função para exibir apenas as tarefas concluidas
void visualizarComFiltro(struct Tarefa tarefas[], int totalTarefas, int mostrarSomenteConcluidas) {
    int encontrou = 0;

    printf("--- Lista de Tarefas ---\n\n");

    for (int i = 0; i < totalTarefas; i++) {
        if (mostrarSomenteConcluidas && tarefas[i].concluida == 0) {
            continue; // pula se quiser só concluídas e essa não estiver concluída
        }

        encontrou = 1;

        if (tarefas[i].concluida) {
            printf("\033[1;32m%d. [X] %s\033[0m\n", i + 1, tarefas[i].tituloDaTarefa);
        } else {
            printf("\033[1;31m%d. [ ] %s\033[0m\n", i + 1, tarefas[i].tituloDaTarefa);
        }

        printf("    Descricao: %s\n\n", tarefas[i].descDaTarefa);
    }

    if (!encontrou) {
        printf("Nenhuma tarefa encontrada com esse filtro.\n");
    }
}

// Função para editar tarefas cadastradas
void editarTarefa(struct Tarefa tarefas[], int totalTarefas) {
    if (totalTarefas == 0) {
        printf("Nenhuma tarefa para editar.\n");
        return;
    }

    visualizarTarefas(tarefas, totalTarefas); // Rreutiliza a função

    int indice;
    printf("Digite o numero da tarefa que deseja editar:\n");
    scanf("%d", &indice);
    indice--; // ajusta para o índice do array (0 a n-1)

    if (indice < 0 || indice >= totalTarefas) {
        printf("Numero invalido!\n");
        return;
    }

    printf("Novo titulo da tarefa:\n");
    scanf(" %[^\n]", tarefas[indice].tituloDaTarefa);

    printf("Nova descricao da tarefa:\n");
    scanf(" %[^\n]", tarefas[indice].descDaTarefa);

    printf("A tarefa esta concluida? (1 = Sim, 0 = Nao):\n");
    scanf("%d", &tarefas[indice].concluida);

    printf("Tarefa editada com sucesso!\n\n");
}

// Função para excluir tarefas cadastradas
void excluirTarefa(struct Tarefa tarefas[], int *totalTarefas) {
    if (*totalTarefas == 0) {
        printf("Nenhuma tarefa para excluir.\n");
        return;
    }

    visualizarTarefas(tarefas, *totalTarefas); // Mostra as tarefas

    int indice;
    printf("Digite o numero da tarefa que deseja excluir:\n");
    scanf("%d", &indice);
    indice--; // ajustar para índice do array

    if (indice < 0 || indice >= *totalTarefas) {
        printf("Numero invalido!\n");
        return;
    }

    // Deslocar as tarefas acima da que será excluída
    for (int i = indice; i < *totalTarefas - 1; i++) {
        tarefas[i] = tarefas[i + 1];
    }

    (*totalTarefas)--; // Decrementa o contador
    printf("Tarefa excluida com sucesso!\n\n");
}

// Função para marcar tarefas como concluídas
void marcarTarefaComoConcluida(struct Tarefa tarefas[], int *totalTarefas) {
    if (*totalTarefas == 0) {
        printf("Nenhuma tarefa para marcar como concluida.\n");
        return;
    }

    visualizarTarefas(tarefas, *totalTarefas);

    int indice;
    printf("Digite o numero da tarefa que deseja marcar como concluida:\n");
    scanf("%d", &indice);
    indice--;  // Ajusta para índice do array

    if (indice < 0 || indice >= *totalTarefas) {
        printf("Numero invalido!\n");
        return;
    }

    if (tarefas[indice].concluida == 1) {
        printf("Essa tarefa ja esta marcada como concluída.\n");
    } else {
        tarefas[indice].concluida = 1;
        printf("Tarefa marcada como concluida com sucesso!\n");
    }
}

// Função para salvar tarefas cadastradas em .txt
void salvarTarefasEmArquivo(struct Tarefa tarefas[], int totalTarefas) {
    FILE *arquivo = fopen("tarefas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar!\n");
        return;
    }

    for (int i = 0; i < totalTarefas; i++) {
        fprintf(arquivo, "%d|%s|%s|%d\n",
                i + 1,
                tarefas[i].tituloDaTarefa,
                tarefas[i].descDaTarefa,
                tarefas[i].concluida);
    }

    fclose(arquivo);
    printf("Tarefas salvas com sucesso!\n");
}

// Função para carregar tarefas cadastradas em .txt
void carregarTarefasDoArquivo(struct Tarefa tarefas[], int *totalTarefas) {
    FILE *arquivo = fopen("tarefas.txt", "r");
    if (arquivo == NULL) {
        // Não tem arquivo ainda, tudo certo
        return;
    }

    *totalTarefas = 0;
    while (fscanf(arquivo, "%*d|%49[^|]|%149[^|]|%d\n",
                  tarefas[*totalTarefas].tituloDaTarefa,
                  tarefas[*totalTarefas].descDaTarefa,
                  &tarefas[*totalTarefas].concluida) == 3) {
        (*totalTarefas)++;
    }

    fclose(arquivo);
}

int main() {
    struct Tarefa tarefas[100];
    int totalTarefas = 0;
    int numeroDigitado;
    
    carregarTarefasDoArquivo(tarefas, &totalTarefas);

    do {
        printf("\033[1;31mTaskMan - Sistema de Controle de Tarefas\033[0m\n\n");
        printf("Bem-vindo(a) ao TaskMan o melhor sistema de controle de tarefas da atualidade.\n\n");

        printf("Digite (1) para adicionar uma tarefa\n");
        printf("Digite (2) para editar uma tarefa\n");
        printf("Digite (3) para visualizar as tarefas\n");
        printf("Digite (4) para visualizar apenas as tarefas concluidas\n");
        printf("Digite (5) para excluir uma tarefa\n");
        printf("Digite (6) para marcar tarefa como concluida\n\n");
        printf("Digite (0) para sair\n");

        scanf("%d", &numeroDigitado);
        
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        if (numeroDigitado == 1) {
            
            adicionarTarefa(tarefas, &totalTarefas);
            salvarTarefasEmArquivo(tarefas, totalTarefas);
            
        } else if (numeroDigitado == 2) {
            
            editarTarefa(tarefas, totalTarefas);
            salvarTarefasEmArquivo(tarefas, totalTarefas);
            
        } else if (numeroDigitado == 3) {
            
            visualizarComFiltro(tarefas, totalTarefas, 0); // 0 = todas
            
        } else if (numeroDigitado == 4) {
            
            visualizarComFiltro(tarefas, totalTarefas, 1); // 1 = só concluídas
            
        } else if (numeroDigitado == 5) {
            
            excluirTarefa(tarefas, &totalTarefas);
            salvarTarefasEmArquivo(tarefas, totalTarefas);
            
        } else if (numeroDigitado == 6) {
            marcarTarefaComoConcluida(tarefas, &totalTarefas);
            salvarTarefasEmArquivo(tarefas, totalTarefas);
        } else if (numeroDigitado == 0) {
            
            printf("Saindo do TaskMan. Até logo!\n");
            
        } else {
            
            printf("Numero invalido. Por favor, digite um numero valido.\n");
            
        }

        printf("\n");
    } while (numeroDigitado != 0);

    return 0;
}
