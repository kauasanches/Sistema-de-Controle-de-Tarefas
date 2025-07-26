# TaskMan (C) – Gerenciador de Tarefas no Terminal 📋💻

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

---

## ▶️ Como compilar e rodar

### 1. Compile o código:

`gcc -o taskman main.c`

### 2. Execute o programa:

`./taskman`

## 🧠 Observações

- O arquivo `tarefas.txt` armazena as tarefas no formato:
`1|Comprar pão|Ir à padaria|0
2|Estudar C|Fazer exercícios|1`
