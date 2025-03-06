# Usar una imagen base con herramientas para C
FROM gcc:latest

# Crear un directorio para tu proyecto
WORKDIR /cursus42

# Instalar herramientas necesarias
RUN apt-get update && apt-get install -y \
    git \
    make \
    cmake \
    openssh-server \
    python3 \
    python3-pip \
    python3-dev \
    build-essential \
    python3.11-venv \
    python3-setuptools \
    pipx \
    clang \
    libxext-dev \
    libxrandr-dev \
    libx11-dev \
    libbsd-dev \
    libssl-dev \
    x11-apps \
    curl \
    && rm -rf /var/lib/apt/lists/*

# Instalar norminette
RUN pipx install norminette && pipx ensurepath

# Instalar paco (Francinette para la corrección de proyectos en 42)
RUN bash -c "$(curl -fsSL https://raw.github.com/xicodomingues/francinette/master/bin/install.sh)"

# Clonar e instalar MiniLibX
RUN git clone https://github.com/42Paris/minilibx-linux.git /cursus42/minilibx-linux \
    && cd /cursus42/minilibx-linux \
    && make \
    && cp libmlx.a /usr/local/lib/ \
    && cp mlx.h /usr/local/include/

# Configurar SSH
RUN mkdir /var/run/sshd \
    && echo 'root:rootpassword' | chpasswd \
    && sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config

# Exponer el puerto SSH
EXPOSE 22

# Copiar los archivos de tu proyecto al contenedor
COPY ./ /cursus42

# Comando por defecto
CMD ["/usr/sbin/sshd", "-D"]
