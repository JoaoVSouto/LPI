# Market project :convenience_store:

## Compiling :package:

On root folder run: `make` or `make all`.

This will compile and link all your source files and will create the executable `supermercado` inside your root directory.

## Running :runner:

On the root folder, run:

```shell

./supermercado

```

## Usage 🗂️

This program works with a `estoque.csv` file which controls all the stock and product data. _Ps. You have to have this file in your project's root folder, otherwise the program will not run._

There are two interactive menus:

1. The first one is used to enter the market with a new customer or simply left the store (quit the program).

```
┌─────────────────────────────────────┐
│   Seja bem-vindo(a) ao mercado!     │
│                                     │
│   Selecione o que deseja:           │
│                                     │
│   1. Entrar como um novo cliente    │
│   2. Sair                           │
└─────────────────────────────────────┘
```

2. The second one is used to interact with the market and it gives you the following options:
   1. Increase the customer's balance, in which you can enter the amount of money you want.
   2. Show available products. This will consult the products list and will return only the ones which have at least one in stock.
   3. Buy a product. You will be prompted to enter the name of the product you want to buy and if all the checks (product availability and necessary amount of money) pass, the product will be put on your products bag.
   4. List customer's products bag. Simply lists all the products you have already bought.
   5. List the market's cash register. Lists all the products the market have sold for all the customers in current program execution.

```
┌─────────────────────────────────────┐
│   Olá Cliente!                      │
│                                     │
│   Seu saldo é de R$ 100.00          │
│                                     │
│   Selecione o que deseja:           │
│                                     │
│   1. Adicionar saldo                │
│   2. Produtos disponíveis           │
│   3. Comprar produto                │
│   4. Minha sacola                   │
│   5. Ver caixa do mercado           │
│   6. Sair                           │
└─────────────────────────────────────┘
```

### Generated files

By the end of the program's execution you will notice that at least two new files have been created:

1. The first one will be the `caixa.csv` file which contains the data of the market's cash register, that is, of all the products that were sold on the last program execution and the total profit.
2. The other file you might notice will be the `cliente_1.txt` which holds the data of all the products that the first customer bought. If you buy any product with more than one customer, this file will be created for each one in the following format `cliente_x.txt` where _x_ is the number of the customer starting with 1 and increased by one.

## Cleaning up 🧽

If you want to remove all the generated files, simply run:

```shell

make clean

```
