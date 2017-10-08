TAG=stack
DEP1=main
DEP2=functions

DEPS= $(DEP2).o $(DEP1).o


$(TAG): $(DEPS)
	clang $(DEPS) -g -o $(TAG)
	
$(DEP1).o: $(DEP1).c
	clang -g -c $(DEP1).c
	
$(DEP2).o: $(DEP2).c
	clang -g -c $(DEP2).c
	
clean:
	rm -f $(DEPS) $(TAG)
