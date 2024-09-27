# Variabili principali
JAVAC = javac
JAVA = java
JFLAGS = -g
CLASSPATH = . # Solo il classpath base senza JAR
BIN = out/production/laboratorio-algoritmi-2023-2024
SRC = priorityQueue/*.java graph/*.java Prim.java
EXCLUDE_TEST = test/*.java
MAIN = priorityQueue.Main_ex3
CSV_FILE = data/italian_dist_graph.csv

# Compila solo i file sorgente dell'applicazione
all:
	@echo "Compiling source files..."
	$(JAVAC) $(JFLAGS) -cp $(CLASSPATH) -d $(BIN) $(SRC)

# Esegui il programma principale
run: all
	@echo "Running main program..."
	$(JAVA) -cp $(BIN) Prim $(CSV_FILE)

# Esegui i test (opzionale, se hai test)
test: all
	@echo "Running tests..."
	$(JAVA) -cp $(BIN) org.junit.runner.JUnitCore $(TEST)

# Pulisci i file compilati
clean:
	@echo "Cleaning up compiled files..."
	@if exist "$(BIN)" del /q "$(BIN)\*.class"
	@if exist "$(BIN)\priorityQueue" del /q "$(BIN)\priorityQueue\*.class"
	@if exist "$(BIN)\graph" del /q "$(BIN)\graph\*.class"
	@if exist "$(BIN)" echo "Directory $(BIN) cleaned."