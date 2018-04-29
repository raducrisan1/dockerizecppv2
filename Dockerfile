FROM ubuntu:18.04
RUN apt-get update
EXPOSE 5200
COPY cmake-build-minsizerel/bin/dockerizecppv2 /app/
RUN chmod +x /app/dockerizecppv2
ENTRYPOINT /app/dockerizecppv2