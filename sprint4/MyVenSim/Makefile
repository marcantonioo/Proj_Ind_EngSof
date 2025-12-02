.PHONY: TESTES BUILD_FUNC_TEST BUILD_UNIT_TEST BUILD_OBJ APP clean

TESTES: BUILD_FUNC_TEST BUILD_UNIT_TEST APP


BUILD_OBJ: bin/Flow.o bin/System.o bin/Model.o

bin/Flow.o: src/Flow.cpp
	g++ -c -Wextra src/Flow.cpp -o bin/Flow.o

bin/System.o: src/System.cpp
	g++ -c -Wextra src/System.cpp -o bin/System.o

bin/Model.o: src/Model.cpp
	g++ -c -Wextra src/Model.cpp -o bin/Model.o


BUILD_FUNC_TEST: bin/funcional_tests.o bin/func_main.o BUILD_OBJ
	g++ bin/funcional_tests.o bin/func_main.o bin/Flow.o bin/System.o bin/Model.o -o bin/exefunc -Wextra
	./bin/exefunc

bin/funcional_tests.o: test/funcional/funcional_tests.cpp
	g++ -c -Wextra test/funcional/funcional_tests.cpp -o bin/funcional_tests.o

bin/func_main.o: test/funcional/main.cpp
	g++ -c -Wextra test/funcional/main.cpp -o bin/func_main.o

BUILD_UNIT_TEST: bin/unit_main.o BUILD_OBJ
	g++ bin/unit_main.o bin/Flow.o bin/System.o bin/Model.o -o bin/exeunit -Wextra
	./bin/exeunit

bin/unit_main.o: test/unit/main.cpp
	g++ -c -Wextra test/unit/main.cpp -o bin/unit_main.o


APP: BUILD_OBJ
	g++ src/main.cpp bin/Flow.o bin/System.o bin/Model.o -o app -Wextra
	./app

clean:
	rm -f bin/*.o bin/exefunc bin/exeunit app
