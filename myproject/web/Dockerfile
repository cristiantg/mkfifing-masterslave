FROM node:15.0.1-alpine

LABEL maintainer="cristian.tejedorgarcia@ru.nl"

RUN apk add build-base

RUN apk update

WORKDIR /app

COPY package*.json ./
COPY tsconfig.json ./

RUN npm install

COPY . /app
RUN npm run build

EXPOSE 3000
CMD [ "npm", "start" ]
