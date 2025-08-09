# TaskMan – Sistema de Controle de Tarefas 📋💻

**Kauã Rodrigues Sanches - N°21 - 1°D**

**TaskMan** é um sistema simples e funcional de gerenciamento de tarefas feito em linguagem C, com menu interativo via terminal.

---

## ❓ Problema

Muitas vezes precisamos de um controle de tarefas local, sem depender de aplicativos pesados, internet ou interfaces complexas. Algo leve, direto e funcional.

---

## 💡 Solução

**TaskMan** oferece:
- Adição, edição, exclusão e visualização de tarefas
- Marcação de tarefas como concluídas
- Armazenamento persistente em arquivo `.txt`
- Menu intuitivo no terminal
- Código em C puro, fácil de compilar e entender

---

## ⚙️ Funcionalidades

- 📌 Adicionar novas tarefas
- ✏️ Editar título e descrição
- ✅ Marcar como concluída
- 🗑️ Excluir tarefas
- 🔍 Filtrar tarefas concluídas
- 💾 Gravar e carregar tarefas em `tarefas.txt`
- 👉 Foi trocada a função de prazo pela função de conclusão

---

## ▶️ Como compilar e rodar

### 1. Compile o código:

`gcc -o taskman main.c`

### 2. Execute o programa:

`./taskman`

---

## 🧠 Observações

- O arquivo `tarefas.txt` armazena as tarefas no formato:

Número da tarefa | Título da tarefa | Descrição da tarefa | 0 ou 1, sendo 1 para concluída e 0 para pendente

1|Comprar pão|Ir à padaria|0 <br>
2|Estudar C|Fazer exercícios|1

---



<img width="926" height="428" alt="screenshot" src="https://github.com/user-attachments/assets/c70a7a9e-3f71-4d3d-97fc-a04030b3f35a" />

<img width="512" height="178" alt="pasta" src="https://github.com/user-attachments/assets/859ffb29-b239-4367-bb99-f629d2eb725f" />
