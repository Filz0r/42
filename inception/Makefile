# Define variables
COMPOSE_FILE := docker-compose.yml
SRC_DIR := src
ENV_FILE := .env
VOLUME_DIR = ./volumes/mariadb/* ./volumes/wordpress/*

# List of files to monitor for changes
FILES := $(shell find $(SRC_DIR) -type f) $(ENV_FILE) $(COMPOSE_FILE)


up: build
	docker compose up

down:
	docker compose down

build:
	docker compose build

clean: down
	sudo rm -rf $(VOLUME_DIR)
	docker image prune -a -f
	docker container prune -f
	docker builder prune -a -f
	docker volume prune -a -f
	docker network prune -f
	docker pull alpine:3.18.6

re: clean up


.PHONY: up down build clean re 
