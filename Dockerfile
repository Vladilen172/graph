FROM ubuntu:20.04

RUN apt-get update && apt-get install -y \
    g++ \
    libgtest-dev \
    make \
    curl \
    doxygen \
    vim 

WORKDIR /app

COPY ./ /app/


ENTRYPOINT [ "make", "run"]