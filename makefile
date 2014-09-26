CC=ccsc
CFLAGS=+FH +LN -T -A -M -Z +DF +Y=9 +STDOUT
HFLAGS=+FB +LN -T -A -M -Z +DF +Y=9 +STDOUT

all: shell

shell: shell.c
	$(CC) $(CFLAGS) shell.c

clean:
	rm *.cof *.err *.esym *.hex *.lst *.pjt *.STA *.sym *.tre *.MCP *.PWI *.DBK