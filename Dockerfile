# Usar una imagen base con herramientas para C
FROM gcc:latest

# Crear un directorio para tu proyecto
WORKDIR /cursus42

# Instalar herramientas adicionales si son necesarias
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
    pipx

# Instalar norminette
RUN pipx install norminette
RUN pipx ensurepath

# Instalar paco
RUN bash -c "$(curl -fsSL https://raw.github.com/xicodomingues/francinette/master/bin/install.sh)"

# Crear y configurar directorios para SSH
RUN mkdir /var/run/sshd

# Cambiar contraseña del usuario root (puedes usar una personalizada)
RUN echo 'root:rootpassword' | chpasswd

# Permitir acceso root por SSH
RUN sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config

# Exponer el puerto 22 para SSH
EXPOSE 22


COPY ./ /cursus42

# Definir el comando por defecto (puedes cambiarlo)
CMD ["/usr/sbin/sshd", "-D"]