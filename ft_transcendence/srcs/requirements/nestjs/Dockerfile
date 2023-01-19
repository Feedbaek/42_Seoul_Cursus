# ubuntu 20.04 Version을 기반으로 한다.
FROM minskim2/ubuntu-nestjs

# 기본적인 패키지 설치
#RUN apk update && apk upgrade && apk add sudo curl git dumb-init

# node, npm, nestjs/cli 설치
#RUN	sudo apt-get install -y npm
#RUN sudo npm cache clean --force && sudo npm install -g n
#RUN	sudo n stable && sudo npm install -g npm && npm install -g @nestjs/cli
#RUN npm install -g @nestjs/cli

# start_nestjs.sh 세팅
#COPY conf/start_nestjs.sh /home
#RUN chmod 755 /home/start_nestjs.sh

#USER maria
#WORKDIR /home/maria

# DBMS포트는 3306을 사용한다.
#EXPOSE 3306
ENTRYPOINT [ "bash" ]
#ENTRYPOINT ["/usr/bin/dumb-init", "--", "/home/start_nestjs.sh"]
