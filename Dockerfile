FROM debian:latest

# Install cpp build tools
RUN apt-get -y update && apt-get install -y \
    gcc\
    g++\ 
    cmake\
    libncurses-dev
    

ADD ../kcurses /kcurses/

