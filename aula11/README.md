# Diary project :book:

## Compiling :package:

On root folder run: `make` or `make all`.

This will compile and link all your source files and will create the executables `diary` and `run_test` inside your root directory.

## Running :runner:

Besides the main program you have the option to run the tests too.

### Program

On the root folder, run:

```shell
./diary add
```

### Testing

On the root folder, run:

```shell
./run_test
```

## Usage 🗂️

You have the following options to use your diary:

`./diary add <message>` - Adds a new message into your diary. _Note: **message** argument is optional._<br><br>
`./diary search <term>` - Searches and lists all the messages that contains _term_. _Note: **term** argument is optional._<br><br>
`./diary list` - Lists all the messages of your diary.

## Cleaning up 🧽

If you want to remove all the compiled .o files, simply run:

```shell
make clean
```
