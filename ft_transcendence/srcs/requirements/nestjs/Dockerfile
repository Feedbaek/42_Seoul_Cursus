# ubuntu 20.04 Version을 기반으로 한다.
FROM minskim2/ubuntu-nestjs:1.0

# 기본적인 패키지 업데이트
RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y dumb-init

# start_nestjs.sh 세팅
COPY conf/start_nestjs.sh /home
RUN chmod 755 /home/start_nestjs.sh

ENTRYPOINT ["/usr/bin/dumb-init", "--", "/home/start_nestjs.sh"]
