.PHONY: TESTES BUILD_FUNC_TEST BUILD_UNIT_TEST APP

TESTES: BUILD_FUNC_TEST BUILD_UNIT_TEST APP

BUILD_FUNC_TEST:
	g++ test/funcional/funcional_tests.cpp test/funcional/main.cpp src/Flow.cpp src/System.cpp src/Model.cpp -o exefunc -Wextra
	./exefunc

BUILD_UNIT_TEST:
	g++ test/unit/main.cpp src/Flow.cpp src/System.cpp src/Model.cpp -o exeunit -Wextra
	./exeunit

APP:
	g++ src/main.cpp src/Flow.cpp src/System.cpp src/Model.cpp -o app -Wextra
	./app

clean:
	rm -f exefunc exeunit app
