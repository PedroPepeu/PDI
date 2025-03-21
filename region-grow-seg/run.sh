CAMINHO="."

g++ $CAMINHO/main.cpp -o $CAMINHO/out.o $(pkg-config --cflags --libs opencv4)

if [ $? -eq 0 ]; then
	echo "Compilation successful. Running program..."
	./out.o
else
	echo "Compilation failed. Please check for errors."
fi
