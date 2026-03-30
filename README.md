# Lista-1---Joana-Fontes-e-Elainne-Rohs---Estrutura-de-Dados

## Descrição do Projeto
Implementação de um sistema simples para gerenciar a alocação de disciplinas em salas de aula durante uma semana.

Um usuário solicita a reserva de uma sala para ministrar uma disciplina em um determinado dia da semana e intervalo contínuo de tempo, com determinada capacidade de alunos. O sistema verifica automaticamente se existe alguma sala disponível naquele período.

Caso exista alguma sala disponível que atenda às condições da solicitação, a reserva é realizada. Caso contrário, o sistema informa que não há salas disponíveis naquele horário.

### Verificações básicas de erro:
* Se os números dos horários de início e final da reserva estiverem fora do horário de funcionamento do sistema, será lançado erro.
* Também, se o horário de saída for cronologicamente antes ou simultâneo ao horário de entrada. 

## Instruções de compilação

```
g++ main.cpp ReservationSystem.cpp ReservationRequest.cpp -o reservation_system
```

## Instruções de execução
* Para realizar uma reserva, o usuário deve informar a matéria ministrada, escolher o dia da semana da reserva, os horários de entrada e saída da sala e a capacidade máxima de alunos requerida.
* O nome da disciplina é único dentro do sistema. Não há possibilidade de cadastro duplicado.
* O horário de funcionamento do sistema é de 7h às 21h. Os horários informados devem ser inteiros.
* Se a reserva for realizada, ou seja, existir sala que atenda aos requisitos terá como saída no console: ```reserva bem sucedida! ```
* Caso contrário: ```essa reserva não é possível. Tente outra```

## Organização interna dos dados
Para armazenar as salas e as reservas, optamos por arrays dinâmicos. O ReservationSystem guarda um array de objetos Room, e cada sala guarda seu próprio array de objetos Reservation.
Escolhemos o array dinâmico porque ele permite aumentar de tamanho durante a execução do programa — quando o array fica cheio, dobramos sua capacidade e copiamos os dados — e exige menos memória do que alocar um array fixo grande desde o início.
### Classe Room
Classe criada para reepresentar uma sala de aula e controlar as reservas.
### Classe Reservation
Classe que representa uma reserva confirmada no sistema.
### Verificações de erro
No estudo de POO, é estabelecido como boa prática implementar as validações em setters, que deveriam ser declarados no construtor. No entanto, para esta modelagem, a criação de setters não é uma boa ideia, uma vez que não de deveria ser permitida a modificação de atributos da ```ReservationRquest```, fixos desde seu instanciamento, a fim de evitar conflitos de reservas.
Dessa forma, as validações foram realizadas dentro da função ```reserve``` de ```ReservationSystem```.