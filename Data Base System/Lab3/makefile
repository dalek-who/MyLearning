object = SQLparser.o SQLexec.o SQLjoin.o SQLgroupby.o
rpn:	$(object)
	gcc -o ucasdb $(object)
%.o:	%.c
	gcc -o $@ -c $<
clean:
	rm *.o
