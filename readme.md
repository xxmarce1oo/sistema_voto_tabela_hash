# Exercício: Sistema de Votação com Tabela Hash - Professor Lucas

## Utilize Python ou JS ou JAVA

## Regras
1. Cada eleitor tem um **ID único** (ex.: CPF ou número de registro).
2. Um eleitor só pode votar **uma única vez**.
3. O sistema deve permitir que os votos sejam contados para diferentes candidatos.
4. Caso um eleitor tente votar mais de uma vez, o sistema deve rejeitar o voto.

## Requisitos
1. Use uma **tabela hash** para armazenar os IDs dos eleitores que já votaram.
2. Armazene os votos de forma que seja possível contar quantos cada candidato recebeu.
3. Crie uma função para exibir o resultado da eleição.


# Exemplo esperado

## Eleitor votando pela primeira vez
**Entrada:**  
`vote("123", "Alice")`  
**Saída:**  
`"Voto registrado para Alice!"`

---

## Eleitor tentando votar novamente
**Entrada:**  
`vote("123", "Bob")`  
**Saída:**  
`"Erro: Eleitor já votou."`

---

## Resultado da eleição
**Entrada:**  
`show_results()`  
**Saída:**  

# Orientações para Entrega

## Passos para entrega do exercício

1. **Crie um repositório no GitHub**

2. **Envie o link do repositório no TEAMS**
