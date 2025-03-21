FROM ubuntu:latest

# Instala dependências necessárias
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    unzip \
    pkg-config \
    libopencv-dev \
    && rm -rf /var/lib/apt/lists/*

# Define o diretório de trabalho
WORKDIR /app

# Copia o código fonte para o container
COPY . .

# Compila o código (supondo que haja um CMakeLists.txt na pasta /app)
RUN mkdir -p build && cd build \
    && cmake .. \
    && make

# Define o comando padrão para rodar o binário gerado
CMD ["./build/seu_programa"]
