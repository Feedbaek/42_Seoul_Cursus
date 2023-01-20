#!/bin/sh

# 프로젝트 생성
if [ ! -d /ft_transcendence/src ]; then
	# git repo 변경 가능
	git clone https://github.com/Feedbaek/ft_transcendence.git
fi
cd /ft_transcendence

# nestjs 설치
npm install

# 서버 실행
npm run start:dev
