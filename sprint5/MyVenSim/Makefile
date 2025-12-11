.PHONY: TESTES BUILD_FUNC_TEST BUILD_UNIT_TEST BUILD_OBJ APP clean

TESTES: UNIT FUNC APP


# Build Object Files

BUILD_OBJ: bin/Flow.o bin/System.o bin/Model.o

bin/Flow.o: src/Flow.cpp
	g++ -c -Wextra src/Flow.cpp -o bin/Flow.o

bin/System.o: src/System.cpp
	g++ -c -Wextra src/System.cpp -o bin/System.o

bin/Model.o: src/Model.cpp
	g++ -c -Wextra src/Model.cpp -o bin/Model.o

# Unit Test make target

UNIT: BUILD_OBJ bin/unit_main.o bin/unit_system.o bin/unit_flow.o bin/unit_model.o
	g++ bin/unit_main.o bin/unit_system.o bin/unit_flow.o bin/unit_model.o bin/Flow.o bin/System.o bin/Model.o -o bin/exeunit -Wextra
	./bin/exeunit

bin/unit_main.o: test/unit/main.cpp
	g++ -c -Wextra -I include -I test/unit test/unit/main.cpp -o bin/unit_main.o

bin/unit_system.o: test/unit/unit_system.cpp
	g++ -c -Wextra -I include -I test/unit test/unit/unit_system.cpp -o bin/unit_system.o

bin/unit_flow.o: test/unit/unit_flow.cpp
	g++ -c -Wextra -I include -I test/unit test/unit/unit_flow.cpp -o bin/unit_flow.o

bin/unit_model.o: test/unit/unit_model.cpp
	g++ -c -Wextra -I include -I test/unit test/unit/unit_model.cpp -o bin/unit_model.o



# Functional Test make target

FUNC: bin/funcional_tests.o bin/func_main.o BUILD_OBJ
	g++ bin/funcional_tests.o bin/func_main.o bin/Flow.o bin/System.o bin/Model.o -o bin/exefunc -Wextra
	./bin/exefunc

bin/funcional_tests.o: test/funcional/funcional_tests.cpp
	g++ -c -Wextra test/funcional/funcional_tests.cpp -o bin/funcional_tests.o

bin/func_main.o: test/funcional/main.cpp
	g++ -c -Wextra test/funcional/main.cpp -o bin/func_main.o

APP: BUILD_OBJ
	g++ src/main.cpp bin/Flow.o bin/System.o bin/Model.o -o app -Wextra
	./app

clean:
	rm -f bin/*.o bin/exefunc bin/exeunit app
