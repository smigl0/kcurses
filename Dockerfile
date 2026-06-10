FROM alpine:latest

# Install cpp build tools
RUN apk update && apk add gcc g++ cmake make ncurses-dev libncursesw

ADD ../kcurses /kcurses/

