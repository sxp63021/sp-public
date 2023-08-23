# syntax=docker/dockerfile:1

FROM ubuntu:latest
RUN apt-get update && apt-get install -y ksh && apt-get clean
#USER root
#RUN apt-get update && apt-get install procps -y
RUN apt-get update && apt-get install -y procps && apt-get clean
#USER nobody

WORKDIR /app
COPY br.config /app/.
COPY br.ksh /app/.
RUN mkdir /app/test1
RUN mkdir /app/test2
COPY test1 /app/test1
COPY test2 /app/test2
#RUN yarn install --production
#CMD ["/bin/ksh", "/app/br.ksh"]
