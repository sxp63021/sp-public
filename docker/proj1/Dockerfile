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
COPY test1 /app/.
COPY test2 /app/.
#RUN yarn install --production
CMD ["/bin/ksh", "/app/br.ksh"]
