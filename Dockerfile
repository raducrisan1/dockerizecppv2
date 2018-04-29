FROM frolvlad/alpine-glibc
RUN apk update && \
    apk add libstdc++

COPY cmake-build-release/bin/dockerizecppv2 /app/
RUN chmod +x /app/dockerizecppv2
ENTRYPOINT /app/dockerizecppv2