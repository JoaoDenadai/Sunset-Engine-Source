@echo Compiling the program...
g++ -c -I. Sunset_app.cpp 
@echo Linking additional libraries...
g++ -o Sunset_exec.exe Sunset_app.o -L. -lglfw3 -lopengl32 -lgdi32
@echo Running the program...
.\Sunset_exec.exe