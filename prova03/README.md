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
`./diary list <format>` - Lists all the messages of your diary based on the format. _Note: **format** argument is optional. If not present, the format will be read from `diary.config` file_<br><br>
`./diary interactive` - Activates the interactive mode which you can list messages or add new messages.

### Configuration file

The `diary.config` file allows you to configure the name and path of your diary file and the default format of the messages listing.

### Formatting the listing

You can use three formatting rules, which are:

- %d - Shows the message date
- %t - Shows the message time
- %m - Shows the message content

For example, if you pass the following format: `[%d %t] %m`, you will get as output:
`[01/07/2020 09:35:16] Message content`

## Cleaning up 🧽

If you want to remove all the generated files, simply run:

```shell
make clean
```
